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
#define CURSOR_DISPLACEMENT 20.0f

//server defines
#define SERVER_URL "irc.twitch.tv"
#define SERVER_PORT "6667"

// Chat input values
#define INPUT_AMOUNT 1.0f
#define ZAP_MAX 5.0f
#define SPAWN_MAX 10.0f
#define TOWER_MAX 15.0f
#define RITUAL_MAX 20.0f

typedef enum e_Deities {
	HELIX,
	DOME
} Deities;

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
	ZAPBARHELIX,
	SPAWNBARDOME,
	TOWERBARDOME,
	RITUALBARDOME,
	ZAPBARDOME

} BarType;

typedef enum e_State{
	ALIVE,
	DEAD
} State;

typedef enum e_ObjectTypes{
	RITUAL,
	CREATURE,
	TOWER
} ObjectType;

#endif