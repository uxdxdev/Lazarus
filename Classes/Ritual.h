#ifndef _RITUAL_
#define _RITUAL_

#include "cocos2d.h"

typedef enum e_Deities {
	HELIX,
	DOME
} Deities;

class Ritual : public cocos2d::Sprite
{
public:
	Ritual();
	~Ritual();
	static Ritual* create(Deities deity);

	void initOptions();

	void addEvents();
private:

};

#endif // _RITUAL_
