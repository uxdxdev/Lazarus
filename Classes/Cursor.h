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
	void setDeity(Deities deity);

	void move(Directions direction);
	void MoveTarget(Directions direction);

	void randomeMove();
	void toggleMovement() { m_bMoving = true; }
	bool isMoving() { return m_bMoving; }
	bool canMove(Directions direction);

private:
	bool m_bMoving;
	Deities m_deity;

};

#endif // _CURSOR_
