#include "BuildingManager.h"

#include <BWAPI/Game.h>
#include <BWAPI/Unitset.h>
#include <BWAPI/Player.h>

using namespace BWAPI;

void BuildingManager::onStart()
{
	for (auto& unit : Broodwar->self()->getUnits())
	{
		if (unit->getType().isResourceDepot())
			workerBuildings.push_back(unit);
	}
}

void BuildingManager::onFrame()
{
	auto minerals = Broodwar->self()->gatheredMinerals();
	auto gas = Broodwar->self()->gatheredGas();
	auto workerType = Broodwar->self()->getRace().getWorker();

	for (auto& wb : workerBuildings)
	{
		if (minerals >= workerType.mineralPrice() && wb->isIdle()) {
			wb->train(workerType);
			minerals -= workerType.mineralPrice();
		}
		else break;
	}
}

