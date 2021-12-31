#include "Origin.h"

SwitchBoard & Origin::getBoardByInputNumber(int input)
{
	// find switch board number 1 through 6
	int boardNumber = input - 1;
	boardNumber = boardNumber / 5;
	SwitchBoard * targetedBoard = &boards[boardNumber];
	return *targetedBoard;
}

Origin::Origin()
{
	lastMillis = millis();
	swxOperationDelay = 0;
}

void Origin::setupOrigin()
{
	boards = new SwitchBoard[NUM_SWITCHES];

	dbSerialPrint("Configuring for ");
	dbSerialPrint(NUM_SWITCHES);
	dbSerialPrintln(" SwitchBoards");
	
	// setup SwitchBoards
	for (int i = 0; i < NUM_SWITCHES; ++i)
	{
		dbSerialPrint("Setting up SwitchBoard #");
		dbSerialPrintln(i+1);
		switch (i)
		{
			case 0:
			{
				boards[i] = SwitchBoard(1, SWX1_POWERLED, SWX1_POWERBUTTON, SWX1_CHANGEINPUT, SWX1_INPUT1, SWX1_INPUT2, SWX1_INPUT3, SWX1_INPUT4, SWX1_INPUT5);
				pinMode(SWX1_POWERBUTTON, OUTPUT);
				digitalWrite(SWX1_POWERBUTTON, HIGH);
				pinMode(SWX1_CHANGEINPUT, OUTPUT);
				digitalWrite(SWX1_CHANGEINPUT, HIGH);
				pinMode(SWX1_INPUT1, INPUT);
				pinMode(SWX1_INPUT2, INPUT);
				pinMode(SWX1_INPUT3, INPUT);
				pinMode(SWX1_INPUT4, INPUT);
				pinMode(SWX1_INPUT5, INPUT);
				break;
			}

			case 1:
			{
				boards[i] = SwitchBoard(2, SWX2_POWERLED, SWX2_POWERBUTTON, SWX2_CHANGEINPUT, SWX2_INPUT1, SWX2_INPUT2, SWX2_INPUT3, SWX2_INPUT4, SWX2_INPUT5);
				pinMode(SWX2_POWERBUTTON, OUTPUT);
				digitalWrite(SWX2_POWERBUTTON, HIGH);
				pinMode(SWX2_CHANGEINPUT, OUTPUT);
				digitalWrite(SWX2_CHANGEINPUT, HIGH);
				pinMode(SWX2_INPUT1, INPUT);
				pinMode(SWX2_INPUT2, INPUT);
				pinMode(SWX2_INPUT3, INPUT);
				pinMode(SWX2_INPUT4, INPUT);
				pinMode(SWX2_INPUT5, INPUT);
				break;
			}

			case 2:
			{
				boards[i] = SwitchBoard(3, SWX3_POWERLED, SWX3_POWERBUTTON, SWX3_CHANGEINPUT, SWX3_INPUT1, SWX3_INPUT2, SWX3_INPUT3, SWX3_INPUT4, SWX3_INPUT5);
				pinMode(SWX3_POWERBUTTON, OUTPUT);
				digitalWrite(SWX3_POWERBUTTON, HIGH);
				pinMode(SWX3_CHANGEINPUT, OUTPUT);
				digitalWrite(SWX3_CHANGEINPUT, HIGH);
				pinMode(SWX3_INPUT1, INPUT);
				pinMode(SWX3_INPUT2, INPUT);
				pinMode(SWX3_INPUT3, INPUT);
				pinMode(SWX3_INPUT4, INPUT);
				pinMode(SWX3_INPUT5, INPUT);
				break;
			}
			case 3:
			{
				boards[i] = SwitchBoard(4, SWX4_POWERLED, SWX4_POWERBUTTON, SWX4_CHANGEINPUT, SWX4_INPUT1, SWX4_INPUT2, SWX4_INPUT3, SWX4_INPUT4, SWX4_INPUT5);
				pinMode(SWX4_POWERBUTTON, OUTPUT);
				digitalWrite(SWX4_POWERBUTTON, HIGH);
				pinMode(SWX4_CHANGEINPUT, OUTPUT);
				digitalWrite(SWX4_CHANGEINPUT, HIGH);
				pinMode(SWX4_INPUT1, INPUT);
				pinMode(SWX4_INPUT2, INPUT);
				pinMode(SWX4_INPUT3, INPUT);
				pinMode(SWX4_INPUT4, INPUT);
				pinMode(SWX4_INPUT5, INPUT);
				break;
			}
			case 4:
			{
				boards[i] = SwitchBoard(5, SWX5_POWERLED, SWX5_POWERBUTTON, SWX5_CHANGEINPUT, SWX5_INPUT1, SWX5_INPUT2, SWX5_INPUT3, SWX5_INPUT4, SWX5_INPUT5);
				pinMode(SWX5_POWERBUTTON, OUTPUT);
				digitalWrite(SWX5_POWERBUTTON, HIGH);
				pinMode(SWX5_CHANGEINPUT, OUTPUT);
				digitalWrite(SWX5_CHANGEINPUT, HIGH);
				pinMode(SWX5_INPUT1, INPUT);
				pinMode(SWX5_INPUT2, INPUT);
				pinMode(SWX5_INPUT3, INPUT);
				pinMode(SWX5_INPUT4, INPUT);
				pinMode(SWX5_INPUT5, INPUT);
				break;
			}
			case 5:
			{
				boards[i] = SwitchBoard(6, SWX6_POWERLED, SWX6_POWERBUTTON, SWX6_CHANGEINPUT, SWX6_INPUT1, SWX6_INPUT2, SWX6_INPUT3, SWX6_INPUT4, SWX6_INPUT5);
				pinMode(SWX6_POWERBUTTON, OUTPUT);
				digitalWrite(SWX6_POWERBUTTON, HIGH);
				pinMode(SWX6_CHANGEINPUT, OUTPUT);
				digitalWrite(SWX6_CHANGEINPUT, HIGH);
				pinMode(SWX6_INPUT1, INPUT);
				pinMode(SWX6_INPUT2, INPUT);
				pinMode(SWX6_INPUT3, INPUT);
				pinMode(SWX6_INPUT4, INPUT);
				pinMode(SWX6_INPUT5, INPUT);
				break;
			}
		}
	}
}

Origin::~Origin()
{
	if (boards)
	{
		delete[] boards;
	}
}

int Origin::getNumberOfSwitches()
{
	return NUM_SWITCHES;
}

void Origin::dbPrintBoardStats()
{
	// prints switch board information for debugging purposes. Prints to serial monitor if Serial2 is enabled

	// see which boards are on
	for (int i = 0; i < NUM_SWITCHES; ++i)
	{
		dbSerialPrint("Board Number: ");
		dbSerialPrint(i+1);
		dbSerialPrint(", Powered on: ");
		dbSerialPrint(boards[i].isPowerOn());
		if (boards[i].isPowerOn())
		{
			dbSerialPrint(", Active pin: ");
			dbSerialPrint(boards[i].getCurrentInputPin());
			dbSerialPrint(", Active port: ");
			dbSerialPrint(boards[i].getCurrentInput());
		}
		if (i == (NUM_SWITCHES - 1)) dbSerialPrint(" (HUB)");
		dbSerialPrintln();
	}
	dbSerialPrint("Logical active port: ");
	dbSerialPrintln(getInput());
}

byte Origin::getInput()
{
	//dbSerialPrintln("Origin::getInput()");
	SwitchBoard targetedBoard;
	SwitchBoard hub;
	byte logicalInput = 0;
	
	// identify hub board
	hub = boards[NUM_SWITCHES - 1];
	
	byte hubInput = hub.getCurrentInput();
	//dbSerialPrint("Hub input: ");
	//dbSerialPrintln(hubInput);
	if (hubInput > (NUM_SWITCHES - 1))
	{
		logicalInput = hubInput + ((NUM_SWITCHES - 1) * 5) - (NUM_SWITCHES - 1);
	}
	else
	{
		byte swxInput = boards[hubInput - 1].getCurrentInput();
		//dbSerialPrint("Switch ");
		//dbSerialPrint(hubInput);
		//dbSerialPrint(" input: ");
		//dbSerialPrintln(swxInput);
		logicalInput = swxInput + ((hubInput - 1) * 5);
	}
	//dbSerialPrint("Logical input: ");
	//dbSerialPrintln(logicalInput);
	//dbSerialPrintln();
	
	return logicalInput;
}

byte Origin::attemptSetInput(int input)
{
	// since we know this is only attempting to set the input and not guaranteeing it, we'll handle
	// the "delay" between switchboard operations (change input/power on/power off) here using
	// millis() to track how long it's been since the last operation.  if it hasn't been long enough,
	// we'll do nothing in order to allow other operations (mostly IR receiving) to happen while we wait.
	
	// by writing the millis comparison this way, we account for the overflow of millis(), which is returns an
	// unsigned long, every 50 days.  the subtraction equation will overflow also, resulting in the correct answer.
	// credit: https://www.norwegiancreations.com/2018/10/arduino-tutorial-avoiding-the-overflow-issue-when-using-millis-and-micros/
	if (millis() - lastMillis > swxOperationDelay)
	{
		// lastMillis will be reset at the end of this code block, once the necessary delay is determined.
		
		//dbSerialPrint("Origin::attemptSetInput(");
		//dbSerialPrint(input);
		//dbSerialPrintln(")");
		SwitchBoard targetedBoard;
		SwitchBoard hubBoard;

		//dbSerialPrintln();
		//dbPrintBoardStats();

		// find SwitchBoard number (0 through 5) that the logical input is physically on
		int boardNumber = input - 1;
		boardNumber = boardNumber / 5;
		
		// find SwitchBoard number for the hub.  (boards array is 0 based.  for a 5 port switch, hub = 0.  9 port, hub = 1.  etc.)
		int hubNumber = NUM_SWITCHES - 1;
		
		targetedBoard = boards[boardNumber];
		hubBoard = boards[hubNumber];
		
		//dbSerialPrint("boardNumber: ");
		//dbSerialPrintln(boardNumber);
		//dbSerialPrint("hubNumber: ");
		//dbSerialPrintln(hubNumber);

		// turn off boards not needed
		for (int i = 0; i < NUM_SWITCHES; ++i)
		{
			if (i != boardNumber && i != hubNumber)
			{
				//dbSerialPrint("Powering off switch # ");
				//dbSerialPrintln(i+1);
				boards[i].powerOff();
			}
		}

		// the attemptSetInput command ATTEMPTS to set the input but doesn't guarantee it because
		// a guarantee would take too long.  when switching inputs on two switches at once,
		// it's faster to handle that here than in SwitchBoard.cpp, because we can effectively
		// do two things at once and only have one delay instead of two.
		
		byte hubReturn = 0;
		byte targetReturn = 0;
		int loopDelay = 150; // default value for each iteration of this function.  can be increased if needed for powering on a SwitchBoard.
			
		//dbSerialPrint("Origin::setInput counter: ");
		//dbSerialPrintln(counter);
		
		// hubReturn will be non-zero once the hub is at the correct input.  if hubReturn is 0, we continue checking the hub.
		if (hubReturn == 0)
		{
			// if the requested input is not on the hub switch, set the hub to the input that corresponds with the targetedBoard's output (A thru E)
			if (boardNumber != hubNumber)
			{
				if (hubBoard.isPowerOn() == false) {
					hubBoard.powerOn();
					//dbSerialPrintln("Hub SwitchBoard is powering on.");
					loopDelay = 350; // This is how long it takes for the Ask Technology HDMI 2.0a switch's power LED to receive power when the switch is powered on
				}
				else
				{
					hubReturn = hubBoard.attemptSetInput(boardNumber + 1); // hub ports are conveniently equivalent to the switchboards that connect to them for all Origin configurations
					if (hubReturn == 0) {
						//dbSerialPrintln("Hub SwitchBoard is processing an input change.");
					}
					else
					{
						//dbSerialPrintln("Hub SwitchBoard is done processing.  It is at the correct input.");
					}
				}
			}
			else
			{
				hubReturn = 255;
			}
		}
		
		// targetReturn will be non-zero once targetBoard is at the correct input.  if targetReturn is 0, we continue checking targetBoard.
		if (targetReturn == 0)
		{
			if (targetedBoard.isPowerOn() == false) {
				targetedBoard.powerOn();
				//dbSerialPrintln("Target SwitchBoard is powering on.");
				loopDelay = 350; // This is how long it takes for the Ask Technology HDMI 2.0a switch's power LED to receive power when the switch is powered on
			}
			else
			{
				// now we need to select the input on the targeted board
				switch (NUM_PORTS)
				{
					case 5:

					{
						targetReturn = targetedBoard.attemptSetInput(input);
						break;
					}

					case 9:
					{
						if (input <= 5)
						{
							targetReturn = targetedBoard.attemptSetInput(input);
						}
						else
						{
							targetReturn = targetedBoard.attemptSetInput(input - 4);
						}
						break;
					}

					case 13:
					{
						int port = input % 5;
						if (input <= 10)
						{
							if (port == 0) port = 5;
							targetReturn = targetedBoard.attemptSetInput(port);
						}
						else
						{
							port += 2;
							targetReturn = targetedBoard.attemptSetInput(port);
						}
						break;
					}

					case 17:
					{
						int port = input % 5;
						if (input <= 15)
						{
							if (port == 0) port = 5;
							targetReturn = targetedBoard.attemptSetInput(port);
						}
						else
						{
							port += 3;
							targetReturn = targetedBoard.attemptSetInput(port);
						}
						break;
					}

					case 21:
					{
						int port = input % 5;
						if (input <= 20)
						{
							if (port == 0) port = 5;
							targetReturn = targetedBoard.attemptSetInput(port);
						}
						else
						{
							targetReturn = targetedBoard.attemptSetInput(5);
						}
						break;
					}

					case 25:
					{
						int port = input % 5;
						if (port == 0) port = 5;
						targetReturn = targetedBoard.attemptSetInput(port);
						break;
					}
				}
				if (targetReturn == 0) {
					//dbSerialPrintln("Target SwitchBoard is processing an input change.");
				}
				else
				{
					//dbSerialPrintln("Target SwitchBoard is done processing.  It is at the correct input.");
				}
			}
		}
		
		if ((hubReturn == 0) || (targetReturn == 0)) {
			// if either the hub or target SwitchBoards returned 0 when attempting to change inputs,
			// that means they've requested an input change and require a delay to see if it reached the target input.
			
			// Give the input change some time to process and then loop to check if the requested input is now selected.
			swxOperationDelay = loopDelay;
			lastMillis = millis();
			
			// we're still trying to reach the target input, so return that same input number to trigger another run of this function
			return input;
		}
		else
		{
			//dbPrintBoardStats();
			//dbSerialPrintln();
			swxOperationDelay = 0;
			lastMillis = millis();
			return 0;
		}
	}
	else
	{
		// we're still trying to reach the target input, and are waiting for a previous operation to complete
		// before we can try again.  return the requested input number to trigger another run of this function.
		return input;
	}
}

