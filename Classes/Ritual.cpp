#include "Ritual.h"
#include "WorldManager.h"

namespace ritual{
	Ritual::Ritual(Deities deity)
	{
		m_Deity = deity;
		if (deity == HELIX)
		{
			m_Sprite = cocos2d::Sprite::create("helix.png");
		}			
		else
		{
			m_Sprite = cocos2d::Sprite::create("dome.png");
		}

		m_fHealth = 100;
				
		Init();
	}	

	void Ritual::Init()
	{
		Animate();
	}

	void Ritual::Animate()
	{
		// do things here like setTag(), setPosition(), any custom logic.
		auto rotateCW = cocos2d::RotateBy::create(0.50f * ACTION_SPEED, 40.0f);
		auto rotateCCW = rotateCW->reverse();
		auto wobble = cocos2d::Sequence::create(rotateCW, rotateCCW, rotateCCW->clone(), rotateCW->clone(), nullptr);

		m_Sprite->runAction(cocos2d::RepeatForever::create(wobble));
	}

	void Ritual::ApplyDamage(float damage)
	{
		m_fHealth -= damage;
	}

	void Ritual::Update(float dt)
	{
		if (m_fHealth < 0)
		{
			WorldManager::getInstance()->GetGameBoard()->removeChild(m_Sprite);
		}
	}

}
