#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <memory>

#include "GameDefines.h"

namespace gameobject{

	class GameObject {
	public:
		virtual ~GameObject(){}
		virtual void ApplyDamage(float damage);
				
		virtual void Update(float dt){}

		virtual void SetDeity(Deities deity);
		virtual Deities GetDeity();
		
		virtual void SetHealth(float health);
		virtual float GetHealth();

		virtual void SetTarget(GameObject *target);
		virtual GameObject *GetTarget();

		virtual cocos2d::Sprite *GetSprite();
		virtual State GetState();

		virtual ObjectType GetObjectType();

	protected:
		float m_fHealth;
		Deities m_Deity;
		float m_fAttackValue;
		GameObject *m_pTarget;
		cocos2d::Sprite *m_Sprite;
		State m_eState;
		ObjectType m_eObjectType;
	};

}

#endif