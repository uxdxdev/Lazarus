//enum event type
//player name
//getters and setters

#ifndef _TWITCHEVENT_H_
#define _TWITCHEVENT_H_

#include <memory>

#include "GameDefines.h"

using namespace std;

class TwitchEvent 
{
public:
	static std::shared_ptr<TwitchEvent> create();
	static std::shared_ptr<TwitchEvent> create(TwitchEventType tevent, std::string username);
	//overload this later
	virtual bool init();
	void cleanup(){ }
	TwitchEventType GetEventType();
	shared_ptr<string> GetUsername();
	TwitchEvent();
	~TwitchEvent();

private:
	TwitchEventType eventType;
	shared_ptr<string> playerName;
};

#endif

