#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "GameDefines.h"

namespace gameobject{

	class GameObject {
	public:
		virtual ~GameObject(){}
		virtual void ApplyDamage(float damage);
		virtual void Attack(GameObject *target);
		virtual void update(float dt){}
		Deities GetDeity();
		void SetDeity(Deities deity);
		cocos2d::Sprite *GetSprite();
		void SetHealth(float health);
		float GetHealth();
	protected:
		float m_fHealth;
		Deities m_Deity;
		float m_fAttackValue;
		cocos2d::Sprite *m_Sprite;
	};

}

#endif