#pragma once

#ifndef __ENEMY2_H__
#define __ENEMY2_H__

#include "cocos2d.h"

class Enemy2
{
public:
	Enemy2(cocos2d::Layer *layer);
	~Enemy2();
	void Respawn();

private:
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;

	cocos2d::Sprite *enemyRobot;
};

#endif // __ENEMY2_H__

