#ifndef _CURSOR_
#define _CURSOR_

#include "Ritual.h"

class Cursor : public cocos2d::Sprite
{
public:
	Cursor();
	~Cursor();
	static Cursor* create(Deities deity);

	void initOptions();

	void addEvents();
private:

};

#endif // _CURSOR_
