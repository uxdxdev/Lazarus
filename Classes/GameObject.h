#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "GameDefines.h"

namespace gameobject{

	class GameObject : public cocos2d::Sprite{
	public:
		virtual ~GameObject(){}
		virtual void ApplyDamage(float damage);
		virtual void Attack(GameObject *target);
		Deities GetDeity();
	private:
		float m_fHealth;
		Deities m_Deity;
		float m_fAttackValue;
	};

}

#endif