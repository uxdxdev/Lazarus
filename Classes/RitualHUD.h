#ifndef _RITUALHUD_H_
#define _RITUALHUD_H_

#include "BoardLayer.h"

using namespace cocos2d;

class RitualHUD : public cocos2d::Layer
{
public:
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	CREATE_FUNC(RitualHUD);

	void initDeity(Deities deity);

	void update(float dt) override;

private:
	Sprite* _spRitualBar;
	Label* _lpRitualLabel;
	Sprite* _spTowerBar;
	Label* _lpTowerLabel;
	Sprite* _spSpawnBar;
	Label* _lpSpawnLabel;
	Sprite* _spZapBar;
	Label* _lpZapLabel;

	Deities _eDeity;
};

#endif