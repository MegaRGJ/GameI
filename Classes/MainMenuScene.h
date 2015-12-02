#ifndef __MAINMENUSCENE_SCENE_H__
#define __MAINMENUSCENE_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

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

	//Deal with touches.
	virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);
	virtual void onTouchEnded(cocos2d::Touch*, cocos2d::Event*);
	virtual void onTouchMoved(cocos2d::Touch*, cocos2d::Event*);
	virtual void onTouchCancelled(cocos2d::Touch*, cocos2d::Event*);

	//Button event
	void StartButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type);

private:
	void GoToGameScene(cocos2d::Ref *sender);
	cocos2d::ui::Button*    startButton;

};

#endif // __MAINMENUSCENE_SCENE_H__
