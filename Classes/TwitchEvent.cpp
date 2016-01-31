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
	pRet->playerName = shared_ptr<string>(new string(username.c_str()));

	if (pRet->init())
	{
		//instance = pRet;
		return pRet;
	}
	return NULL;
}

TwitchEventType TwitchEvent::GetEventType()
{
	return eventType;
}

shared_ptr<string> TwitchEvent::GetUsername()
{
	return playerName;
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

