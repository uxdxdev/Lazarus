#include "BoardLayer.h"

#include "WorldManager.h"
#include "Creature.h"
#include "Tower.h"

USING_NS_CC;

BoardLayer::~BoardLayer()
{	
}

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

	WorldManager::getInstance()->SetGameBoard(this);
	// Register with the world manager
	WorldManager::getInstance()->addObserver(this);

	Size boardSize =_spBoard->getContentSize();

	// Helix ritual
	std::shared_ptr<ritual::Ritual> ritualHelix (new ritual::Ritual(HELIX));
	helixRitual = std::move(ritualHelix);
	WorldManager::getInstance()->registerWithWorldManger(helixRitual);
	helixRitual->GetSprite()->setPosition(
		(screenSize.width - boardSize.width + helixRitual->GetSprite()->getContentSize().width) * 0.55,
		screenSize.height * 0.5);
	helixRitual->GetParticleSystem()->setPosition(helixRitual->GetSprite()->getPosition());
	this->addChild(helixRitual->GetSprite());

	// Dome ritual
	std::shared_ptr<ritual::Ritual> ritualDome(new ritual::Ritual(DOME));
	domeRitual = std::move(ritualDome);
	WorldManager::getInstance()->registerWithWorldManger(domeRitual);
	domeRitual->GetSprite()->setPosition(
		(screenSize.width + boardSize.width - domeRitual->GetSprite()->getContentSize().width) * 0.48,
		screenSize.height * 0.5);
	domeRitual->GetParticleSystem()->setPosition(domeRitual->GetSprite()->getPosition());
	this->addChild(domeRitual->GetSprite());

	helixCursor = Cursor::create(HELIX);
	helixCursor->setDeity(HELIX);
	helixCursor->setPosition(
		helixRitual->GetSprite()->getPositionX() + helixRitual->GetSprite()->getContentSize().width,
		helixRitual->GetSprite()->getPositionY());
	this->addChild(helixCursor, 2);

	domeCursor = Cursor::create(DOME);
	domeCursor->setDeity(DOME);
	domeCursor->setPosition(
		domeRitual->GetSprite()->getPositionX() - domeRitual->GetSprite()->getContentSize().width,
		domeRitual->GetSprite()->getPositionY());
	this->addChild(domeCursor, 2);

	m_bIsCreatureSpawnedHelix = false;
	m_bIsCreatureSpawnedDome = false;

	m_bCanSpawnTowerHelix = true;
	m_bCanSpawnTowerDome = true;
	
	m_iNumberOfTowersSpawnedHelix = 0;
	m_iNumberOfTowersSpawnedDome = 0;
	


	return true;
}

void BoardLayer::SetCreatureSpawned(Deities deity, bool value)
{
	if (deity == HELIX)
	{
		m_bIsCreatureSpawnedHelix = value;
	}
	else if (deity == DOME)
	{
		m_bIsCreatureSpawnedDome = value;
	}
}

void BoardLayer::TowerDestroyed(Deities deity)
{
	if (deity == HELIX)
	{
		m_iNumberOfTowersSpawnedHelix--;
		CCLOG("Helix towers %d", m_iNumberOfTowersSpawnedHelix);
	}
	else if (deity == DOME)
	{
		m_iNumberOfTowersSpawnedDome--;
		CCLOG("Dome towers %d", m_iNumberOfTowersSpawnedDome);
	}
}

Cursor* BoardLayer::GetCursor(Deities deity)
{
	if (deity == HELIX)
	{
		return helixCursor;
	}
	else if (deity == DOME)
	{
		return domeCursor;
	}
}

ritual::Ritual *BoardLayer::GetRitual(Deities deity)
{
	if (deity == HELIX)
	{
		return helixRitual.get();
	}
	else if (deity == DOME)
	{
		return domeRitual.get();
	}
}





void BoardLayer::onNotify(std::shared_ptr<TwitchEvent> tEvent)
{
	WorldManager* worldMan = WorldManager::getInstance();
	if (tEvent->GetEventType() == TwitchEventType::ZAPEVENT)
	{
		CCLOG("BoardLayer ZAPPY ZAP by %s", tEvent->GetUsername()->c_str());
		std::shared_ptr<TwitchPlayer> tPlayer = WorldManager::getInstance()->getTwitchModel()->getPlayer(tEvent->GetUsername());
		if (tPlayer != NULL)
		{
			switch (tPlayer->getDeity())
			{
			case HELIX:
				helixCursor->attack();
				break;
			case DOME:
				domeCursor->attack();
				break;
			default:
				CCLOG("UPEVENT defaulted here on TwitchPlayer deity");
				break;
			}

			
		}
	}

	if (tEvent->GetEventType() == TwitchEventType::UPEVENT)
	{
		CCLOG("BoardLayer TARGET Up by %s", tEvent->GetUsername().get()->c_str());
		std::shared_ptr<TwitchPlayer> tPlayer = WorldManager::getInstance()->getTwitchModel()->getPlayer(tEvent->GetUsername());
		if (tPlayer != NULL)
		{
			switch (tPlayer->getDeity())
			{
			case HELIX:
				helixCursor->move(Directions::UP);
				break;
			case DOME:
				domeCursor->move(Directions::UP);
				break;
			default:
				CCLOG("UPEVENT defaulted here on TwitchPlayer deity");
				break;
			}
		}	
	}

	if (tEvent->GetEventType() == TwitchEventType::DOWNEVENT)
	{
		CCLOG("BoardLayer TARGET Down by %s", tEvent->GetUsername()->c_str());
		std::shared_ptr<TwitchPlayer> tPlayer = WorldManager::getInstance()->getTwitchModel()->getPlayer(tEvent->GetUsername());
		if (tPlayer != NULL)
		{
			switch (tPlayer->getDeity())
			{
			case HELIX:
				helixCursor->move(Directions::DOWN);
				break;
			case DOME:
				domeCursor->move(Directions::DOWN);
				break;
			default:
				CCLOG("DOWNEVENT defaulted here on TwitchPlayer deity");
				break;
			}
		}
	}

	if (tEvent->GetEventType() == TwitchEventType::LEFTEVENT)
	{
		CCLOG("BoardLayer TARGET Left by %s", tEvent->GetUsername()->c_str());
		std::shared_ptr<TwitchPlayer> tPlayer = WorldManager::getInstance()->getTwitchModel()->getPlayer(tEvent->GetUsername());
		if (tPlayer != NULL)
		{
			switch (tPlayer->getDeity())
			{
			case HELIX:
				helixCursor->move(Directions::LEFT);
				break;
			case DOME:
				domeCursor->move(Directions::LEFT);
				break;
			default:
				CCLOG("UPEVENT defaulted here on TwitchPlayer deity");
				break;
			}
		}
	}

	if (tEvent->GetEventType() == TwitchEventType::RIGHTEVENT)
	{
		CCLOG("BoardLayer TARGET Right by %s", tEvent->GetUsername()->c_str());
		std::shared_ptr<TwitchPlayer> tPlayer = WorldManager::getInstance()->getTwitchModel()->getPlayer(tEvent->GetUsername());
		if (tPlayer != NULL)
		{
			switch (tPlayer->getDeity())
			{
			case HELIX:
				helixCursor->move(Directions::RIGHT);
				break;
			case DOME:
				domeCursor->move(Directions::RIGHT);
				break;
			default:
				CCLOG("UPEVENT defaulted here on TwitchPlayer deity");
				break;
			}
		}
	}
	if (tEvent->GetEventType() == TwitchEventType::SPAWNEVENT)
	{
		//check if the spawn bar is full
		shared_ptr<TwitchPlayer> twitchp = worldMan->getTwitchModel()->getPlayer(tEvent->GetUsername());
		if (twitchp != NULL){
			if (twitchp->getDeity() == Deities::HELIX)
			{
				float current, max;
				current = WorldManager::getInstance()->getTwitchModel()->getBarCurrent(SPAWNBARHELIX);
				max = WorldManager::getInstance()->getTwitchModel()->getBarMax(SPAWNBARHELIX);
				if (current == max)
				{
					spawnHelix();
				}				
			}
			else if(twitchp->getDeity() == Deities::DOME)
			{
				float current, max;
				current = WorldManager::getInstance()->getTwitchModel()->getBarCurrent(SPAWNBARDOME);
				max = WorldManager::getInstance()->getTwitchModel()->getBarMax(SPAWNBARDOME);
				if (current == max)
				{
					spawnDome();
				}				
			}
		}
	}
	if (tEvent->GetEventType() == TwitchEventType::TOWEREVENT)
	{
		//check if the spawn bar is full
		shared_ptr<TwitchPlayer> twitchp = worldMan->getTwitchModel()->getPlayer(tEvent->GetUsername());
		if (twitchp != NULL){
			if (twitchp->getDeity() == Deities::HELIX)
			{
				float current, max;
				current = WorldManager::getInstance()->getTwitchModel()->getBarCurrent(TOWERBARHELIX);
				max = WorldManager::getInstance()->getTwitchModel()->getBarMax(TOWERBARHELIX);
				if (current == max)
				{
					TowerHelix();
				}
			}
			else if (twitchp->getDeity() == Deities::DOME)
			{
				float current, max;
				current = WorldManager::getInstance()->getTwitchModel()->getBarCurrent(TOWERBARDOME);
				max = WorldManager::getInstance()->getTwitchModel()->getBarMax(TOWERBARDOME);
				if (current == max)
				{
					TowerDome();
				}
			}
		}
	}
}

void BoardLayer::spawnDome()
{
	if (!m_bIsCreatureSpawnedDome)
	{
		//get cursor position
		//spawn dome 
		std::shared_ptr<Creature> spawned(new Creature(Deities::DOME));
		//spawned->GetSprite()->setPosition(domeRitual->GetSprite()->getPosition());
		this->addChild(spawned->GetSprite());
		//register with world manager
		WorldManager::getInstance()->registerWithWorldManger(spawned);
		m_bIsCreatureSpawnedDome = true;
		WorldManager::getInstance()->getTwitchModel()->setBarCurrent(SPAWNBARDOME, 0.0f);
	}
}
void BoardLayer::spawnHelix()
{
	if (!m_bIsCreatureSpawnedHelix)
	{
		//get cursor position
		//spawn helix
		std::shared_ptr<Creature> spawned(new Creature(Deities::HELIX));
		//spawned->GetSprite()->setPosition(helixRitual->GetSprite()->getPosition());
		this->addChild(spawned->GetSprite());
		//register with world manager
		WorldManager::getInstance()->registerWithWorldManger(spawned);
		m_bIsCreatureSpawnedHelix = true;
		WorldManager::getInstance()->getTwitchModel()->setBarCurrent(SPAWNBARHELIX, 0.0f);
	}	
}

void BoardLayer::TowerDome()
{
	if (m_bCanSpawnTowerDome)
	{
		//get cursor position
		//place tower dome 
		std::shared_ptr<Tower> spawned(new Tower(Deities::DOME));
		spawned->GetSprite()->setPosition(domeCursor->getPosition());
		this->addChild(spawned->GetSprite());
		//register with world manager
		WorldManager::getInstance()->registerWithWorldManger(spawned);
		WorldManager::getInstance()->getTwitchModel()->setBarCurrent(TOWERBARDOME, 0.0f);
		m_iNumberOfTowersSpawnedDome++;
	}
		
}

void BoardLayer::TowerHelix()
{
	if (m_bCanSpawnTowerHelix)
	{
		//get cursor position
		//place tower helix
		//register with world manager
		std::shared_ptr<Tower> spawned(new Tower(Deities::HELIX));
		spawned->GetSprite()->setPosition(helixCursor->getPosition());
		this->addChild(spawned->GetSprite());
		//register with world manager
		WorldManager::getInstance()->registerWithWorldManger(spawned);
		WorldManager::getInstance()->getTwitchModel()->setBarCurrent(TOWERBARHELIX, 0.0f);
		m_iNumberOfTowersSpawnedHelix++;
	}
}

void BoardLayer::update(float dt)
{
	//helixCursor->randomeMove();
	//domeCursor->randomeMove();

	//collisions
	WorldManager::getInstance()->updateGameObjects(dt);
	
	if (m_iNumberOfTowersSpawnedHelix > 2)
	{
		m_bCanSpawnTowerHelix = false;
	}
	else
	{
		m_bCanSpawnTowerHelix = true;
	}

	if (m_iNumberOfTowersSpawnedDome > 2)
	{
		m_bCanSpawnTowerDome = false;
	}
	else
	{
		m_bCanSpawnTowerDome = true;
	}

	
	



}