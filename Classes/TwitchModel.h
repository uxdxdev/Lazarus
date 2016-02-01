#ifndef _TWITCHMODEL_H_
#define _TWITCHMODEL_H_


#include "Observer.h"
#include "TwitchPlayer.h"

using namespace std;

typedef struct topbar{

public:
	void setCurrent(float  setcurrent){
		current = setcurrent;
		CCLOG("Current reset to %f", current);
	}

	void setMax(float setMax){
		max = setMax;
	}
	void setsaviour(Deities setsaviour){
		saviour = setsaviour;
	}

	float max;
	float current;
	Deities saviour;
}topbar;

class TwitchModel : public Observer
{
public:
	static std::shared_ptr<TwitchModel> create();
	//overload this later
	virtual bool init();
	void cleanup(){ /*this->~TwitchPlayer();*/ }
	

	void onNotify(std::shared_ptr<TwitchEvent> tEvent);
	TwitchModel();
	~TwitchModel();

	
	vector < shared_ptr<TwitchPlayer>> playerList;
	

	//method to search for player object from player name & if not found create and return player object
	shared_ptr<TwitchPlayer> getPlayer(shared_ptr<string> pname);
	shared_ptr<TwitchPlayer> registerPlayer(shared_ptr<string> pname, Deities saviour);

	void initBars();
	
	float getBarCurrent(BarType bartype);
	float getBarMax(BarType bartype);
	void setBarCurrent(BarType bartype, float currentset);
	void setBarMax(BarType bartype, float maxset);

	//TODO clear all players and counters


private:
	topbar *getBar(BarType bartype);
	string name;
	topbar zapBarHelix;
	topbar spawnBarHelix;
	topbar towerBarHelix;
	topbar ritualBarHelix;
	topbar zapBarDome;
	topbar spawnBarDome;
	topbar towerBarDome;
	topbar ritualBarDome;

	void increaseBar(TwitchEventType teType, shared_ptr<string> pname);
	
};



#endif
