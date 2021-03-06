// Aidens Code
#ifndef __MAINMENUSCENE_SCENE_H__
#define __MAINMENUSCENE_SCENE_H__

#include "GameManager.h"
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

class MainMenuScene : public cocos2d::Layer
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(MainMenuScene);

	void StartButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type);
	//void QuitButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type);

private:
	cocos2d::ui::Button*    startButton;
	cocos2d::ui::Button*    quitButton;

};

#endif // __MAINMENUSCENE_SCENE_H__
