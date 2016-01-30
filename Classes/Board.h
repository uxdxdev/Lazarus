#ifndef _BOARD_
#define _BOARD_

#include "cocos2d.h"

using namespace cocos2d;

class Board : public cocos2d::Layer
{
public:
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	CREATE_FUNC(Board);

private:
	Sprite* _spBoard;
};

#endif