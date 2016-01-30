#include "Ritual.h"

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
}

void Ritual::addEvents()
{
	// add any event handler 
}
