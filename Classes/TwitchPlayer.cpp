#include "TwitchPlayer.h"


std::shared_ptr<TwitchPlayer> TwitchPlayer::create()
{
	//create our instance to be returned
	std::shared_ptr<TwitchPlayer> pRet(new TwitchPlayer());
	//set up default values 

	if (pRet->init())
	{
		//instance = pRet;
		return pRet;
	}
	return NULL;
}

std::shared_ptr<TwitchPlayer> TwitchPlayer::create(shared_ptr<string> pName, Deities pSavior)
{
	//create our instance to be returned
	std::shared_ptr<TwitchPlayer> pRet(new TwitchPlayer());

	pRet->setName(pName);
	pRet->setDiety(pSavior);
	//set up default values 

	if (pRet->init())
	{
		//instance = pRet;
		return pRet;
	}
	return NULL;
}


void TwitchPlayer::onNotify(cocos2d::Node* node, cocos2d::EventCustom* event){

}


void TwitchPlayer::setName(shared_ptr<string> name)
{

	this->name = name;
	//twitch players name should not be longer than 12 characters
	if (this->name->length() > 25)
	{
		this->name->resize(25);
	}
}

void TwitchPlayer::setDiety(Deities pSavior)
{
	this->savior = pSavior;
}

bool TwitchPlayer::init()
{


	return true;
}

TwitchPlayer::TwitchPlayer()
{

}

TwitchPlayer::~TwitchPlayer()
{
	//cleanup here
}

