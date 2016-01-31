#include "TwitchModel.h"


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
		registerPlayer(newEvent->GetUsername(), Deities::HELIX);
		CCLOG("Player : %s registered with DOME", newEvent->GetUsername()->c_str());
		break;
	default:
		break;
	}
}



shared_ptr<TwitchPlayer> TwitchModel::getPlayer(shared_ptr<string> pname){

	for (int i = 0; i < playerList.size(); i++)
	{
		if (playerList.at(i)->getName()->compare(pname->c_str()))
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
		
		
	}
	
	

	return playerCheck;
}

void TwitchModel::initBars()
{
	
	spawnBarHelix.current = 0;
	spawnBarHelix.max = 20;
	spawnBarHelix.saviour = HELIX;
	towerBarHelix.current = 0;
	towerBarHelix.max = 20;
	towerBarHelix.saviour = HELIX;
	ritualBarHelix.current = 0;
	ritualBarHelix.max = 500;
	ritualBarHelix.saviour = HELIX;
	spawnBarDome.current = 0;
	spawnBarDome.max = 20;
	spawnBarDome.saviour = DOME;
	towerBarDome.current = 0;
	towerBarDome.max = 20;
	towerBarDome.saviour = DOME;
	ritualBarDome.current = 0;
	ritualBarDome.max = 500;
	ritualBarDome.saviour = DOME;

}


topbar TwitchModel::getBar(BarType bartype){

	switch (bartype)
	{
	case SPAWNBARHELIX:
		return spawnBarHelix;
		break;

	case TOWERBARHELIX:
		return towerBarHelix;
		break;

	case RITUALBARHELIX:
		return ritualBarHelix;
		break;
	case SPAWNBARDOME:
		return spawnBarDome; 
		break;
	case TOWERBARDOME:
		return towerBarDome;
		break;
	case RITUALBARDOME:
		return ritualBarDome;
		break;
	default:
		
		break;
	}
}
unsigned int TwitchModel::getBarCurrent(BarType bartype){
	return getBar(bartype).current;
}
unsigned int TwitchModel::getBarMax(BarType bartype){
	return getBar(bartype).max;
}
void TwitchModel::setBarCurrent(BarType bartype, unsigned int currentset){
	
	getBar(bartype).setCurrent(currentset);
}
void TwitchModel::setBarMax(BarType bartype, unsigned int maxset){
	getBar(bartype).setMax(maxset);
}

bool TwitchModel::init()
{
	//chantBarDome
	//chantBarHelix.current = 
	initBars();

	return true;
}



TwitchModel::TwitchModel()
{

}

TwitchModel::~TwitchModel()
{
	//cleanup here
}

