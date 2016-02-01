#ifndef _BOARDLAYER_H_
#define _BOARDLAYER_H_

#include <memory>

#include "Observer.h"
#include "TwitchEvent.h"
#include "Cursor.h"


using namespace cocos2d;

class BoardLayer : public cocos2d::Layer, public Observer
{
public:
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	CREATE_FUNC(BoardLayer);

	~BoardLayer();

	Size getBoardSize(){ return _spBoard->getContentSize(); }

	virtual void onNotify(std::shared_ptr<TwitchEvent> tEvent);

	void update(float dt) override;

	void spawnHelix();
	void spawnDome();
	void TowerHelix();
	void TowerDome();

	void SetCreatureSpawned(Deities deity, bool value);
	void TowerDestroyed(Deities deity);

	Cursor* GetCursor(Deities deity);
	ritual::Ritual *GetRitual(Deities deity);

private:
	Sprite* _spBoard;
	bool m_bIsCreatureSpawnedHelix;
	bool m_bIsCreatureSpawnedDome;
	bool m_bCanSpawnTowerHelix;
	bool m_bCanSpawnTowerDome;

	int m_iNumberOfTowersSpawnedHelix;
	int m_iNumberOfTowersSpawnedDome;

	Cursor* helixCursor;
	Cursor* domeCursor;
	std::shared_ptr<ritual::Ritual> helixRitual;
	std::shared_ptr<ritual::Ritual> domeRitual;
	
};

#endif