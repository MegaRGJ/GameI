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

	// Label Children 
	moneyLabel = (Text*)rootNode->getChildByName("Money_Label");
	levelLabel = (Text*)rootNode->getChildByName("Level_Label");
	hpLabel = (Text*)rootNode->getChildByName("HP_Label"); 
	lpCostLabel = (Text*)rootNode->getChildByName("LPCost_Label");
	lpAmountLabel = (Text*)rootNode->getChildByName("LPAmount_Label");
	lrCostLabel = (Text*)rootNode->getChildByName("LRCost_Label");
	lrAmountLabel = (Text*)rootNode->getChildByName("LRAmount_Label");
	rgCostLabel = (Text*)rootNode->getChildByName("RGCost_Label");
	rgAmountLabel = (Text*)rootNode->getChildByName("RGAmount_Label");
	egCostLabel = (Text*)rootNode->getChildByName("EGCost_Label");
	egAmountLabel = (Text*)rootNode->getChildByName("EGAmount_Label");
	mCostLabel = (Text*)rootNode->getChildByName("MCost_Label");
	mAmountLabel = (Text*)rootNode->getChildByName("MAmount_Label");
	ssCostlabel = (Text*)rootNode->getChildByName("SSCost_Label");
	ssAmountLabel = (Text*)rootNode->getChildByName("SSAmount_Label");
	mechCostLabel = (Text*)rootNode->getChildByName("MECost_Label");
	mechAmountLabel = (Text*)rootNode->getChildByName("MEAmount_Label");
	osCostLabel = (Text*)rootNode->getChildByName("OSCost_Label");
	osAmountLabel = (Text*)rootNode->getChildByName("OSAmount_Label");
	clickDPSLabel = (Text*)rootNode->getChildByName("ClickDPS_Label");
	autoDPSLabel = (Text*)rootNode->getChildByName("AutoDPS_Label");;
	
	//Button Children
	attackButton = static_cast<ui::Button*>(rootNode->getChildByName("Attack_Button"));
	lpButton = static_cast<ui::Button*>(rootNode->getChildByName("LaserPistol_Button"));
	lrButton = static_cast<ui::Button*>(rootNode->getChildByName("LaserRifle_Button"));
	rgButton = static_cast<ui::Button*>(rootNode->getChildByName("RailGun_Button"));
	egButton = static_cast<ui::Button*>(rootNode->getChildByName("EMPGrenade_Button"));
	mButton = static_cast<ui::Button*>(rootNode->getChildByName("Mercenary_Button"));
	ssButton = static_cast<ui::Button*>(rootNode->getChildByName("SniperSupport_Button"));
	mechButton = static_cast<ui::Button*>(rootNode->getChildByName("Mechs_Button"));
	osButton = static_cast<ui::Button*>(rootNode->getChildByName("OrbitalStrike_Button"));

	//Button listerners
	attackButton->addTouchEventListener(CC_CALLBACK_2(GameScene::AttackButtonPressed, this)); // need to change to health/hp
	lpButton->addTouchEventListener(CC_CALLBACK_2(GameScene::LPButtonPressed, this));
	lrButton->addTouchEventListener(CC_CALLBACK_2(GameScene::LRButtonPressed, this));
	rgButton->addTouchEventListener(CC_CALLBACK_2(GameScene::RGButtonPressed, this));
	egButton->addTouchEventListener(CC_CALLBACK_2(GameScene::EGButtonPressed, this));
	mButton->addTouchEventListener(CC_CALLBACK_2(GameScene::MButtonPressed, this));
	ssButton->addTouchEventListener(CC_CALLBACK_2(GameScene::SSButtonPressed, this));
	mechButton->addTouchEventListener(CC_CALLBACK_2(GameScene::MechButtonPressed, this));
	osButton->addTouchEventListener(CC_CALLBACK_2(GameScene::OSButtonPressed, this));

	return true;
}

void GameScene::update(float delta)
{
	// no HP in here atm
	hpLabel->setString(StringUtils::format("HP: %d", GameManager::sharedGameManager()->GetHP()));
	moneyLabel->setString(StringUtils::format("$%d", GameManager::sharedGameManager()->GetMoney()));
	levelLabel->setString(StringUtils::format("Level: %d", GameManager::sharedGameManager()->GetLevel()));
	lpCostLabel->setString(StringUtils::format("$%d", GameManager::sharedGameManager()->GetlpCost()));
	lpAmountLabel->setString(StringUtils::format("x%d", GameManager::sharedGameManager()->GetlpAmount()));
	lrCostLabel->setString(StringUtils::format("$%d", GameManager::sharedGameManager()->GetlrCost()));
	lrAmountLabel->setString(StringUtils::format("x%d", GameManager::sharedGameManager()->GetlrAmount()));
	rgCostLabel->setString(StringUtils::format("$%d", GameManager::sharedGameManager()->GetrgCost()));
	rgAmountLabel->setString(StringUtils::format("x%d", GameManager::sharedGameManager()->GetrgAmount()));
	egCostLabel->setString(StringUtils::format("$%d", GameManager::sharedGameManager()->GetegCost()));
	egAmountLabel->setString(StringUtils::format("x%d", GameManager::sharedGameManager()->GetegAmount()));
	mCostLabel->setString(StringUtils::format("$%d", GameManager::sharedGameManager()->GetmCost()));
	mAmountLabel->setString(StringUtils::format("x%d", GameManager::sharedGameManager()->GetmAmount()));
	ssCostlabel->setString(StringUtils::format("$%d", GameManager::sharedGameManager()->GetssCost()));
	ssAmountLabel->setString(StringUtils::format("x%d", GameManager::sharedGameManager()->GetssAmount()));
	mechCostLabel->setString(StringUtils::format("$%d", GameManager::sharedGameManager()->GetmechCost()));
	mechAmountLabel->setString(StringUtils::format("x%d", GameManager::sharedGameManager()->GetmechAmount()));
	osCostLabel->setString(StringUtils::format("$%d", GameManager::sharedGameManager()->GetosCost()));
	osAmountLabel->setString(StringUtils::format("x%d", GameManager::sharedGameManager()->GetosAmount()));

	GameManager::sharedGameManager()->HPManager();

	schedule(schedule_selector(GameScene::AutoAttacks), 1.0f);
}

void GameScene::AutoAttacks(float s)
{
	GameManager::sharedGameManager()->AutoDamageHP(0);
}

void GameScene::AttackButtonPressed(Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
{
	CCLOG("In touch! %d", type);

	if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
	{
		GameManager::sharedGameManager()->AddToMoney(1);
		GameManager::sharedGameManager()->DamageHP(1);
	}
	
}

void GameScene::LPButtonPressed(Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
{
	CCLOG("In touch! %d", type);

	if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
	{

		GameManager::sharedGameManager()->AddToLP(1.7f, 1);
	}
}

void GameScene::LRButtonPressed(Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
{
	CCLOG("In touch! %d", type);

	if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
	{
		GameManager::sharedGameManager()->AddToLR(1.7f, 1);
	}
}

void GameScene::RGButtonPressed(Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
{
	CCLOG("In touch! %d", type);

	if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
	{
		GameManager::sharedGameManager()->AddToRG(1.7f, 1);
	}
}

void GameScene::EGButtonPressed(Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
{
	CCLOG("In touch! %d", type);

	if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
	{
		GameManager::sharedGameManager()->AddToEMPG(1.7f, 1);
	}
}

void GameScene::MButtonPressed(Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
{
	CCLOG("In touch! %d", type);

	if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
	{
		GameManager::sharedGameManager()->AddToM(1.7f, 1);
	}
}

void GameScene::SSButtonPressed(Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
{
	CCLOG("In touch! %d", type);

	if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
	{
		GameManager::sharedGameManager()->AddToSS(1.7f, 1);
	}
}

void GameScene::MechButtonPressed(Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
{
	CCLOG("In touch! %d", type);

	if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
	{
		GameManager::sharedGameManager()->AddToMech(1.7f, 1);
	}
}

void GameScene::OSButtonPressed(Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
{
	CCLOG("In touch! %d", type);

	if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
	{
		GameManager::sharedGameManager()->AddToOS(1.7f, 1);
	}
}