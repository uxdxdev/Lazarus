#include "GameObject.h"

namespace gameobject{
	void GameObject::ApplyDamage(float damage)
	{
		m_fHealth -= damage;
	}

	Deities GameObject::GetDeity()
	{
		return m_Deity;
	}

	void GameObject::SetDeity(Deities deity)
	{
		m_Deity = deity;
	}

	void GameObject::SetTarget(GameObject *target)
	{
		m_pTarget = target;

		// Move to target
		auto moveAction = cocos2d::MoveTo::create(4.0f * ACTION_SPEED, m_pTarget->GetSprite()->getPosition());
		auto easeInOut = cocos2d::EaseInOut::create(moveAction->clone(), 2.0f);
		auto delay = cocos2d::DelayTime::create(4.0f * ACTION_SPEED);
		auto attack = cocos2d::CallFunc::create(std::bind(&GameObject::Attack, this));
		auto sequence = cocos2d::Sequence::create(easeInOut, delay, attack, nullptr);

		m_Sprite->runAction(sequence);
	}


	cocos2d::Sprite *GameObject::GetSprite()
	{
		return m_Sprite;
	}


	void GameObject::Attack()
	{
		m_pTarget->ApplyDamage(m_fAttackValue);
	}
}