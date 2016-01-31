#include "Cursor.h"


USING_NS_CC;

Cursor::Cursor(){}

Cursor::~Cursor(){}

Cursor* Cursor::create(Deities deity)
{
	Cursor* pSprite = new Cursor();

	switch (deity)
	{
	case HELIX:
		pSprite->initWithFile("helixCursor.png");
		break;
	case DOME:
		pSprite->initWithFile("domeCursor.png");
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
	m_bMoving = false;

}

void Cursor::setDeity(Deities deity)
{
	m_deity = deity;
}

void Cursor::addEvents()
{
	// add any event handler 
}

void Cursor::move(Directions direction) 
{
	// apply a movement action only if cursor has finished moving
	if (canMove(direction))
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
		auto sequence = Sequence::create(easeInOut, delay, callToggleMovement, nullptr);

		this->runAction(sequence);
	}
	
}

void Cursor::MoveTarget(Directions direction)
{
		switch (direction)
		{
		case UP:
			this->setPosition(Vec2(this->getPositionX(), this->getPositionY() + CURSOR_DISPLACEMENT));
			break;
		case DOWN:
			this->setPosition(Vec2(this->getPositionX(), this->getPositionY() - CURSOR_DISPLACEMENT));
			break;
		case LEFT:
			this->setPosition(Vec2(this->getPositionX() - CURSOR_DISPLACEMENT, this->getPositionY()));
			break;
		case RIGHT:
			this->setPosition(Vec2(this->getPositionX() + CURSOR_DISPLACEMENT, this->getPositionY()));
			break;
		default:
			CCLOG("Cursor::move switch statement defaulted here!");
			break;
		}
}

bool Cursor::canMove(Directions direction)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	bool result = true;
	switch (direction)
	{
	case UP:
		if ((this->getPositionY() + this->getContentSize().height * 0.5 + CURSOR_DISPLACEMENT) > visibleSize.height)
			result = false;
		break;
	case DOWN:
		if ((this->getPositionY() - this->getContentSize().height * 0.5 - CURSOR_DISPLACEMENT) < 0)
			result = false;
		break;
	case LEFT:
		if (m_deity == HELIX)
			if ((this->getPositionX() - this->getContentSize().width * 0.5 - CURSOR_DISPLACEMENT) < (visibleSize.width - visibleSize.height) * 0.5)
				result = false;
		if (m_deity == DOME)
			if ((this->getPositionX() - this->getContentSize().width * 0.5 - CURSOR_DISPLACEMENT) < visibleSize.width * 0.5)
				result = false;
		break;
	case RIGHT:
		if (m_deity == HELIX)
			if ((this->getPositionX() + this->getContentSize().width * 0.5 + CURSOR_DISPLACEMENT) > visibleSize.width * 0.5)
				result = false;
		if (m_deity == DOME)
			if ((this->getPositionX() - this->getContentSize().width * 0.5 - CURSOR_DISPLACEMENT) > (visibleSize.width + visibleSize.height) * 0.5)
				result = false;
		break;
	default:
		break;
	}

	return result;
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