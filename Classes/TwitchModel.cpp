#include "TwitchModel.h"
#include "WorldManager.h"


std::shared_ptr<TwitchModel> TwitchModel::create()
{
	//create our instance to be returned
	std::shared_ptr<TwitchModel> pRet(new TwitchModel());
	//set up default values 

	if (pRet->init())
	{
		//instance = pRet;
		return pRet;
	}
	return NULL;
}


void TwitchModel::onNotify(std::shared_ptr<TwitchEvent> tEvent){
	//handle messages here
	std::shared_ptr<TwitchEvent> newEvent = tEvent;

	switch (newEvent->GetEventType()){
	case PRAISEHELIX:
		registerPlayer(newEvent->GetUsername(), Deities::HELIX);
		CCLOG("Player : %s registered with HELIX", newEvent->GetUsername()->c_str());
		break;
	case PRAISEDOME:
		registerPlayer(newEvent->GetUsername(), Deities::DOME);
		CCLOG("Player : %s registered with DOME", newEvent->GetUsername()->c_str());
		break;
	case CHANTEVENT:
		increaseBar(CHANTEVENT, newEvent->GetUsername());
		break;
	case TOWEREVENT:
		increaseBar(TOWEREVENT, newEvent->GetUsername());
		break;
	case ZAPEVENT:
		increaseBar(ZAPEVENT, newEvent->GetUsername());
		break;
	case SPAWNEVENT:
		increaseBar(SPAWNEVENT, newEvent->GetUsername());
		break;
	default:
		break;
	}
}



shared_ptr<TwitchPlayer> TwitchModel::getPlayer(shared_ptr<string> pname){

	for (int i = 0; i < playerList.size(); i++)
	{
		string playerString = *(playerList.at(i)->getName());
		if (playerString == *pname)
		{
			return playerList.at(i);
		}
	}

	return NULL;

}

shared_ptr<TwitchPlayer> TwitchModel::registerPlayer(shared_ptr<string> pname, Deities pSavior)
{
	shared_ptr<TwitchPlayer> playerCheck = getPlayer(pname);
	if (playerCheck == NULL)
	{
		playerCheck = TwitchPlayer::create(pname, pSavior);
		playerList.push_back(playerCheck);

		if (pSavior == HELIX)
		{
			m_iHelixPlayers++;
		}
		else if (pSavior == DOME)
		{
			m_iDomePlayers++;
		}
		
		
	}
	
	return playerCheck;
}

void TwitchModel::initBars()
{
	zapBarHelix.current = 0.f;
	zapBarHelix.max = ZAP_MAX;
	zapBarHelix.saviour = HELIX;
	spawnBarHelix.current = 0.f;
	spawnBarHelix.max = SPAWN_MAX;
	spawnBarHelix.saviour = HELIX;
	towerBarHelix.current = 0.f;
	towerBarHelix.max = TOWER_MAX;
	towerBarHelix.saviour = HELIX;
	ritualBarHelix.current = 0.f;
	ritualBarHelix.max = RITUAL_MAX;
	ritualBarHelix.saviour = HELIX;

	zapBarDome.current = 0.f;
	zapBarDome.max = ZAP_MAX;
	zapBarDome.saviour = DOME;
	spawnBarDome.current = 0.f;
	spawnBarDome.max = SPAWN_MAX;
	spawnBarDome.saviour = DOME;
	towerBarDome.current = 0.f;
	towerBarDome.max = TOWER_MAX;
	towerBarDome.saviour = DOME;
	ritualBarDome.current = 0.f;
	ritualBarDome.max = RITUAL_MAX;
	ritualBarDome.saviour = DOME;

}


topbar *TwitchModel::getBar(BarType bartype){

	switch (bartype)
	{
	case SPAWNBARHELIX:
		return &spawnBarHelix;
		break;
	case TOWERBARHELIX:
		return &towerBarHelix;
		break;
	case RITUALBARHELIX:
		return &ritualBarHelix;
		break;
	case ZAPBARHELIX:
		return &zapBarHelix;

	case SPAWNBARDOME:
		return &spawnBarDome; 
		break;
	case TOWERBARDOME:
		return &towerBarDome;
		break;
	case RITUALBARDOME:
		return &ritualBarDome;
		break;
	case ZAPBARDOME:
		return &zapBarDome;
	default:
		
		break;
	}
}
float TwitchModel::getBarCurrent(BarType bartype){
	return getBar(bartype)->current;
}
float TwitchModel::getBarMax(BarType bartype){
	return getBar(bartype)->max;
}
void TwitchModel::setBarCurrent(BarType bartype, float currentset){
	
	getBar(bartype)->setCurrent(currentset);
}
void TwitchModel::setBarMax(BarType bartype, float maxset){
	getBar(bartype)->setMax(maxset);
}

bool TwitchModel::init()
{
	//chantBarDome
	//chantBarHelix.current = 
	initBars();

	m_iHelixPlayers = 0;
	m_iDomePlayers = 0;
	return true;
}



TwitchModel::TwitchModel()
{

}

TwitchModel::~TwitchModel()
{
	//cleanup here
}

void TwitchModel::increaseBar(TwitchEventType teType, shared_ptr<string> pname)
{
	std::shared_ptr<TwitchPlayer> tPlayer = WorldManager::getInstance()->getTwitchModel()->getPlayer(pname);
	if (tPlayer != NULL)
	{
		switch (tPlayer->getDeity())
		{
		case HELIX:
			if (teType == CHANTEVENT) {
				if (ritualBarHelix.current < ritualBarHelix.max) {
					ritualBarHelix.current += INPUT_AMOUNT;
					CCLOG("ritualBar Helix up! now %f", ritualBarHelix.current);
				}
			}
			if (teType == TOWEREVENT) {
				if (towerBarHelix.current < towerBarHelix.max) {
					towerBarHelix.current += INPUT_AMOUNT;
					CCLOG("towerbar Helix up! now %f", towerBarHelix.current);
				}
			}
			if (teType == ZAPEVENT) {
				if (zapBarHelix.current < zapBarHelix.max) {
					zapBarHelix.current += INPUT_AMOUNT;
					CCLOG("zapBar Helix up! now %f", zapBarHelix.current);
				}
			}
			if (teType == SPAWNEVENT) {
				if (spawnBarHelix.current < spawnBarHelix.max) {
					spawnBarHelix.current += INPUT_AMOUNT;
					CCLOG("spawnBar Helix up! now %f", spawnBarHelix.current);
				}
			}
			break;
		case DOME:
			if (teType == CHANTEVENT) {
				if (ritualBarDome.current < ritualBarDome.max) {
					ritualBarDome.current += INPUT_AMOUNT;
					CCLOG("ritualBar Dome up!");
				}
			}
			if (teType == TOWEREVENT) {
				if (towerBarDome.current < towerBarDome.max){
					towerBarDome.current += INPUT_AMOUNT;
					CCLOG("towerBar Dome up!");
				}
			}
			if (teType == ZAPEVENT) {
				if (zapBarDome.current < zapBarDome.max) {
					zapBarDome.current += INPUT_AMOUNT;
					CCLOG("zapBar Dome up!");
				}
			}
			if (teType == SPAWNEVENT) {
				if (spawnBarDome.current < spawnBarDome.max) {
					spawnBarDome.current += INPUT_AMOUNT;
					CCLOG("spawnBar Helix up!");
				}
			}
			break;
		}
	}
}