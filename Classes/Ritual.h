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
	};

}
#endif // _RITUAL_
