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

	Size getBoardSize(){ return _spBoard->getContentSize(); }

	virtual void onNotify(std::shared_ptr<TwitchEvent> tEvent);

	void update(float dt) override;

	

private:
	Sprite* _spBoard;

	Cursor* helixCursor;
	Cursor* domeCursor;
	Ritual* helixRitual;
	Ritual* domeRitual;
	
};

#endif