#include "Creature.h"
#include "WorldManager.h"

Creature::Creature(Deities deity)
{
	m_Deity = deity;
	if (deity == HELIX)
	{
		m_Sprite = cocos2d::Sprite::create("helixCreature.png");
	}
	else
	{
		m_Sprite = cocos2d::Sprite::create("domeCreature.png");
	}
	m_fHealth = 100;
	m_fAttackValue = 100;
	m_eState = ALIVE;
	m_eObjectType = CREATURE;
	m_pTarget = nullptr;
	m_Sprite->setPosition(WorldManager::getInstance()->GetGameBoard()->GetCursor(m_Deity)->getPosition());

	Init();
}

void Creature::Init()
{
	float smallestDistance = 99999;	
	for (int i = 0; i < WorldManager::getInstance()->getGameObects().size(); i++)
	{
		float xDist = (WorldManager::getInstance()->getGameObects().at(i)->GetSprite()->getPositionX() - m_Sprite->getPositionX());
		float yDist = (WorldManager::getInstance()->getGameObects().at(i)->GetSprite()->getPositionY() - m_Sprite->getPositionY());
		float distance = sqrt((xDist * xDist) + (yDist * yDist));

		//float distance = cocos2d::ccpDistance(WorldManager::getInstance()->getGameObects().at(i)->GetSprite()->getPosition(), m_Sprite->getPosition());
		if (distance < smallestDistance && WorldManager::getInstance()->getGameObects().at(i)->GetDeity() != m_Deity && WorldManager::getInstance()->getGameObects().at(i)->GetObjectType() != CREATURE)
		{
			m_pTarget = WorldManager::getInstance()->getGameObects().at(i).get();
			smallestDistance = distance;
		}
	}
	
	m_Sprite->setScale(0.1f, 0.1f);
	auto growAction = cocos2d::ScaleTo::create(0.5f * ACTION_SPEED, 0.5f);
	m_Sprite->runAction(growAction);
	MoveToTarget();
}

void Creature::Update(float dt)
{	
	if (m_pTarget != nullptr)
	{
		if (m_Sprite->getBoundingBox().intersectsRect(m_pTarget->GetSprite()->getBoundingBox()))
		{
			Attack();
			m_Sprite->getParent()->removeChild(m_Sprite); // kill this creature
			m_eState = DEAD;
			WorldManager::getInstance()->GetGameBoard()->SetCreatureSpawned(m_Deity, false);
			if (m_pTarget->GetObjectType() == RITUAL)
			{
				if (m_Deity == HELIX)
				{
					WorldManager::getInstance()->getTwitchModel()->setBarCurrent(RITUALBARDOME, 0.0f);
				}
				else if (m_Deity == DOME)
				{
					WorldManager::getInstance()->getTwitchModel()->setBarCurrent(RITUALBARHELIX, 0.0f);
				}				
			}
		}
	}
}

void Creature::MoveToTarget()
{
	if (m_pTarget != nullptr)
	{
		// Move to target
		auto moveAction = cocos2d::MoveTo::create(20.0f * ACTION_SPEED, m_pTarget->GetSprite()->getPosition());
		auto easeInOut = cocos2d::EaseInOut::create(moveAction->clone(), 2.0f);
		//auto delay = cocos2d::DelayTime::create(4.0f * ACTION_SPEED);
		//auto attack = cocos2d::CallFunc::create(std::bind(&Creature::Attack, this));
		auto sequence = cocos2d::Sequence::create(easeInOut, nullptr);

		m_Sprite->runAction(sequence);
	}
}

void Creature::Attack()
{
	CCLOG("Creature attacked!");
	m_pTarget->ApplyDamage(m_fAttackValue);
}