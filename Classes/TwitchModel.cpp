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


void TwitchModel::onNotify(cocos2d::Node* node, cocos2d::EventCustom* event){
	//handle messages here
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
	shared_ptr<TwitchPlayer> pTwitch = TwitchPlayer::create(pname, pSavior);
	playerList.push_back(pTwitch);

	return pTwitch;
}



bool TwitchModel::init()
{
	//chantBarDome
	//chantBarHelix.current = 


	return true;
}

TwitchModel::TwitchModel()
{

}

TwitchModel::~TwitchModel()
{
	//cleanup here
}

