#ifndef __GAMESCENE_SCENE_H__
#define __GAMESCENE_SCENE_H__

#include "GameManager.h"
#include "windows.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "cocos2d.h"
#include <string.h>
#include <sstream>

using namespace cocostudio::timeline;
using namespace cocos2d;
using namespace cocos2d::ui;
using namespace std;

//This will be my game

class GameScene : public cocos2d::Layer
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(GameScene);

	

	void update(float);

	//Button events
	void AttackButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type); //Robot button
	void LPButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type); // laser pistol 

private:
	cocos2d::ui::Button*    attackButton;

	cocos2d::ui::Text*      moneyLabel;
};

#endif // __GAMESCENE_SCENE_H__
