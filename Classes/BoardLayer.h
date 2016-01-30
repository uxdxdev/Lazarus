#ifndef _BOARDLAYER_H_
#define _BOARDLAYER_H_

#include "Cursor.h"

using namespace cocos2d;

class BoardLayer : public cocos2d::Layer
{
public:
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	CREATE_FUNC(BoardLayer);

	Size getBoardSize(){ return _spBoard->getContentSize(); }
	void update(float dt) override;

private:
	Sprite* _spBoard;

	Cursor* helixCursor;
	Cursor* domeCursor;
	Ritual* helixRitual;
	Ritual* domeRitual;
};

#endif