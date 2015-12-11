#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "cocos2d.h"

class Enemy
{
public:
	Enemy(cocos2d::Layer *layer);
	~Enemy();

private:
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;

	cocos2d::Sprite *enemyRobot;
};

#endif // __ENEMY_H__
