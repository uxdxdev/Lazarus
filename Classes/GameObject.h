#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <memory>

#include "GameDefines.h"

namespace gameobject{

	class GameObject {
	public:
		virtual ~GameObject(){}
		virtual void ApplyDamage(float damage);
		virtual void Attack();
		Deities GetDeity();
		void SetDeity(Deities deity);
		cocos2d::Sprite *GetSprite();
		void SetHealth(float health);
		void SetTarget(GameObject *target);
		float GetHealth();
	protected:
		float m_fHealth;
		Deities m_Deity;
		float m_fAttackValue;
		cocos2d::Sprite *m_Sprite;
		GameObject *m_pTarget;
	};

}

#endif