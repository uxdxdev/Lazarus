#include "Creature.h"

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

	Init();
}

void Creature::Init()
{

}

void Creature::Update(float dt)
{

}