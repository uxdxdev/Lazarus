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


	cocos2d::Sprite *GameObject::GetSprite()
	{
		return m_Sprite;
	}


	void GameObject::Attack(GameObject *target)
	{
		target->ApplyDamage(m_fAttackValue);
	}
}