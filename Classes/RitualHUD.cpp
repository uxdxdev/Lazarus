#include "RitualHUD.h"

USING_NS_CC;

bool RitualHUD::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	return true;
}

void RitualHUD::initDeity(Deities deity)
{

	std::string filename = "";
	switch (deity)
	{
	case HELIX:
		filename = "helix";
		break;
	case DOME:
		filename = "dome";
		break;
	default:
		break;
	}
	filename += "Bar.png";

	_spRitualBar = Sprite::create(filename.c_str());
	_lpRitualLabel = Label::createWithTTF("Ritual", "fonts/Marker Felt.ttf", 20);

	_spTowerBar = Sprite::create(filename.c_str());
	_lpTowerLabel = Label::createWithTTF("Tower", "fonts/Marker Felt.ttf", 20);

	_spSpawnBar = Sprite::create(filename.c_str());
	_lpSpawnLabel = Label::createWithTTF("Spawn", "fonts/Marker Felt.ttf", 20);

	_spZapBar = Sprite::create(filename.c_str());
	_lpZapLabel = Label::createWithTTF("Zap", "fonts/Marker Felt.ttf", 20);

	Size visibleSize = Director::getInstance()->getVisibleSize();
	float topBarPosX = 0.0f;

	switch (deity)
	{
	case HELIX:
		topBarPosX = visibleSize.width * 0.01 + _spRitualBar->getContentSize().width * 0.5;
		break;
	case DOME:
		topBarPosX = visibleSize.width * 0.99 - _spRitualBar->getContentSize().width * 0.5;
		break;
	default:
		break;
	}
	_spRitualBar->setPosition(
		topBarPosX, 
		visibleSize.height - _spRitualBar->getContentSize().height);
	_lpRitualLabel->setPosition(
		_spRitualBar->getPositionX() - _spRitualBar->getContentSize().width * 0.45 + _lpRitualLabel->getContentSize().width * 0.5,
		_spRitualBar->getPositionY());

	_spTowerBar->setPosition(
		_spRitualBar->getPositionX(),
		_spRitualBar->getPositionY() - _spRitualBar->getContentSize().height * 1.25f);
	_lpTowerLabel->setPosition(
		_lpRitualLabel->getPositionX(),
		_spTowerBar->getPositionY());

	_spSpawnBar->setPosition(
		_spTowerBar->getPositionX(),
		_spTowerBar->getPositionY() - _spRitualBar->getContentSize().height * 1.25f);
	_lpSpawnLabel->setPosition(
		_lpRitualLabel->getPositionX(),
		_spSpawnBar->getPositionY());

	_spZapBar->setPosition(
		_spSpawnBar->getPositionX(),
		_spSpawnBar->getPositionY() - _spRitualBar->getContentSize().height * 1.25f);
	_lpZapLabel->setPosition(
		_lpRitualLabel->getPositionX(),
		_spZapBar->getPositionY());

	this->addChild(_spRitualBar);
	this->addChild(_lpRitualLabel);
	this->addChild(_spTowerBar);
	this->addChild(_lpTowerLabel);
	this->addChild(_spSpawnBar);
	this->addChild(_lpSpawnLabel);
	this->addChild(_spZapBar);
	this->addChild(_lpZapLabel);

}

void RitualHUD::update(float dt)
{

}