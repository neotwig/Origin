#include "IRremoteHelper.h"
#include <IRremote.h>  // Infrared Remote

IRremoteHelper::IRremoteHelper()
{
}

IRremoteHelper::~IRremoteHelper()
{
}

void IRremoteHelper::Init()
{
  // setup IR remote receiver
  pinMode(IR_RECV_DATA, INPUT);
  pinMode(IR_RECV_POWER, OUTPUT); // setup power pin for the IR receiver
  digitalWrite(IR_RECV_POWER, HIGH); // turn IR receiver on
  IrReceiver.begin(IR_RECV_DATA, DISABLE_LED_FEEDBACK); // Start the receiver
}

unsigned long IRremoteHelper::receiveIRcode()
{
  unsigned long IRcode = 0;
  if (IrReceiver.decode()) {
    IRcode = IrReceiver.decodedIRData.decodedRawData;
    //dbSerialPrintln("--------------------------------");
    //dbSerialPrintln(IRcode);
    //dbSerialPrintln(IrReceiver.decodedIRData.decodedRawData);
    //dbSerialPrintln(IrReceiver.decodedIRData.address);
    //dbSerialPrintln(IrReceiver.decodedIRData.command);
    //dbSerialPrintln("--------------------------------");
    IrReceiver.resume(); // Receive the next value
  }
  return IRcode;
}

int IRremoteHelper::mapIRcodeToFunction(unsigned long IRcode)
{
  if (IRcode == 0) {
	return 0;
  } else if (IRcode == 0xFFFFFFFF) { // REPEAT
	return 0;
  } else if (IRcode == IRup) {
	return IR_UP;
  } else if (IRcode == IRdown) {
	return IR_DOWN;
  } if (IRcode == IRpower) {
	return IR_POWER;
  } else if (IRcode == IRprevious) {
	return IR_PREVIOUS;
  } else if (IRcode == IRnext) {
	return IR_NEXT;
  } else { // We didn't match any of the navigation or power buttons, so now check direct input jump buttons
	for (int i = 0; i < NUM_PORTS; i++) {
	  if (IRcode == IRinput[i]) {
		// input is 1 based, but IR code is 0 based
		return (i+1);
	  }
	}
  }
  return 0; // code didn't match any of our defined codes
}

String IRremoteHelper::getIRcode(int whichFunction, bool insertPipe)
{
  if (whichFunction == IR_UP) {
    return IRtoString(IRup, insertPipe);
  } else if (whichFunction == IR_DOWN) {
    return IRtoString(IRdown, insertPipe);
  } else if (whichFunction == IR_POWER) {
    return IRtoString(IRpower, insertPipe);
  } else if (whichFunction == IR_PREVIOUS) {
    return IRtoString(IRprevious, insertPipe);
  } else if (whichFunction == IR_NEXT) {
    return IRtoString(IRnext, insertPipe);
  } else {
    if ((whichFunction > 0) && (whichFunction <= NUM_PORTS)) {
      return IRtoString(IRinput[whichFunction - 1], insertPipe);
    }
  }
}

void IRremoteHelper::setIRcode(int whichFunction, String IRstr)
{
  unsigned long IRcode = StringToIR(IRstr);
  if (whichFunction == IR_UP) {
    IRup = IRcode;
  } else if (whichFunction == IR_DOWN) {
    IRdown = IRcode;
  } else if (whichFunction == IR_POWER) {
    IRpower = IRcode;
  } else if (whichFunction == IR_PREVIOUS) {
    IRprevious = IRcode;
  } else if (whichFunction == IR_NEXT) {
    IRnext = IRcode;
  } else {
    if ((whichFunction > 0) && (whichFunction <= NUM_PORTS)) {
      IRinput[whichFunction - 1] = IRcode;
    }
  }
}

unsigned long IRremoteHelper::StringToIR(String myStr)
{
  // strip out "0x" if the string starts with it
  if (myStr.length() > 2) {
    if (myStr.substring(0,2) == "0x") {
      myStr = myStr.substring(2);
    }
  }
  // strip out pipes used by Nextion for multi-line display division
  String newStr = "";
  for (int i = 0; i < myStr.length(); i++) {
    if (myStr[i] != '|') {
      newStr += myStr[i];
    }
  }
  if (newStr.length() > 0) {
    return strtoul(newStr.c_str(), NULL, 16);
  } else {
    return 0;
  }
}

String IRremoteHelper::IRtoString(unsigned long myIR, bool insertPipe)
{
  if (myIR == 0) return "";
  String tempStr = String(myIR,HEX);
  byte targetLen = tempStr.length();
  if (((int)(tempStr.length() / 2) % 2) == 1) { targetLen += 2; } // if splitting the string in half results in an odd number of digits per line, pad by 2 digits.
  if (targetLen < 10) targetLen = 10;
  if (tempStr.length() < targetLen) {
    byte neededPadding = targetLen - tempStr.length();
    for (byte b = 0; b < neededPadding; b++) {
      tempStr = "0" + tempStr;
    }
  }
  if (insertPipe) {
    tempStr = tempStr.substring(0,(targetLen / 2)) + '|' + tempStr.substring((targetLen / 2));
    tempStr.toUpperCase();
  } else {
    tempStr = tempStr.substring(0,(targetLen / 2)) + tempStr.substring((targetLen / 2));
    tempStr.toUpperCase();
    tempStr = "0x" + tempStr;
  }
  return tempStr;
}
