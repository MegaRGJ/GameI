// Aidens Code
#include "MainMenuScene.h"
#include "GameScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace cocos2d;
using namespace cocos2d::ui;

Scene* MainMenuScene::createScene()
{
	// 'scene' is an autorelease object
	auto myScene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = MainMenuScene::create();

	// add layer as a child to scene
	myScene->addChild(layer);

	// return the scene
	return myScene;
}

// on "init" you need to initialize your instance
bool MainMenuScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	auto rootNode = CSLoader::createNode("MenuScene.csb");

	addChild(rootNode);

	//Button children
	startButton = static_cast<ui::Button*>(rootNode->getChildByName("btnStart"));
	quitButton = static_cast<ui::Button*>(rootNode->getChildByName("btnQuit"));

	//Button listeners
	startButton->addTouchEventListener(CC_CALLBACK_2(MainMenuScene::StartButtonPressed, this)); // need to change to health/hp
	//quitButton->addTouchEventListener(CC_CALLBACK_2(MainMenuScene::QuitButtonPressed, this));

	return true;
}

void MainMenuScene::StartButtonPressed(Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
{
	CCLOG("In touch! %d", type);

	if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
	{
		Scene *scene = GameScene::createScene();
		Director::getInstance()->replaceScene(scene);
	}

}
