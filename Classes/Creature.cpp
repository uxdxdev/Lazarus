#include "Creature.h"

Creature::Creature(Deities deity)
{
	m_Deity = deity;
	if (deity == HELIX)
	{
		m_Sprite = cocos2d::Sprite::create("creatureHelix.png");
	}
	else
	{
		m_Sprite = cocos2d::Sprite::create("creatureDome.png");
	}

	m_fHealth = 100;

	Init();
}

void Creature::Init()
{

}

void Creature::Update(float dt)
{

}