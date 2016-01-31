#ifndef CREATURE_H_
#define CREATURE_H_

#include "GameObject.h"

class Creature : public gameobject::GameObject{
public:
	Creature(Deities deity);
	void Init();
	void Update(float dt);
};

#endif