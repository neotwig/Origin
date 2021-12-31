#include <NextionHelper.h>

NextionHelper::NextionHelper()
{
}

NextionHelper::~NextionHelper()
{
  if (_varList) { delete[] _varList; }
}

void NextionHelper::Init()
{
  //sd card initializer
  dbSerialPrintln("Initializing SD card reader");
  SD.begin(SD_CS);
  
  dbSerialPrintln("Initializing Nextion variables");
  int ports = NUM_PORTS;
  if (ports == 5)
  {
    NexVariable t1 = NexVariable(1, 45, "grid.tx1");
    NexVariable t2 = NexVariable(1, 46, "grid.tx2");
    NexVariable t3 = NexVariable(1, 47, "grid.tx3");
    NexVariable t4 = NexVariable(1, 48, "grid.tx4");
    NexVariable t5 = NexVariable(1, 49, "grid.tx5");

    NexVariable vArr[] = { t1, t2, t3, t4, t5 };
    _varList = new NexVariable[ports];
    for (int i = 0; i < ports; ++i)
    {
      _varList[i] = vArr[i];
    }
  }
  else if (ports == 9)
  {
    NexVariable t1 = NexVariable(1, 45, "grid.tx1");
    NexVariable t2 = NexVariable(1, 46, "grid.tx2");
    NexVariable t3 = NexVariable(1, 47, "grid.tx3");
    NexVariable t4 = NexVariable(1, 48, "grid.tx4");
    NexVariable t5 = NexVariable(1, 49, "grid.tx5");
    NexVariable t6 = NexVariable(1, 50, "grid.tx6");
    NexVariable t7 = NexVariable(1, 51, "grid.tx7");
    NexVariable t8 = NexVariable(1, 52, "grid.tx8");
    NexVariable t9 = NexVariable(1, 53, "grid.tx9");

    NexVariable vArr[] = { t1, t2, t3, t4, t5, t6, t7, t8, t9 };
    _varList = new NexVariable[ports];
    for (int i = 0; i < ports; ++i)
    {
      _varList[i] = vArr[i];
    }
  }
  else if (ports == 13)
  {
    NexVariable t1 = NexVariable(1, 52, "grid.tx1");
    NexVariable t2 = NexVariable(1, 53, "grid.tx2");
    NexVariable t3 = NexVariable(1, 54, "grid.tx3");
    NexVariable t4 = NexVariable(1, 55, "grid.tx4");
    NexVariable t5 = NexVariable(1, 56, "grid.tx5");
    NexVariable t6 = NexVariable(1, 57, "grid.tx6");
    NexVariable t7 = NexVariable(1, 58, "grid.tx7");
    NexVariable t8 = NexVariable(1, 59, "grid.tx8");
    NexVariable t9 = NexVariable(1, 60, "grid.tx9");
    NexVariable t10 = NexVariable(1, 61, "grid.tx10");
    NexVariable t11 = NexVariable(1, 62, "grid.tx11");
    NexVariable t12 = NexVariable(1, 63, "grid.tx12");
    NexVariable t13 = NexVariable(1, 64, "grid.tx13");
    NexVariable t14 = NexVariable(1, 65, "grid.tx14");
    NexVariable t15 = NexVariable(1, 66, "grid.tx15");
    NexVariable t16 = NexVariable(1, 67, "grid.tx16");

    NexVariable vArr[] = { t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16 };
    _varList = new NexVariable[ports];
    for (int i = 0; i < ports; ++i)
    {
      _varList[i] = vArr[i];
    }
  }
  else if (ports == 17)
  {
    //TODO
  }
  else if (ports == 21)
  {
    //TODO
  }
  else if (ports == 25)
  {
    NexVariable t1 = NexVariable(1, 61, "grid.tx1");
    NexVariable t2 = NexVariable(1, 62, "grid.tx2");
    NexVariable t3 = NexVariable(1, 63, "grid.tx3");
    NexVariable t4 = NexVariable(1, 64, "grid.tx4");
    NexVariable t5 = NexVariable(1, 65, "grid.tx5");
    NexVariable t6 = NexVariable(1, 66, "grid.tx6");
    NexVariable t7 = NexVariable(1, 67, "grid.tx7");
    NexVariable t8 = NexVariable(1, 68, "grid.tx8");
    NexVariable t9 = NexVariable(1, 69, "grid.tx9");
    NexVariable t10 = NexVariable(1, 70, "grid.tx10");
    NexVariable t11 = NexVariable(1, 71, "grid.tx11");
    NexVariable t12 = NexVariable(1, 72, "grid.tx12");
    NexVariable t13 = NexVariable(1, 73, "grid.tx13");
    NexVariable t14 = NexVariable(1, 74, "grid.tx14");
    NexVariable t15 = NexVariable(1, 75, "grid.tx15");
    NexVariable t16 = NexVariable(1, 76, "grid.tx16");
    NexVariable t17 = NexVariable(1, 77, "grid.tx17");
    NexVariable t18 = NexVariable(1, 78, "grid.tx18");
    NexVariable t19 = NexVariable(1, 79, "grid.tx19");
    NexVariable t20 = NexVariable(1, 80, "grid.tx20");
    NexVariable t21 = NexVariable(1, 81, "grid.tx21");
    NexVariable t22 = NexVariable(1, 82, "grid.tx22");
    NexVariable t23 = NexVariable(1, 83, "grid.tx23");
    NexVariable t24 = NexVariable(1, 84, "grid.tx24");
    NexVariable t25 = NexVariable(1, 85, "grid.tx25");

    NexVariable vArr[] = { t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25 };
    _varList = new NexVariable[ports];
    for (int i = 0; i < ports; ++i)
    {
      _varList[i] = vArr[i];
    }
  }
  
  // create list of objects needed for event listener loop
  // must add NULL object at end. Nextion doesn't get the list length so it looks for NULL to terminate iterations
  _objects = new NexTouch*[1];
  _objects[0] = NULL;
  
  dbSerialPrintln("Initializing IR receiver");
  irHelper.Init();
}

// should be called in loop() to process any pending events such as IR codes.
// will return a function code if one needs to be processed.
int NextionHelper::handleEvents()
{
  // Update Arduino IR codes selected by user in Nextion config menu
  byte nextionMenuMode = getMenuMode(); // determine what page and mode the Nextion is in right now
  
  // Change an IR code
  if (nextionMenuMode == 104) {
    // If the Nextion is on the menu page with mode 104, we are being told to save the currently selected IR code.
    // subMode.val will contain the value to modify (1 to num inputs for input-specific jumping)
    //                          (101 = Up, 102 = Down, 103 = Display On/Off, 104 = Previous, 105 = Next)
    // IRcode.txt will contain the the selected IR code as a string.  Pipes will need to be removed to convert to a real IR code.
    int whichFunction = getMenuSubMode();
    irHelper.setIRcode(whichFunction, getMenuIRcode());
    setMenuMode(4); // mode 4 = remote control main menu
    gotoPage(2); // page 2 = menu (this forces a reload of the menu after changing the menu mode)
	saveToSD(); // save the new IR code to the SD card
	return 0;
  }
  
  // Input change requested via touchscreen
  if (nextionMenuMode == 110) {
	setMenuMode(101);
	return getGUIinput(); // input is 1 based
  }
  
  // Request from a config menu to save data and then return to the main config menu
  if (nextionMenuMode == 120) {
	setMenuMode(0);
    gotoPage(2); // page 2 = menu (this forces a reload of the menu after changing the menu mode)
	saveToSD(); // save the new data to the SD card
	return 0; // we know we're in a config menu, so there's no need to check for IR codes
  }
  
  // Request from a config menu to save data and then return to the color scheme menu
  if (nextionMenuMode == 122) {
	setMenuMode(2);
    gotoPage(2); // page 2 = menu (this forces a reload of the menu after changing the menu mode)
	saveToSD(); // save the new data to the SD card
	return 0; // we know we're in a config menu, so there's no need to check for IR codes
  }
  
  // Handle IR input
  unsigned long IRcode = irHelper.receiveIRcode();
  if (IRcode != 0) {
    if (nextionMenuMode == 6) {
      // If the Nextion is on the menu page with mode 6, we are programming IR codes.  Update the Nextion display.
      // Format the IR code for the Nextion display
      setMenuIRcode(irHelper.IRtoString(IRcode, true));
      setMenuMode(106); // 106 = new IR code sent from Arduino
      delay(500); // Nextion has a 100ms cycle for checking these codes.  Give it time to process one before potentially sending another.
	  return 0;
    
    } else if (nextionMenuMode == 101) {
      // If the Nextion display is on the grid page, process the IR code.  We know it's on the grid page when menu.mode is 101
      
	  int IRfunction = irHelper.mapIRcodeToFunction(IRcode);
	  
	  int curInput = getGUIinput(); // GUI input should be more accurate than the hardware input, as the
	                                // but the hardware could be in the middle of switching inputs GUI
									// should be up to date with the input we're switching to (or already on).
	  
      if (IRfunction == IR_PREVIOUS) {
        curInput--;
        if (curInput < 1) curInput = NUM_PORTS;
        return curInput;
    
      } else if (IRfunction == IR_NEXT) {
        curInput++;
        if (curInput > NUM_PORTS) curInput = 1;
        return curInput;
    
      } else if (IRfunction == IR_POWER) {
        // Nextion timer grid.tmInputMonitor interprets 199 as a screen on/off event
        setGridMode(199);
    
      } else if (IRfunction == IR_UP) { // Go vertically up one row on the input selection screen
        if (NUM_PORTS == 5) {
		  if (curInput != 3) { // there is no input above or below 3 on the 5 port layout, so up/down should do nothing
            curInput = curInput - 3;
            if (curInput < 1) curInput = NUM_PORTS + curInput + 1;
		  }
          return curInput;
      
        } else if (NUM_PORTS == 9) {
          curInput = curInput - 3;
          if (curInput < 1) curInput = NUM_PORTS + curInput;
          return curInput;
		  
        } else if (NUM_PORTS == 13) {
		  if (curInput == 1) curInput = 17;
          curInput = curInput - 4;
          if (curInput < 1) curInput = NUM_PORTS + curInput - 1;
          return curInput;
		  
        } else if (NUM_PORTS == 17) {
          //TODO
      
        } else if (NUM_PORTS == 21) {
          //TODO
      
        } else if (NUM_PORTS == 25) {
          curInput = curInput - 5;
          if (curInput < 1) curInput = NUM_PORTS + curInput;
          return curInput;
		  
        }
    
      } else if (IRfunction == IR_DOWN) { // Go vertically down one row on the input selection screen
        if (NUM_PORTS == 5) {
		  if (curInput != 3) { // there is no input above or below 3 on the 5 port layout, so up/down should do nothing
            curInput = curInput + 3;
            if (curInput > NUM_PORTS) curInput = curInput - NUM_PORTS - 1;
		  }
          return curInput;
      
        } else if (NUM_PORTS == 9) {
          curInput = curInput + 3;
          if (curInput > NUM_PORTS) curInput = curInput - NUM_PORTS;
          return curInput;
		  
        } else if (NUM_PORTS == 13) {
		  if (curInput == 13) curInput = -3;
          curInput = curInput + 4;
          if (curInput > NUM_PORTS) curInput = curInput - NUM_PORTS + 1;
          return curInput;
		  
        } else if (NUM_PORTS == 17) {
          //TODO
      
        } else if (NUM_PORTS == 21) {
          //TODO
      
        } else if (NUM_PORTS == 25) {
          curInput = curInput + 5;
          if (curInput > NUM_PORTS) curInput = curInput - NUM_PORTS;
          return curInput;
      
        }
    
      } else { // We didn't match any of the navigation or power buttons, so now check direct input jump buttons
        if ((IRfunction > 0) && (IRfunction <= NUM_PORTS)) {
          return (IRfunction);
        }
      }
    }
  }
  return 0;
}

NexTouch** NextionHelper::getNexObjects()
{
  return _objects;
}

void NextionHelper::gotoPage(int pageNum)
{
  switch(pageNum)
  {
    case 0:
      _pageSplash.show();
      break;
    case 1:
      _pageGrid.show();
      break;
    case 2:
      _pageMenu.show();
      break;
    case 3:
      _pageEdit.show();
      break;
  }
}

int NextionHelper::getGUIinput()
{
  uint32_t value;
  varCurInput.getValue(&value);
  return value;
}

void NextionHelper::setGUIinput(int value)
{
  varCurInput.setValue(value);
}

int NextionHelper::getGridMode()
{
  uint32_t value;
  varGridMode.getValue(&value);
  return value;
}

void NextionHelper::setGridMode(int value)
{
  varGridMode.setValue(value);
}

int NextionHelper::getMenuMode()
{
  uint32_t value;
  varMenuMode.getValue(&value);
  return value;
}

void NextionHelper::setMenuMode(int value)
{
  varMenuMode.setValue(value);
}

int NextionHelper::getMenuSubMode()
{
  uint32_t value;
  varMenuSubMode.getValue(&value);
  return value;
}

String NextionHelper::getMenuIRcode()
{
  uint32_t bufferSize = 40;

  // setup buffer
  char value[bufferSize] = { 0 };
  
  varMenuIRcode.getText(value, bufferSize);
  return value;
}

void NextionHelper::setMenuIRcode(String code)
{
  varMenuIRcode.setText(code.c_str());
}

unsigned long NextionHelper::getUserPref(int pref)
{
  uint32_t value = 0;
  switch (pref)
  {
    case 1: // Text
	  varColorText.getValue(&value);
	  break;
    case 2: // Selected Text
	  varColorSelectedText.getValue(&value);
	  break;
    case 3: // Background
	  varColorBackground.getValue(&value);
	  break;
    case 4: // Selected Background
	  varColorSelectedBackground.getValue(&value);
	  break;
    case 5: // Grid
	  varColorGrid.getValue(&value);
	  break;
    case 6: // Display Brightness
	  varDisplayBrightness.getValue(&value);
	  break;
    case 7: // Screen Saver Dim Level
	  varDisplayDimLevel.getValue(&value);
	  break;
    case 8: // Screen Saver Timer
	  varDisplayTimer.getCycle(&value);
	  break;
  }
  //dbSerialPrintln(value);
  return value;
}

void NextionHelper::setUserPref(int pref, unsigned long value)
{
  switch (pref)
  {
    case 1: // Text
	  varColorText.setValue(value);
	  break;
    case 2: // Selected Text
	  varColorSelectedText.setValue(value);
	  break;
    case 3: // Background
	  varColorBackground.setValue(value);
	  break;
    case 4: // Selected Background
	  varColorSelectedBackground.setValue(value);
	  break;
    case 5: // Grid
	  varColorGrid.setValue(value);
	  break;
    case 6: // Display Brightness
	  varDisplayBrightness.setValue(value);
	  break;
    case 7: // Screen Saver Dim Level
	  varDisplayDimLevel.setValue(value);
	  break;
    case 8: // Screen Saver Timer
	  varDisplayTimer.setCycle(value);
	  break;
  }
}

bool NextionHelper::saveToSD() {
  // NOTE: if write operation is failing, see note in Origin3.ino and extend timeout in NexHardware.h to 3000 ms.

  // Writes the current configuration to the ORIGIN.TXT file.
  dbSerialPrintln("***********Save to SD Starting************");
  
  File myFile;
  uint32_t bufferSize = 40;
  char buffer[bufferSize] = { 0 };
  uint32_t bufferLength = 0;

  // read the label texts from Nextion and store in buffer
  for (int i = 0; i < NUM_PORTS; ++i)
  {
    
    
  }
  if (SD.exists("ORIGIN.TXT") == true) {
    dbSerialPrintln("ORIGIN.TXT Exists");
    SD.remove("ORIGIN.TXT");
  }

  myFile = SD.open("ORIGIN.TXT", FILE_WRITE);
  if (!myFile) {
    // Error: Unable to open file for writing on the SD card.
    dbSerialPrintln("ERROR: Cannot Write to File ORIGIN.TXT");

    return false;
  }
  else {
    dbSerialPrintln("Writing to File ORIGIN.TXT");
    myFile.println(F("# This file configures the Origin HDMI System Selector."));
    myFile.println(F("# It must be named ORIGIN.TXT for settings to be applied."));
    myFile.println(F(""));
    myFile.println(F("# Button Labels"));
    myFile.println(F(""));
	for (int i = 1; i <= NUM_PORTS; i++) {
		// get the text from the Nextion display
		bufferLength = _varList[i-1].getText(buffer, bufferSize);
		
		// since we're reusing the same buffer, old data will mix in if we don't specify the end of the string with a null character.
		buffer[bufferLength] = '\0'; 
		
		dbSerialPrintln("LABEL " + String(i) + "=" + String(buffer));
		myFile.println("LABEL " + String(i) + "=" + String(buffer));
	}
    myFile.println(F(""));
    myFile.println(F("# IR Remote Codes"));
    myFile.println(F(""));
	for (int i = 1; i <= NUM_PORTS; i++) {
		dbSerialPrintln("REMOTE " + String(i) + "=" + irHelper.getIRcode(i,false));
		myFile.println("REMOTE " + String(i) + "=" + irHelper.getIRcode(i,false));
	}
	dbSerialPrintln("REMOTE UP=" + irHelper.getIRcode(IR_UP,false));
	myFile.println("REMOTE UP=" + irHelper.getIRcode(IR_UP,false));
	dbSerialPrintln("REMOTE DOWN=" + irHelper.getIRcode(IR_DOWN,false));
	myFile.println("REMOTE DOWN=" + irHelper.getIRcode(IR_DOWN,false));
	dbSerialPrintln("REMOTE PREVIOUS=" + irHelper.getIRcode(IR_PREVIOUS,false));
	myFile.println("REMOTE PREVIOUS=" + irHelper.getIRcode(IR_PREVIOUS,false));
	dbSerialPrintln("REMOTE NEXT=" + irHelper.getIRcode(IR_NEXT,false));
	myFile.println("REMOTE NEXT=" + irHelper.getIRcode(IR_NEXT,false));
	dbSerialPrintln("REMOTE POWER=" + irHelper.getIRcode(IR_POWER,false));
	myFile.println("REMOTE POWER=" + irHelper.getIRcode(IR_POWER,false));
    myFile.println(F(""));
    myFile.println(F("# Origin Preferences"));
    myFile.println(F(""));
	dbSerialPrintln("COLOR TEXT=" + String(getUserPref(1)));
	myFile.println("COLOR TEXT=" + String(getUserPref(1)));
	dbSerialPrintln("COLOR SELECTEDTEXT=" + String(getUserPref(2)));
	myFile.println("COLOR SELECTEDTEXT=" + String(getUserPref(2)));
	dbSerialPrintln("COLOR BACKGROUND=" + String(getUserPref(3)));
	myFile.println("COLOR BACKGROUND=" + String(getUserPref(3)));
	dbSerialPrintln("COLOR SELECTEDBACKGROUND=" + String(getUserPref(4)));
	myFile.println("COLOR SELECTEDBACKGROUND=" + String(getUserPref(4)));
	dbSerialPrintln("COLOR GRID=" + String(getUserPref(5)));
	myFile.println("COLOR GRID=" + String(getUserPref(5)));
	dbSerialPrintln("COLOR BRIGHTNESS=" + String(getUserPref(6)));
	myFile.println("DISPLAY BRIGHTNESS=" + String(getUserPref(6)));
	dbSerialPrintln("COLOR DIMLEVEL=" + String(getUserPref(7)));
	myFile.println("DISPLAY DIMLEVEL=" + String(getUserPref(7)));
	dbSerialPrintln("COLOR TIMER=" + String(getUserPref(8)));
	myFile.println("DISPLAY TIMER=" + String(getUserPref(8)));
    myFile.println(F(""));
    myFile.close();

    dbSerialPrintln("***********Save to SD Finished************");
    return true;
  }
}

bool NextionHelper::readFromSD() {
  // NOTE: if read operation is failing, see note in Origin3.ino and extend timeout in NexHardware.h to 3000 ms.

  dbSerialPrintln("***********Read from SD Starting************");
  File myFile;

  // Ensure that the ORIGIN.TXT file exists on the SD card so user has a template to work from.
  if (SD.exists("ORIGIN.TXT") == false) {
    dbSerialPrintln("ORIGIN.TXT cannot be read as it does not exist.");
    // ORIGIN.TXT file not found.
    return false;
  }
  else {
    // Load the ORIGIN.TXT file
    dbSerialPrintln("Reading ORIGIN.TXT");
    myFile = SD.open("ORIGIN.TXT", FILE_READ);
    if (!myFile) {
      // ORIGIN.TXT failed to open.
      return false;
    }
    else {
      String myLine;
      String myParam;
      String myValue;
      int separatorSpot;
      unsigned long tempLong;

      while (myFile.available()) {
        myLine = myFile.readStringUntil('\n');
        if (myLine.length() > 0) {
          if (myLine[0] != '#') {
            myParam = "";
            myValue = "";
            separatorSpot = myLine.indexOf('=');
            if (separatorSpot != -1) {
              // Extract the parameter and value from the string
              myParam = myLine.substring(0, separatorSpot);
              myValue = myLine.substring(separatorSpot + 1);

              // Strip any unwanted characters
              myValue.replace("\r", "");
              myValue.replace("\n", "");

              // Replace the string "\n" (which is really two characters '\' and 'n') with the new line character '\n'
              myValue.replace("\\n", "\n");

              // Ensure that the parameter portion is in all caps to make string comparisons easy
              myParam.toUpperCase();

              if (myParam.startsWith("LABEL ")) {
                myParam.remove(0, 6); // remove "LABEL "
                tempLong = strtoul(myParam.c_str(), NULL, 10);
                if ((tempLong > 0) && (tempLong <= NUM_PORTS)) {
                  dbSerialPrintln("LABEL " + String(tempLong) + "=" + myValue);
                  _varList[(tempLong - 1)].setText(myValue.c_str() + '\0');
                }                
              } else if (myParam.startsWith("REMOTE ")) {
				myParam.remove(0, 7); // remove "REMOTE "
				dbSerialPrintln("REMOTE " + myParam + "=" + myValue);
				if (myParam == "UP") {
				  irHelper.setIRcode(IR_UP, myValue);
				} else if (myParam == "DOWN") {
				  irHelper.setIRcode(IR_DOWN, myValue);
				} else if (myParam == "PREVIOUS") {
				  irHelper.setIRcode(IR_PREVIOUS, myValue);
				} else if (myParam == "NEXT") {
				  irHelper.setIRcode(IR_NEXT, myValue);
				} else if (myParam == "POWER") {
				  irHelper.setIRcode(IR_POWER, myValue);
				} else {
				  tempLong = strtoul(myParam.c_str(), NULL, 10); // returns 0 if the string is not numeric
				  if ((tempLong > 0) && (tempLong <= NUM_PORTS)) {
				    irHelper.setIRcode((int)tempLong, myValue);
				  }
				}
			  } else if (myParam.startsWith("COLOR ")) {
				myParam.remove(0, 6); // remove "COLOR "
				dbSerialPrintln("COLOR " + myParam + "=" + myValue);
                tempLong = strtoul(myValue.c_str(), NULL, 10);
				if (myParam == "TEXT") {
				  setUserPref(1, tempLong);
				} else if (myParam == "SELECTEDTEXT") {
				  setUserPref(2, tempLong);
				} else if (myParam == "BACKGROUND") {
				  setUserPref(3, tempLong);
				} else if (myParam == "SELECTEDBACKGROUND") {
				  setUserPref(4, tempLong);
				} else if (myParam == "GRID") {
				  setUserPref(5, tempLong);
				}
			  } else if (myParam.startsWith("DISPLAY ")) {
				myParam.remove(0, 8); // remove "DISPLAY "
				dbSerialPrintln("DISPLAY " + myParam + "=" + myValue);
                tempLong = strtoul(myValue.c_str(), NULL, 10);
				if (myParam == "BRIGHTNESS") {
				  setUserPref(6, tempLong);
				} else if (myParam == "DIMLEVEL") {
				  setUserPref(7, tempLong);
				} else if (myParam == "TIMER") {
				  setUserPref(8, tempLong);
				}
			  }
            }
          }
        }
      }
      myFile.close();

      dbSerialPrintln("***********Read from SD Finished************");
      return true;
    }
  }
}
