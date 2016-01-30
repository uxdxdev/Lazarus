#ifndef _TWITCHPLAYER_H_
#define _TWITCHPLAYER_H_

#include "GameDefines.h"
#include "Observer.h"
using namespace std;

class TwitchPlayer : public Observer
{
public:
	static std::shared_ptr<TwitchPlayer> create();
	//overload this later
	virtual bool init();
	void cleanup(){ /*this->~TwitchPlayer();*/ }
	void setName(string nameset);
	string getName(){ return this->name; }
	
	void onNotify(cocos2d::Node* node, cocos2d::EventCustom* event);
	TwitchPlayer();
	~TwitchPlayer();

private:
	string name;
	//TwitchPlayer();
	//~TwitchPlayer();
};



#endif
