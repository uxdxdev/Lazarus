#include "Tower.h"
#include "WorldManager.h"

Tower::Tower(Deities deity)
{
	m_Deity = deity;
	if (deity == HELIX)
	{
		m_Sprite = cocos2d::Sprite::create("helixTower.png");
	}
	else
	{
		m_Sprite = cocos2d::Sprite::create("domeTower.png");
	}
	m_fHealth = 100;
	m_eState = ALIVE;
	m_eObjectType = TOWER;
}

void Tower::Update(float dt)
{
	if (m_fHealth <= 0)
	{
		m_Sprite->getParent()->removeChild(m_Sprite);
		m_eState = DEAD;
		WorldManager::getInstance()->GetGameBoard()->TowerDestroyed(m_Deity);
	}
}