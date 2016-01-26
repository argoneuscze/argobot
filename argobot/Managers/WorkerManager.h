#pragma once

#include "Manager.h"
#include <BWAPI/PositionUnit.h>
#include "UnitManager.h"

class WorkerManager: public Manager
{
private:
	UnitManager& unitManager;
public:
	explicit WorkerManager(UnitManager& unitManager);

	void onStart() override;

	void redistributeWorkers() const;
	void assignWorker(const BWAPI::Unit& worker) const;
};
