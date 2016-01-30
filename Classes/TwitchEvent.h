//enum event type
//player name
//getters and setters

#ifndef _TWITCHEVENT_H_
#define _TWITCHEVENT_H_


#include "GameDefines.h"

using namespace std;

class TwitchEvent 
{
public:
	static std::shared_ptr<TwitchEvent> create();
	static std::shared_ptr<TwitchEvent> create(TwitchEventType tevent, std::shared_ptr<string>* pName);
	//overload this later
	virtual bool init();
	void cleanup(){ }
	


	TwitchEvent();
	~TwitchEvent();

	

private:
	TwitchEventType eventType;
	std::shared_ptr<string>* playerName;
};

#endif

