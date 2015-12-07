#include "GameScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "GameManager.h"


USING_NS_CC;


using namespace cocostudio::timeline;
using namespace cocos2d;
using namespace cocos2d::ui;


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
	if (!Layer::init())
	{
		return false;
	}

	GameManager::sharedGameManager()->resetScore();

	auto rootNode = CSLoader::createNode("MainScene.csb");

	addChild(rootNode);

	this->scheduleUpdate();

	moneyLabel = (Text*)rootNode->getChildByName("Money_Label");

	attackButton = static_cast<ui::Button*>(rootNode->getChildByName("Attack_Button"));
	attackButton->addTouchEventListener(CC_CALLBACK_2(GameScene::AttackButtonPressed, this)); // need to change to health/hp

	return true;
}

void GameScene::update(float delta)
{
	moneyLabel->setString(StringUtils::format("%d", GameManager::sharedGameManager()->GetMoney()));
}

void GameScene::AttackButtonPressed(Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
{
	CCLOG("In touch! %d", type);

	if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
	{
		GameManager::sharedGameManager()->AddToMoney(1);
	}
	
}