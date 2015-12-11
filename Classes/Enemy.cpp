#include "Enemy.h"

USING_NS_CC;

Enemy::Enemy(cocos2d::Layer *layer)
{
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	enemyRobot = Sprite::create(".png");
	enemyRobot->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
}

Enemy::AddEnemy()
{
	layer->addChild(enemyRobot, 100);
}

Enemy::~Enemy()
{
	layer->removeChild(enemyRobot, 100);
}