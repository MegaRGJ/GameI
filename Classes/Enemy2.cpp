#include "Enemy2.h"

USING_NS_CC;

Enemy2::Enemy2(cocos2d::Layer *layer)
{
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	enemyRobot2 = Sprite::create(".png");
	enemyRobot2->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	layer->addChild(enemyRobot2, 100);
}

Enemy2::~Enemy2()
{
	layer->removeChild(enemyRobot2, 100);
}


