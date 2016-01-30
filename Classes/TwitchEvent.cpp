#include "TwitchEvent.h"


std::shared_ptr<TwitchEvent> TwitchEvent::create()
{
	//create our instance to be returned
	std::shared_ptr<TwitchEvent> pRet(new TwitchEvent());
	//set up default values 

	if (pRet->init())
	{
		//instance = pRet;
		return pRet;
	}
	return NULL;
}


std::shared_ptr<TwitchEvent> TwitchEvent::create(TwitchEventType tevent, std::string username)
{
	//create our instance to be returned
	std::shared_ptr<TwitchEvent> pRet(new TwitchEvent());
	//set up default values 
	pRet->eventType = tevent;
	pRet->playerName = username;

	if (pRet->init())
	{
		//instance = pRet;
		return pRet;
	}
	return NULL;
}



bool TwitchEvent::init()
{
	//chantBarDome
	//chantBarHelix.current = 


	return true;
}

TwitchEvent::TwitchEvent()
{

}

TwitchEvent::~TwitchEvent()
{
	//cleanup here
}

