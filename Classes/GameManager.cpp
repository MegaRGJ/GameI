#include "GameManager.h"

GameManager* GameManager::instance = NULL;

GameManager* GameManager::sharedGameManager() //HELP
{
	if (instance == NULL)
	{
		instance = new GameManager();
	}
	
	return instance;
}

GameManager::GameManager()
{
	isGameLive = false;
}

GameManager::~GameManager()
{

}

void GameManager::resetScore()
{
	money = 0;
}

// Money, level and hp
void GameManager::AddToMoney(int i)
{
	this->money += i;
}

int GameManager::GetMoney()
{
	return money;
}

void GameManager::AddToLevel(int i)
{

}

// user clicks
void GameManager::AddToLP(int i, int j)
{


}

void GameManager::AddToLR(int i, int j)
{

}

void GameManager::AddToRG(int i, int j)
{

}

void GameManager::AddToOS(int i, int j)
{

}
// Auto clicks


