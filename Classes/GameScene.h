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
	void LRButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type); // laser rifle
	void RGButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type); //railgun
	void EGButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type);  //emp 
	void MButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type); // mercenary
	void SSButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type); //sniper support 
	void MechButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type); // mechs
	void OSButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type); // Orbital Strike

	void AutoAttacks(float s);
private:
	cocos2d::ui::Button*    attackButton;
	cocos2d::ui::Button*	lpButton;
	cocos2d::ui::Button*	lrButton;
	cocos2d::ui::Button*	rgButton;
	cocos2d::ui::Button*	egButton;
	cocos2d::ui::Button*	mButton;
	cocos2d::ui::Button*	ssButton;
	cocos2d::ui::Button*	mechButton;
	cocos2d::ui::Button*	osButton;


	cocos2d::ui::Text*		clickDPSLabel;
	cocos2d::ui::Text*		autoDPSLabel;
	cocos2d::ui::Text*      moneyLabel;
	cocos2d::ui::Text*		levelLabel;
	cocos2d::ui::Text*		hpLabel;
	cocos2d::ui::Text*		lpCostLabel;
	cocos2d::ui::Text*		lpAmountLabel;
	cocos2d::ui::Text*		lrCostLabel;
	cocos2d::ui::Text*		lrAmountLabel;
	cocos2d::ui::Text*		rgCostLabel;
	cocos2d::ui::Text*		rgAmountLabel;
	cocos2d::ui::Text*		egCostLabel;
	cocos2d::ui::Text*		egAmountLabel;
	cocos2d::ui::Text*		mCostLabel;
	cocos2d::ui::Text*		mAmountLabel;
	cocos2d::ui::Text*		ssCostlabel;
	cocos2d::ui::Text*		ssAmountLabel;
	cocos2d::ui::Text*		mechCostLabel;
	cocos2d::ui::Text*		mechAmountLabel;
	cocos2d::ui::Text*		osCostLabel;
	cocos2d::ui::Text*		osAmountLabel;
};

#endif // __GAMESCENE_SCENE_H__
