#include "BoardLayer.h"

USING_NS_CC;

bool BoardLayer::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size screenSize = Director::getInstance()->getVisibleSize();

	_spBoard = Sprite::create("board.png");
	if (_spBoard) 
	{
		_spBoard->setPosition(screenSize.width * 0.5, screenSize.height * 0.5);
		this->addChild(_spBoard);
	}

	return true;
}