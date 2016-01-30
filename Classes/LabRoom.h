#ifndef _LABROOM_
#define _LABROOM_


#include "GameDefines.h"

using namespace cocos2d;

class LabRoom : public cocos2d::Layer
{
public:
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::CCScene* scene();


	
	//extend the draw function
	virtual void draw(cocos2d::Renderer* renderer, const kmMat4& transform, bool transformUpdated);
	//virtual void onDraw(const kmMat4 &transform, bool transformUpdated);
	// implement the "static node()" method manually
	CREATE_FUNC(LabRoom);

private:
	virtual void onDrawPrimitives(const kmMat4 &transform, bool transformUpdated);
	CustomCommand _customCommand;
	std::vector<LinePoint> drawingPoints;
};



#endif