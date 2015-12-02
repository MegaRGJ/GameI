#include "MainMenuScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* MainMenuScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = MainMenuScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
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

	auto rootNode = CSLoader::createNode("MainScene.csb");

	addChild(rootNode);

	auto winSize = Director::getInstance()->getVisibleSize();

	//-----------------------------------------------------------------------------------------
	//TOUCHES
	//Set up a touch listener.
	auto touchListener = EventListenerTouchOneByOne::create();

	//Set callbacks for our touch functions.
	touchListener->onTouchBegan = CC_CALLBACK_2(MainMenuScene::onTouchBegan, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(MainMenuScene::onTouchEnded, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(MainMenuScene::onTouchMoved, this);
	touchListener->onTouchCancelled = CC_CALLBACK_2(MainMenuScene::onTouchCancelled, this);

	//Add our touch listener to event listener list.
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
	//-----------------------------------------------------------------------------------------

	//-----------------------------------------------------------------------------------------
	//Start button.
	startButton = static_cast<ui::Button*>(rootNode->getChildByName("btnStart"));
	startButton->addTouchEventListener(CC_CALLBACK_2(MainMenuScene::StartButtonPressed, this));
	startButton->setPosition(Vec2(winSize.width*0.5f, winSize.height*0.5f));
	//-----------------------------------------------------------------------------------------

	return true;
}