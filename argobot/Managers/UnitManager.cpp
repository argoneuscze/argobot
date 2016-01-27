#include "UnitManager.h"

#include <BWAPI/Game.h>
#include <BWAPI/Player.h>
#include <BWAPI/Unitset.h>
#include "../Util/Util.cpp"

using namespace BWAPI;


void UnitManager::onFrame()
{
}

void UnitManager::onUnitComplete(Unit unit)
{
	if (unit->getType().isWorker())
		workers.push_back(unit);
}

const std::vector<Unit>& UnitManager::getAllWorkers() const
{
	return workers;
}

std::vector<Unit> UnitManager::getIdleWorkers()
{
	return getSubset(workers.begin(), workers.end(), [](Unit& unit)
	                 {
		                 return unit->isIdle();
	                 });
}

