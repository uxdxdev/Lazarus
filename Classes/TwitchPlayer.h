#ifndef _TWITCHPLAYER_H_
#define _TWITCHPLAYER_H_

#include "GameDefines.h"
#include "Observer.h"
#include "TwitchEvent.h"

using namespace std;

class TwitchPlayer : public Observer
{
public:
	static std::shared_ptr<TwitchPlayer> create();
	static std::shared_ptr<TwitchPlayer> create(shared_ptr<string> pName, Deities pSavior);
	//overload this later
	virtual bool init();
	void cleanup(){ /*this->~TwitchPlayer();*/ }
	void setName(shared_ptr<string> nameset);
	shared_ptr<string> getName(){ return this->name; }

	void TwitchPlayer::setDiety(Deities pSavior);

	void onNotify(std::shared_ptr<TwitchEvent> tEvent);
	TwitchPlayer();
	~TwitchPlayer();

private:
	shared_ptr<string> name;
	Deities savior;
	//TwitchPlayer();
	//~TwitchPlayer();
};



#endif
