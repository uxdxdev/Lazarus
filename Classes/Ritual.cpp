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
		m_eObjectType = RITUAL;
		m_eState = ALIVE;
		m_Sprite->setAnchorPoint(Vec2(0.5f, 0.5f));
		m_ParticleSystem = cocos2d::CCParticleSystemQuad::create("Flower.plist");		
		
		WorldManager::getInstance()->GetGameBoard()->addChild(m_ParticleSystem, 2);
		m_ParticleSystem->stopSystem(); // turn off particle system
		m_bIsParticleOn = false;
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
			// Reduce this sides ritual value
			//WorldManager::getInstance()->GetGameBoard()->removeChild(m_Sprite);

		}
				
		// Particle systems
		if (m_Deity == DOME && WorldManager::getInstance()->getTwitchModel()->getBarCurrent(RITUALBARDOME) == WorldManager::getInstance()->getTwitchModel()->getBarMax(RITUALBARDOME) ||
			m_Deity == HELIX && WorldManager::getInstance()->getTwitchModel()->getBarCurrent(RITUALBARHELIX) == WorldManager::getInstance()->getTwitchModel()->getBarMax(RITUALBARHELIX))
		{
			if (!m_bIsParticleOn)
			{
				CCLOG("Particles on for ritual");
				m_ParticleSystem->resetSystem();
				m_bIsParticleOn = true;
			}
		}
		else
		{
			if (m_bIsParticleOn)
			{
				CCLOG("Particles off for ritual");
				m_ParticleSystem->stopSystem();
				m_bIsParticleOn = false;
			}
		}		
	}
}
