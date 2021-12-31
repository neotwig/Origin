#include "SwitchBoard.h"

SwitchBoard::SwitchBoard(byte boardNumber, byte led, byte power, byte changeInput, byte input1, byte input2, byte input3, byte input4, byte input5)
{
	this->_boardNumber = boardNumber;
	this->_led = led;
	this->_power = power;
	this->_changeInput = changeInput;
	this->_input1 = input1;
	this->_input2 = input2;
	this->_input3 = input3;
	this->_input4 = input4;
	this->_input5 = input5;
}

SwitchBoard::SwitchBoard()
{
	// not implemented
}

void SwitchBoard::powerOn()
{
	if (!isPowerOn())
	{
		//dbSerialPrint("SwitchBoard #");
		//dbSerialPrint(_boardNumber);
		//dbSerialPrintln(" is not powered on.  Powering on now.");
		digitalWrite(_power, LOW);
		delay(20);
		digitalWrite(_power, HIGH);
		//delay(350); // This is how long it takes for the Ask Technology HDMI 2.0a switch's power LED to receive power when the switch is powered on (now processed in NextionHelper instead of here)
	}
}

void SwitchBoard::powerOff()
{
	if (isPowerOn())
	{
		//dbSerialPrint("SwitchBoard #");
		//dbSerialPrint(_boardNumber);
		//dbSerialPrintln(" is powered on.  Powering off now.");
		digitalWrite(_power, LOW);
		delay(20);
		digitalWrite(_power, HIGH);
		// shouldn't need to wait for the power off to occur, since the switch isn't going to be used
	}
}

bool SwitchBoard::isPowerOn()
{
	//delay(20);
	if (digitalRead(_led) == LOW) return false;
	return true;
}

byte SwitchBoard::attemptSetInput(int input) // returns 0 when the input is successfully set
{
	//dbSerialPrint("SwitchBoard #");
	//dbSerialPrint(_boardNumber);
	//dbSerialPrint(" is attempting to change to input #");
	//dbSerialPrintln(input);
	switch (input)
	{
		case 1:
			return targetInputPin(_input1);
			break;
		case 2:
			return targetInputPin(_input2);
			break;
		case 3:
			return targetInputPin(_input3);
			break;
		case 4:
			return targetInputPin(_input4);
			break;
		case 5:
			return targetInputPin(_input5);
			break;
	}
}

byte SwitchBoard::getCurrentInput()
{
	//dbSerialPrintln("SwitchBoard::getCurrentInput()");
	
	delay(20);
	if (digitalRead(_input1) == LOW) { return 1; }
	if (digitalRead(_input2) == LOW) { return 2; }
	if (digitalRead(_input3) == LOW) { return 3; }
	if (digitalRead(_input4) == LOW) { return 4; }
	if (digitalRead(_input5) == LOW) { return 5; }

	return 0;
}

byte SwitchBoard::getCurrentInputPin()
{
	//dbSerialPrintln("SwitchBoard::getCurrentInputPin()");
	
	delay(20);
	if (digitalRead(_input1) == LOW) { return _input1; }
	if (digitalRead(_input2) == LOW) { return _input2; }
	if (digitalRead(_input3) == LOW) { return _input3; }
	if (digitalRead(_input4) == LOW) { return _input4; }
	if (digitalRead(_input5) == LOW) { return _input5; }

	return 0;
}

void SwitchBoard::changeInput()
{
	//dbSerialPrintln("SwitchBoard::changeInput - Input button virtually pressed");
	
	digitalWrite(this->_changeInput, LOW);
	delay(20);
	digitalWrite(this->_changeInput, HIGH);
	// don't do the delay here.  we handle it in Origin.cpp so that we can multitask and switch inputs on two SwitchBoards simultaneously.
}

byte SwitchBoard::targetInputPin(byte inputPin)
{
	// check if already on the requested input pin.  if not, make a single attempt to switch to it.
	// return pin number if reached, or 0 if an attempt is being made.
	
	byte currentInputPin = getCurrentInputPin();
	if (currentInputPin == inputPin) { return inputPin; }

	changeInput();
	return 0;
}
