#include "WorkerManager.h"

#include <BWAPI/Game.h>
#include <BWAPI/Player.h>
#include <BWAPI/Unitset.h>
#include <BWAPI/Unit.h>
#include "UnitManager.h"
#include "../Util/Util.cpp"

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
	auto workers = unitManager.getAllWorkers();
	forEachIf(workers.begin(), workers.end(), [](Unit& u)
	          {
		          return u->isIdle();
	          }, [this](Unit& u)
	          {
		          assignWorker(u);
	          });
}

void WorkerManager::assignWorker(const Unit& worker) const
{
	if (!worker->exists())
		return;
	worker->gather(worker->getClosestUnit(Filter::IsMineralField));
}

