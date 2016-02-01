#include "GameScene.h"
#include "BoardLayer.h"

#include "RitualHUD.h"
#include "SimpleAudioEngine.h"  


USING_NS_CC;

cocos2d::Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
	auto scene = cocos2d::Scene::create();
    
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

	m_pBoardLayer = BoardLayer::create();
	this->addChild(m_pBoardLayer);

	m_pHelixHUD = RitualHUD::create();
	m_pHelixHUD->initDeity(HELIX);
	this->addChild(m_pHelixHUD);

	m_pDomeHUD = RitualHUD::create();
	m_pDomeHUD->initDeity(DOME);
	this->addChild(m_pDomeHUD);
	    
    
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("sound/background.wav", true);

	std::unique_ptr<bot::TwitchBot> twitchBot(new bot::TwitchBot("NICK damortonx\r\n", "USER damortonx\r\n", "PASS oauth:9z8neimcarxcdtq241w02l7bzyfozx\r\n"));
	m_TwitchBot = std::move(twitchBot);
	this->scheduleUpdate();



    return true;
}

void GameScene::update(float dt)
{	
	m_TwitchBot->Update();
	m_pBoardLayer->update(dt); 
	m_pDomeHUD->update(dt);
	m_pHelixHUD->update(dt);
}


void GameScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
