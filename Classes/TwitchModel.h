#ifndef _TWITCHMODEL_H_
#define _TWITCHMODEL_H_


#include "Observer.h"
#include "TwitchPlayer.h"

using namespace std;

class TwitchModel : public Observer
{
public:
	static std::shared_ptr<TwitchModel> create();
	//overload this later
	virtual bool init();
	void cleanup(){ /*this->~TwitchPlayer();*/ }
	

	void onNotify(cocos2d::Node* node, cocos2d::EventCustom* event);
	TwitchModel();
	~TwitchModel();

	vector < shared_ptr<TwitchPlayer>> helix;
	vector < shared_ptr<TwitchPlayer>> dome;

	//method to search for player object from player name & if not found create and return player object

private:
	string name;
	topbar chantBarHelix;
	topbar spawnBarHelix;
	topbar towerBarHelix;
	topbar ritualBarHelix;
	topbar chantBarDome;
	topbar spawnBarDome;
	topbar towerBarDome;
	topbar ritualBarDome;
	
};



#endif
