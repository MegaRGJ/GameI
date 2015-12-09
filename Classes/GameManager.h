#ifndef __GAMEMANAGER_SCENE_H__
#define __GAMEMANAGER_SCENE_H__

#include "cocos2d.h"
#include <stdio.h>
//This will be my game

class GameManager
{
public:
	~GameManager();
	static GameManager* sharedGameManager();

	void resetScore();
	//Money, level and hp incrementers 
	void AddToMoney(int i);
	void AddToLevel(int i);
	void DamageHP(int hp);
	void AutoDamageHP();
	void HPManager();

	//increnments to users click
	void AddToLP(float i, int j); // i is the cost, j is thr amount and l is the amount the cost will be * by. 
	void AddToLR(float i, int j);
	void AddToRG(float i, int j);
	void AddToEMPG(float i, int j);

	//increnments to auto clicks
	void AddToM(float i, int j);
	void AddToSS(float i, int j);
	void AddToMech(float i, int j);
	void AddToOS(float i, int j);

	bool PriceCheck(int cost);
	void DamageClick(int amount, int baseDmg);
	void DamageAuto(int amount, int baseDmg);

	//gets 
	int GetHP();
	int GetMoney();
	int GetLevel();
	int GetlpCost();
	int GetlpAmount();
	int GetlrCost();
	int GetlrAmount();
	int GetrgCost();
	int GetrgAmount();
	int GetegCost();
	int GetegAmount();
	int GetmCost();
	int GetmAmount();
	int GetssCost();
	int GetssAmount();
	int GetmechCost();
	int GetmechAmount();
	int GetosCost();
	int GetosAmount();

	//variables
	int hp1;
	int hp;
	int damageTotal;
	int damageAutoTotal;
	int money;
	int level;
	int lpCost;
	int lpAmount;
	int lrCost;
	int lrAmount;
	int rgCost;
	int rgAmount;
	int egCost;
	int egAmount;
	int mCost;
	int mAmount;
	int ssCost;
	int ssAmount;
	int mechCost;
	int mechAmount;
	int osCost;
	int osAmount;


	bool isGameLive;
	
private:
	GameManager();
	static GameManager* instance;
};

#endif // __GAMEMANAGER_SCENE_H__