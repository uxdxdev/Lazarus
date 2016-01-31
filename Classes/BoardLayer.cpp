#include "BoardLayer.h"

#include "WorldManager.h"

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
	helixRitual = new ritual::Ritual(HELIX);
	helixRitual->GetSprite()->setPosition(
		(screenSize.width - boardSize.width + helixRitual->GetSprite()->getContentSize().width) * 0.55,
		screenSize.height * 0.5);
	this->addChild(helixRitual->GetSprite());

	domeRitual = new ritual::Ritual(DOME);
	domeRitual->GetSprite()->setPosition(
		(screenSize.width + boardSize.width - domeRitual->GetSprite()->getContentSize().width) * 0.48,
		screenSize.height * 0.5);
	this->addChild(domeRitual->GetSprite());

	helixCursor = Cursor::create(HELIX);
	helixCursor->setDeity(HELIX);
	helixCursor->setPosition(
		helixRitual->GetSprite()->getPositionX() + helixRitual->GetSprite()->getContentSize().width,
		helixRitual->GetSprite()->getPositionY());
	this->addChild(helixCursor);

	domeCursor = Cursor::create(DOME);
	domeCursor->setDeity(DOME);
	domeCursor->setPosition(
		domeRitual->GetSprite()->getPositionX() - domeRitual->GetSprite()->getContentSize().width,
		domeRitual->GetSprite()->getPositionY());
	this->addChild(domeCursor);


	// Register with the world manager
	
	WorldManager::getInstance()->addObserver(this);


	return true;
}

void BoardLayer::onNotify(std::shared_ptr<TwitchEvent> tEvent)
{
	WorldManager* worldMan = WorldManager::getInstance();
	if (tEvent->GetEventType() == TwitchEventType::ZAPEVENT)
	{
		CCLOG("BoardLayer ZAPPY ZAP by %s", tEvent->GetUsername()->c_str());
		helixCursor->attack();	
		domeCursor->attack();
	}

	if (tEvent->GetEventType() == TwitchEventType::UPEVENT)
	{
		CCLOG("BoardLayer TARGET Up by %s", tEvent->GetUsername()->c_str());
		helixCursor->move(Directions::UP);
		domeCursor->move(Directions::UP);
	}

	if (tEvent->GetEventType() == TwitchEventType::DOWNEVENT)
	{
		CCLOG("BoardLayer TARGET Down by %s", tEvent->GetUsername()->c_str());
		helixCursor->move(Directions::DOWN);
		domeCursor->move(Directions::DOWN);
	}

	if (tEvent->GetEventType() == TwitchEventType::LEFTEVENT)
	{
		CCLOG("BoardLayer TARGET Left by %s", tEvent->GetUsername()->c_str());
		helixCursor->move(Directions::LEFT);
		domeCursor->move(Directions::LEFT);
	}

	if (tEvent->GetEventType() == TwitchEventType::RIGHTEVENT)
	{
		CCLOG("BoardLayer TARGET Right by %s", tEvent->GetUsername()->c_str());
		helixCursor->move(Directions::RIGHT);
		domeCursor->move(Directions::RIGHT);
	}
	if (tEvent->GetEventType() == TwitchEventType::SPAWNEVENT)
	{
		//check if the spawn bar is full
		shared_ptr<TwitchPlayer> twitchp = worldMan->getTwitchModel()->getPlayer(tEvent->GetUsername());
		if (twitchp != NULL){
			if (twitchp->getDiety() == Deities::HELIX)
			{
				spawnDome();
			}
			else if(twitchp->getDiety() == Deities::DOME)
			{
				spawnHelix();
			}
		}
	}
	if (tEvent->GetEventType() == TwitchEventType::TOWEREVENT)
	{
		//check if the spawn bar is full
		shared_ptr<TwitchPlayer> twitchp = worldMan->getTwitchModel()->getPlayer(tEvent->GetUsername());
		if (twitchp != NULL){
			if (twitchp->getDiety() == Deities::HELIX)
			{
				TowerHelix();
			}
			else if (twitchp->getDiety() == Deities::DOME)
			{
				TowerDome();
			}
		}
	}
}

void BoardLayer::spawnDome()
{
	//get cursor position
	//spawn dome 
	//register with world manager

}
void BoardLayer::spawnHelix()
{
	//get cursor position
	//spawn helix
	//register with world manager
}

void BoardLayer::TowerDome()
{
	//get cursor position
	//place tower dome 
	//register with world manager
}

void BoardLayer::TowerHelix()
{
	//get cursor position
	//place tower helix
	//register with world manager
}

void BoardLayer::update(float dt)
{
	//helixCursor->randomeMove();
	//domeCursor->randomeMove();

	//collisions

}