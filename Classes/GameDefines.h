#ifndef GAME_DEFINES_H
#define GAME_DEFINES_H

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

//server defines
#define SERVER_URL "irc.twitch.tv"
#define SERVER_PORT "6667"


typedef enum e_Deities {
	HELIX,
	DOME
} Deities;


typedef struct topbar{


	unsigned int current;
	void setCurrent(unsigned int setcurrent){
		current = setcurrent;
	}
	unsigned int max;
	void setMax(unsigned int setMax){
		max = setMax;
	}
	void setsaviour(Deities setsaviour){
		saviour = setsaviour;
	}
	Deities saviour;
}topbar;


typedef enum e_Directions {
	UP,
	DOWN,
	LEFT,
	RIGHT
} Directions;

typedef enum e_TwitchEvents {
	
	SPAWNEVENT,
	TOWEREVENT,
	CHANTEVENT,
	ZAPEVENT,
	UPEVENT,
	DOWNEVENT,
	LEFTEVENT,
	RIGHTEVENT,
	PRAISEHELIX, //register helix
	PRAISEDOME   //register dome

} TwitchEventType;

typedef enum e_BarTypes {

	SPAWNBARHELIX,
	TOWERBARHELIX,
	RITUALBARHELIX,
	SPAWNBARDOME,
	TOWERBARDOME,
	RITUALBARDOME

} BarType;


#endif