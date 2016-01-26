#pragma once
#include <BWAPI/Unit.h>

class Manager
{
public:
	virtual ~Manager();
	virtual void onStart() = 0;
	virtual void onFrame();
	virtual void onUnitComplete(BWAPI::Unit unit);
};

