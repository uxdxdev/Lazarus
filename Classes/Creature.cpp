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

void Creature::MoveToTarget()
{
	// Move to target
	auto moveAction = cocos2d::MoveTo::create(4.0f * ACTION_SPEED, m_pTarget->GetSprite()->getPosition());
	auto easeInOut = cocos2d::EaseInOut::create(moveAction->clone(), 2.0f);
	auto delay = cocos2d::DelayTime::create(4.0f * ACTION_SPEED);
	auto attack = cocos2d::CallFunc::create(std::bind(&Creature::Attack, this));
	auto sequence = cocos2d::Sequence::create(easeInOut, delay, attack, nullptr);

	m_Sprite->runAction(sequence);
}

void Creature::Attack()
{
	m_pTarget->ApplyDamage(m_fAttackValue);
}