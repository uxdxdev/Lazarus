#ifndef __GAMESSCENE_SCENE_H__
#define __GAMESCENE_SCENE_H__

#include "BoardLayer.h"
#include "Cursor.h"
#include <memory>
#include "bot\TwitchBot.h"


class GameScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

	void update(float dt) override;
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);

private:
	std::unique_ptr<bot::TwitchBot> m_TwitchBot;
	BoardLayer* m_pBoardLayer;

	
};

#endif // __GameScene_SCENE_H__
