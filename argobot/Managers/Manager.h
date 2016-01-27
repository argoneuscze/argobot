#pragma once
#include <BWAPI/Unit.h>

class Manager
{
public:
	virtual ~Manager();
	virtual void onStart();
	virtual void onFrame() = 0;
	virtual void onUnitComplete(BWAPI::Unit unit);
};

