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

	Size boardSize =_spBoard->getContentSize();
	helixRitual = Ritual::create(HELIX);
	helixRitual->setPosition(
		(screenSize.width - boardSize.width + helixRitual->getContentSize().width) * 0.55,
		screenSize.height * 0.5);
	this->addChild(helixRitual);

	domeRitual = Ritual::create(DOME);
	domeRitual->setPosition(
		(screenSize.width + boardSize.width - domeRitual->getContentSize().width) * 0.48,
		screenSize.height * 0.5);
	this->addChild(domeRitual);

	helixCursor = Cursor::create(HELIX);
	helixCursor->setPosition(
		helixRitual->getPositionX() + helixRitual->getContentSize().width,
		helixRitual->getPositionY());
	this->addChild(helixCursor);

	domeCursor = Cursor::create(DOME);
	domeCursor->setPosition(
		domeRitual->getPositionX() - domeRitual->getContentSize().width,
		domeRitual->getPositionY());
	this->addChild(domeCursor);
	return true;
}

void BoardLayer::update(float dt)
{
	helixCursor->randomeMove();
	domeCursor->randomeMove();
}