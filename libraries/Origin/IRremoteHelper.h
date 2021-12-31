#ifndef __IRRREMOTEHELPER_H__
#define __IRRREMOTEHELPER_H__

#include <Arduino.h>
#include <Nextion.h>
#include <OriginConfig.h>
#include <string.h>

// whichFunction value must match pre-defined values
// 1 thru 25 = Jump to specific input number
const byte IR_UP = 101;
const byte IR_DOWN = 102;
const byte IR_POWER = 103;
const byte IR_PREVIOUS = 104;
const byte IR_NEXT = 105;	

class IRremoteHelper
{
private:
	
	// Infrared controls map
	unsigned long IRinput[25] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	unsigned long IRpower = 0;
	unsigned long IRup = 0;
	unsigned long IRdown = 0;
	unsigned long IRprevious = 0;
	unsigned long IRnext = 0;
	
public:
	IRremoteHelper();
	~IRremoteHelper();
	
	void Init();
	
	unsigned long receiveIRcode();
	
	int mapIRcodeToFunction(unsigned long IRcode);
	
	String getIRcode(int whichFunction, bool insertPipe);
	void setIRcode(int whichFunction, String IRcode);
	
	unsigned long StringToIR(String myStr);
	String IRtoString(unsigned long myIR, bool insertPipe);
};

#endif