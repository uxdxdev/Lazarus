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

