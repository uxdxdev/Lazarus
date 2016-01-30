#ifndef _CURSOR_
#define _CURSOR_

#include "Ritual.h"

typedef enum e_Directions {
	UP,
	DOWN,
	LEFT,
	RIGHT
} Directions;

class Cursor : public cocos2d::Sprite
{
public:
	Cursor();
	~Cursor();
	static Cursor* create(Deities deity);

	void initOptions();

	void addEvents();

	void move(Directions direction);
	void randomeMove();
	void toggleMovement() { m_bMoving = !m_bMoving; }
	bool isMoving() { return m_bMoving; }

private:
	bool m_bMoving = false;

};

#endif // _CURSOR_
