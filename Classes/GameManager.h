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


	//increnments to users click
	void AddToLP(int i, int j); 
	void AddToLR(int i, int j);
	void AddToRG(int i, int j);
	void AddToEMPG(int i, int j);

	//increnments to auto clicks
	void AddToM(int i, int j);
	void AddToSS(int i, int j);
	void AddToMech(int i, int j);
	void AddToOS(int i, int j);

	//gets 
	int GetMoney();

	//variables
	int money;
	bool isGameLive;
	
private:
	GameManager();
	static GameManager* instance;
};

#endif // __GAMEMANAGER_SCENE_H__