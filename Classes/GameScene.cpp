#include "GameScene.h"
#include "BoardLayer.h"
#include "Cursor.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto label = Label::createWithTTF("Game Scene", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);


    //add the labroom layer to display guide lines
	//Layer* lablayer = LabRoom::create();
	//this->addChild(lablayer);

	BoardLayer* boardLayer = BoardLayer::create();
	this->addChild(boardLayer);

	Size boardSize = boardLayer->getBoardSize();
	helixRitual = Ritual::create(HELIX);
	helixRitual->setPosition(
		(visibleSize.width - boardSize.width + helixRitual->getContentSize().width) * 0.55,
		visibleSize.height * 0.5);
	this->addChild(helixRitual);

	domeRitual = Ritual::create(DOME);
	domeRitual->setPosition(
		(visibleSize.width + boardSize.width - domeRitual->getContentSize().width) * 0.48,
		visibleSize.height * 0.5);
	this->addChild(domeRitual);

	helixCursor = Cursor::create(HELIX);
	helixCursor->setPosition(
		helixRitual->getPositionX() + helixRitual->getContentSize().width,
		helixRitual->getPositionY());
	this->addChild(helixCursor);

	domeCursor = Cursor::create(DOME);
	domeCursor->setPosition(
		domeRitual->getPositionX() - domeRitual->getContentSize().width,
		domeRitual->getPositionY());
	this->addChild(domeCursor);
	    
    
	std::unique_ptr<bot::TwitchBot> twitchBot(new bot::TwitchBot("NICK damortonx\r\n", "USER damortonx\r\n", "PASS oauth:9z8neimcarxcdtq241w02l7bzyfozx\r\n"));
	m_TwitchBot = std::move(twitchBot);
	this->scheduleUpdate();

    return true;
}

void GameScene::update(float dt)
{	
	m_TwitchBot->Update();

	helixCursor->randomeMove();
	domeCursor->randomeMove();
}


void GameScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
