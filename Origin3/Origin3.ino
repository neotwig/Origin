//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////   Origin 5, 9, 13, 17, 21, or 25 port HDMI 2.0 Switch   ///////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Arduino.h>
#include <OriginConfig.h>
#include <Origin.h>
#include <SPI.h>       // SPI = Serial Peripheral Interface.  Required for SD cards, among other things.
#include <SD.h>        // SD card reader
#include <Nextion.h>   // Nextion Display
#include <NextionHelper.h>
#include <SwitchBoard.h>

//////////////////////////////////////////////////////////////////////////////////////////////////////
// NOTE: NexHardware.h has default timeout values of 100 ms.  These need to be extended to allow some
// operations to complete without errors.  3000 ms is recommended.  Lower values would probably work
// but have not been tested.  If the default 100 ms value is unmodified, save and load operations will
// produce unexpected results, such as shifting input labels or leaving some/all input labels blank.
//////////////////////////////////////////////////////////////////////////////////////////////////////

Origin origin;
NextionHelper nexHelper;
int lastDisplayedInput = 0;
int targetInput = 0;

void setup()
{
  // debugging code is turned on/off in NexConfig.h
  
	nexInit(); // no debugging code can occur before this, as it initializes serial communications (see NexHardware.cpp)
  
  dbSerialPrintln("Initializing NexHelper library");
  nexHelper.Init();

  // if the Arduino has rebooted (usually due to programming), reset the Nextion also.  102 = Nextion splash screen
  if (nexHelper.getMenuMode() != 102) nexHelper.gotoPage(0);
  
  dbSerialPrintln("Initializing Origin library");
	origin.setupOrigin();
 
  dbSerialPrintln("Reading data from SD card");
	nexHelper.readFromSD(); // if read operation is failing, see note above and extend timeout in NexHardware.h to 3000 ms.
 
	dbSerialPrintln("Setup complete!");
  nexHelper.gotoPage(1); // Nextion display will stay at splash screen until we tell it to go to the grid page (page # 1)
}

// Add the main program code into the continuous loop() function
void loop()
{
  //nexLoop(nexHelper.getNexObjects());

  // process any pending events such as IR codes, and return 0 or a new target input if the IR code indicated an input change
  int newTargetInput = nexHelper.handleEvents();
  if (newTargetInput != 0) {
    targetInput = newTargetInput; // if an IR code indicated an input change, override any existing target input
    nexHelper.setGUIinput(targetInput);
  }

  // targetInput is non-zero if an input change is in process
  if (targetInput != 0) {
    // continue the input change attempt
    targetInput = origin.attemptSetInput(targetInput);
  } else {
    // Handle automatic input switching done by the SwitchBoards themselves.  Update the display to reflect the current input.
    int curInput = origin.getInput();
    if (curInput != lastDisplayedInput)
    {
      lastDisplayedInput = curInput;
      nexHelper.setGUIinput(curInput);
    }
  }
}
