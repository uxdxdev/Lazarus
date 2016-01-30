#include "Cursor.h"

Cursor::Cursor(){}

Cursor::~Cursor(){}

Cursor* Cursor::create(Deities deity)
{
	Cursor* pSprite = new Cursor();

	switch (deity)
	{
	case HELIX:
		pSprite->initWithFile("cursorHelix.png");
		break;
	case DOME:
		pSprite->initWithFile("cursorDome.png");
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

void Cursor::initOptions()
{
	// do things here like setTag(), setPosition(), any custom logic.
}

void Cursor::addEvents()
{
	// add any event handler 
}
