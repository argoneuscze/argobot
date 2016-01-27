#pragma once

#include "Manager.h"
#include <BWAPI/Unit.h>

class BuildingManager : public Manager
{
private:
	std::vector<BWAPI::Unit> workerBuildings;

public:
	void onFrame() override;
	void onUnitComplete(BWAPI::Unit unit) override;
};

