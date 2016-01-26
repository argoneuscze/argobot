#include "UnitManager.h"

#include <BWAPI/Game.h>
#include <BWAPI/Player.h>
#include <BWAPI/Unitset.h>

using namespace BWAPI;


void UnitManager::onStart()
{
	for (auto& unit : Broodwar->self()->getUnits())
	{
		if (unit->getType().isWorker())
			workers.push_back(unit);
	}
}

const std::vector<Unit>& UnitManager::getAllWorkers() const
{
	return workers;
}

UnitManager::unitRefs UnitManager::getIdleWorkers()
{
	return getUnitRefs(workers.begin(), workers.end(), [](Unit& unit)
	                   {
		                   return unit->isIdle();
	                   });
}

