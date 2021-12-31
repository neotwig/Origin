#ifndef __SWITCHBOARD_H__
#define __SWITCHBOARD_H__

#include <Arduino.h>
#include <Nextion.h>

class SwitchBoard
{
private:
	byte _boardNumber;
	byte _led;
	byte _power;
	byte _changeInput;
	byte _input1;
	byte _input2;
	byte _input3;
	byte _input4;
	byte _input5;
	
	void changeInput();
	byte targetInputPin(byte);

public:
	SwitchBoard(byte boardNumber, byte led, byte power, byte changeInput, byte input1, byte input2, byte input3, byte input4, byte input5);
	SwitchBoard();
	void powerOn(); // returns the suggested delay to ensure that the operation completes
	bool isPowerOn();
	void powerOff(); // returns the suggested delay to ensure that the operation completes
	byte attemptSetInput(int input); // returns 0 when the input is successfully set.  doesn't guarantee the input change to allow for multitasking.
	byte getCurrentInput();
	byte getCurrentInputPin();

};

#endif


