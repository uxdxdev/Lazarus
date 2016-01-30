#ifndef _TWITCHMODEL_H_
#define _TWITCHMODEL_


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

private:
	string name;
	//TwitchModel();
	//~TwitchModel();
};



#endif
