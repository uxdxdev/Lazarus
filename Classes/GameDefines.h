#include "cocos2d.h"

typedef struct LinePointJames
{
	cocos2d::Vec2 start;
	cocos2d::Vec2 end;
	float r, g, b, a;
} LinePointJames;

// multiplier for the speed of all functions
#define ACTION_SPEED 1.0f
#define CURSOR_DISPLACEMENT 10.0f

