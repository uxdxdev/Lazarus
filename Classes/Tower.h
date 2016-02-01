#ifndef TOWER_H_
#define TOWER_H_

#include "GameObject.h"


class Tower : public gameobject::GameObject{
public:
	Tower::Tower(Deities deity);
	void Update(float dt);
};


#endif