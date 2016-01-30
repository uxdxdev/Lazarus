#include "Ritual.h"
#include "GameDefines.h"

USING_NS_CC;

Ritual::Ritual(){}

Ritual::~Ritual(){}

Ritual* Ritual::create(Deities deity)
{
	Ritual* pSprite = new Ritual();
	
	switch (deity)
	{
	case HELIX:
		pSprite->initWithFile("helix.png");
		break;
	case DOME:
		pSprite->initWithFile("dome.png");
		break;
	default:
		break;
	}

	if (pSprite)
	{
		pSprite->autorelease();

		pSprite->initOptions();

		pSprite->addEvents();

		pSprite->scheduleUpdate();

		return pSprite;
	}

	CC_SAFE_DELETE(pSprite);
	return NULL;

}

void Ritual::initOptions()
{
	// do things here like setTag(), setPosition(), any custom logic.
	auto rotateCW = RotateBy::create(0.50f * ACTION_SPEED, 40.0f);
	auto rotateCCW = rotateCW->reverse();
	auto wobble = Sequence::create(rotateCW, rotateCCW, rotateCCW->clone(), rotateCW->clone(), nullptr);

	this->runAction(RepeatForever::create(wobble));

}

void Ritual::addEvents()
{
	// add any event handler 
}
