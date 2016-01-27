#pragma once

#include "Manager.h"
#include <BWAPI/Unit.h>
#include <vector>

class UnitManager : public Manager
{
private:
	std::vector<BWAPI::Unit> workers;

public:
	void onFrame() override;
	void onUnitComplete(BWAPI::Unit unit) override;

	const std::vector<BWAPI::Unit>& getAllWorkers() const;
	std::vector<BWAPI::Unit> getIdleWorkers();
};

