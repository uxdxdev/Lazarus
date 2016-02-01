#ifndef _RITUAL_
#define _RITUAL_

#include "GameDefines.h"
#include "GameObject.h"

namespace ritual{

	class Ritual : public gameobject::GameObject
	{
	public:
		Ritual(Deities deity);		
		void Init();
		void Ritual::Animate();
		void ApplyDamage(float damage);
		void Update(float dt);
		cocos2d::CCParticleSystemQuad* GetParticleSystem(){ return m_ParticleSystem; }
	private:
		cocos2d::CCParticleSystemQuad* m_ParticleSystem;
		bool m_bIsParticleOn;
	};

}
#endif // _RITUAL_
