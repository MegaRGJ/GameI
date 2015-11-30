#include "Enemy2.h"

USING_NS_CC;

Enemy2::Enemy2(cocos2d::Layer *layer)
{
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	enemyRobot = Sprite::create(".png");
	enemyRobot->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	layer->addChild(enemyRobot, 100);
}

Enemy2::~Enemy2()
{

}

void Enemy2::Respawn()
{
	health = 100;
}



