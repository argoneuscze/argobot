#include "BotModule.h"

BotModule::BotModule()
	: workerManager{unitManager}
{
}

BotModule::~BotModule()
{
}

void BotModule::onStart()
{
}

void BotModule::onEnd(bool isWinner)
{
}

void BotModule::onFrame()
{
	buildingManager.onFrame();
}

void BotModule::onSendText(std::string text)
{
}

void BotModule::onReceiveText(BWAPI::Player player, std::string text)
{
}

void BotModule::onPlayerLeft(BWAPI::Player player)
{
}

void BotModule::onNukeDetect(BWAPI::Position target)
{
}

void BotModule::onUnitDiscover(BWAPI::Unit unit)
{
}

void BotModule::onUnitEvade(BWAPI::Unit unit)
{
}

void BotModule::onUnitShow(BWAPI::Unit unit)
{
}

void BotModule::onUnitHide(BWAPI::Unit unit)
{
}

void BotModule::onUnitCreate(BWAPI::Unit unit)
{
}

void BotModule::onUnitDestroy(BWAPI::Unit unit)
{
}

void BotModule::onUnitMorph(BWAPI::Unit unit)
{
}

void BotModule::onUnitRenegade(BWAPI::Unit unit)
{
}

void BotModule::onSaveGame(std::string gameName)
{
}

void BotModule::onUnitComplete(BWAPI::Unit unit)
{
	unitManager.onUnitComplete(unit);
	buildingManager.onUnitComplete(unit);
	workerManager.onUnitComplete(unit);
}

