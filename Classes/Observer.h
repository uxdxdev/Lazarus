#ifndef OBSERVER_H
#define OBSERVER_H
/*
Observer.h
Observer interface for design pattern implementation
@author	David Morton K00179391, Tommaso Marenzi k00180522
@date	17.4.15
*/
// Includes
#include "cocos2d.h"

class Observer
{
public:
	virtual ~Observer(){}

	/*
	Notify all observers of an event
	@param Node* pointer to a cocos2d node
	@param EventCustom* pointer to a cocos2d custom event
	*/
	virtual void onNotify(cocos2d::Node* node, cocos2d::EventCustom* event) = 0;
};

#endif