#include "WorkerManager.h"

#include <BWAPI/Game.h>
#include <BWAPI/Player.h>
#include <BWAPI/Unitset.h>
#include <BWAPI/Unit.h>
#include "UnitManager.h"

using namespace BWAPI;

WorkerManager::WorkerManager(UnitManager& unitManager)
	: unitManager{unitManager}
{
}

void WorkerManager::onStart()
{
	redistributeWorkers();
}

void WorkerManager::onUnitComplete(Unit unit)
{
	if (unit->getType().isWorker())
		assignWorker(unit);
}

void WorkerManager::redistributeWorkers() const
{
	for (auto& worker : unitManager.getIdleWorkers())
	{
		assignWorker(worker.get());
	}
}

void WorkerManager::assignWorker(const Unit& worker) const
{
	if (!worker->exists())
		return;
	worker->gather(worker->getClosestUnit(Filter::IsMineralField));
}

