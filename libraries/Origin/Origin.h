#ifndef __ORIGIN_H__
#define __ORIGIN_H__

#include <SwitchBoard.h>
#include <OriginConfig.h>
#include <Arduino.h>
#include <Nextion.h>

class Origin
{
private:
	unsigned long lastMillis;
	unsigned long swxOperationDelay;
	
	SwitchBoard* boards;
	SwitchBoard& getBoardByInputNumber(int input);

public:
	Origin();
	~Origin();
	// methods
	int getNumberOfSwitches();
	byte getInput();
	byte attemptSetInput(int input);
	void setupOrigin();
	void dbPrintBoardStats();
	
};

#endif
