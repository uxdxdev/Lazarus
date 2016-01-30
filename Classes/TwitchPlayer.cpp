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


void TwitchPlayer::onNotify(cocos2d::Node* node, cocos2d::EventCustom* event){

}


void TwitchPlayer::setName(string name)
{

	this->name = name;
	//twitch players name should not be longer than 12 characters
	if (this->name.length() > 25)
	{
		this->name.resize(25);
	}
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
