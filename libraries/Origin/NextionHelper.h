#ifndef __NEXTIONHELPER_H__
#define __NEXTIONHELPER_H__

#include <Nextion.h>
#include <Origin.h>
#include <OriginConfig.h>
#include <SD.h>
#include <IRremoteHelper.h>

class NextionHelper
{
private:
	IRremoteHelper irHelper;
	
	NexVariable varCurInput = NexVariable(1, 1, "grid.curInput");
	NexVariable varGridMode = NexVariable(1, 2, "grid.mode");
	NexVariable varColorText = NexVariable(1, 3, "grid.txco1");
	NexVariable varColorSelectedText = NexVariable(1, 4, "grid.txco2");
	NexVariable varColorBackground = NexVariable(1, 5, "grid.bgco1");
	NexVariable varColorSelectedBackground = NexVariable(1, 6, "grid.bgco2");
	NexVariable varColorGrid = NexVariable(1, 7, "grid.bdrco");
	NexVariable varDisplayBrightness = NexVariable(1, 8, "grid.bMax");
	NexVariable varDisplayDimLevel = NexVariable(1, 9, "grid.bDim");
	NexTimer varDisplayTimer = NexTimer(1, 10, "grid.tmDim");
	
	NexVariable varMenuMode = NexVariable(2, 20, "menu.mode");
	NexVariable varMenuSubMode = NexVariable(2, 21, "menu.subMode");
	NexVariable varMenuIRcode = NexVariable(2, 22, "menu.IRcode");
	
	NexVariable * _varList;
	NexTouch ** _objects;
	
	NexPage _pageSplash = NexPage(0, 0, "splash");
	NexPage _pageGrid = NexPage(1, 0, "grid");
	NexPage _pageMenu = NexPage(2, 0, "menu");
	NexPage _pageEdit = NexPage(3, 0, "edit");
	
public:
	NextionHelper();
	~NextionHelper();
	
	void Init();
	
	int handleEvents(); // should be called in loop() to process any pending events such as IR codes.
	                    // will return a function code if one needs to be processed.
	
	NexTouch ** getNexObjects();
	
	void gotoPage(int pageNum);
	
	int getGUIinput(); // 1 based
	void setGUIinput(int value); // 1 based
	
	int getGridMode();
	void setGridMode(int value);
	
	int getMenuMode();
	void setMenuMode(int value);
	int getMenuSubMode();
	String getMenuIRcode();
	void setMenuIRcode(String code);
	
	unsigned long getUserPref(int pref); // 1 = Text, 2 = Selected Text, 3 = Background, 4 = Selected Background, 5 = Grid
	void setUserPref(int pref, unsigned long value);
	
	bool readFromSD();
	bool saveToSD();
};

#endif
