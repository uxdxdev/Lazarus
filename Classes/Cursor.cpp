#include "Cursor.h"
#include "GameDefines.h"

USING_NS_CC;

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

void Cursor::move(Directions direction) 
{
	// apply a movement action only if cursor has finished moving
	if (!this->isMoving())
	{
		Vec2 movement = Vec2(0, 0);

		switch (direction)
		{
		case UP:
			movement.y = CURSOR_DISPLACEMENT;
			break;
		case DOWN:
			movement.y = -CURSOR_DISPLACEMENT;
			break;
		case LEFT:
			movement.x = -CURSOR_DISPLACEMENT;
			break;
		case RIGHT:
			movement.x = CURSOR_DISPLACEMENT;
			break;
		default:
			CCLOG("Cursor::move switch statement defaulted here!");
			break;
		}

		auto moveAction = MoveBy::create(0.3f * ACTION_SPEED, movement);
		auto easeInOut = EaseInOut::create(moveAction->clone(), 2.0f);
		auto delay = DelayTime::create(0.3f * ACTION_SPEED);
		auto callToggleMovement = CallFunc::create(std::bind(&Cursor::toggleMovement, this));
		auto sequence = Sequence::create(moveAction, delay, callToggleMovement, nullptr);

		this->runAction(sequence);
	}
}

void Cursor::randomeMove()
{
	int randomInt = RandomHelper::random_int(1, 4);
	switch (randomInt)
	{
	case 1:
		this->move(UP);
		break;
	case 2:
		this->move(DOWN);
		break;
	case 3:
		this->move(LEFT);
		break;
	case 4:
		this->move(RIGHT);
		break;
	default:
		break;
	}
}