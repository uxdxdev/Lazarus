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

	void GameObject::Attack(GameObject *target, float value)
	{
		target->ApplyDamage(value);
	}
}