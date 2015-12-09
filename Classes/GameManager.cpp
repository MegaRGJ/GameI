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
	level = 1;
	lpCost = 5;
	lpAmount = 0;
	lrCost = 10;
	lrAmount = 0;
	rgCost = 15;
	rgAmount = 0;
	egCost = 30;
	egAmount = 0;
	mCost = 20;
	mAmount = 0;
	ssCost = 30;
	ssAmount = 0;
	mechCost = 40;
	mechAmount = 0;
	osCost = 50;
	osAmount = 0;
	damageTotal = 0;
	damageAutoTotal = 0;
	hp = 100;
	hp1 = 100;
}

// Money, level and hp
void GameManager::AddToMoney(int i)
{
	this->money += i + damageTotal;
}

void GameManager::AddToLevel(int i)
{
	this->level += i;
}

void GameManager::DamageHP(int dmg)
{
	this->hp -= dmg + damageTotal;
	HPManager();
}

void GameManager::HPManager()
{
	if (this->hp < 0)
	{
		hp = (hp1 * level) * 1.30;
		AddToLevel(1);
	}
}

void GameManager::AutoDamageHP()
{
	this->hp -= damageAutoTotal;
	this->money += damageAutoTotal;
	HPManager();
}

bool GameManager::PriceCheck(int cost)
{
	if (this->money >= cost)
	{
		money -= cost;
		return true;
	}
	else
	{
		return false;
	}
}

void GameManager::DamageClick(int amount, int baseDmg)
{
	int damage =  baseDmg * amount + 1;

	damageTotal = +damage;

}

void GameManager::DamageAuto(int amount, int baseDmg)
{
	int damage = baseDmg * (amount + 1);

	damageAutoTotal = +damage;

}

// user clicks
void GameManager::AddToLP(float i, int j)
{
	if (PriceCheck(this->lpCost))
	{
		DamageClick(this->lpAmount, 1);
		this->lpAmount += j;
		this->lpCost *= i;
	}

}

void GameManager::AddToLR(float i, int j)
{
	if (PriceCheck(this->lrCost))
	{
		DamageClick(this->lrAmount, 2);
		this->lrAmount += j;
		this->lrCost *= i;
	}
}

void GameManager::AddToRG(float i, int j)
{
	if (PriceCheck(this->rgCost))
	{
		DamageClick(this->rgAmount, 4);
		this->rgAmount += j;
		this->rgCost *= i;
	}
}

void GameManager::AddToEMPG(float i, int j)
{
	if (PriceCheck(this->egCost))
	{
		DamageClick(this->egAmount, 6);
		this->egAmount += j;
		this->egCost *= i;
	}
}
// Auto clicks
void GameManager::AddToM(float i, int j)
{
	if (PriceCheck(this->mCost))
	{
		DamageAuto(this->mAmount, 2);
		this->mAmount += j;
		this->mCost *= i;
	}
}

void GameManager::AddToSS(float i, int j)
{
	if (PriceCheck(this->ssCost))
	{
		DamageAuto(this->ssAmount, 6);
		this->ssAmount += j;
		this->ssCost *= i;
	}
}

void GameManager::AddToMech(float i, int j)
{
	if (PriceCheck(this->mechCost))
	{
		DamageAuto(this->mechAmount, 10); // not here
		this->mechAmount += j;
		this->mechCost *= i;
	}
}

void GameManager::AddToOS(float i, int j)
{
	if (PriceCheck(this->osCost))
	{
		DamageAuto(this->osAmount, 14);
		this->osAmount += j;
		this->osCost *= i;
	}
}
// returns 
int GameManager::GetMoney()
{
	return money;
}

int GameManager::GetLevel()
{
	return level;
}

int GameManager::GetlpCost()
{
	return lpCost;
}

int GameManager::GetlpAmount()
{
	return lpAmount;
}

int GameManager::GetlrCost()
{
	return lrCost;
}

int GameManager::GetlrAmount()
{
	return lrAmount;
}

int GameManager::GetrgCost()
{
	return rgCost;
}

int GameManager::GetrgAmount()
{
	return rgAmount;
}

int GameManager::GetegCost()
{
	return egCost;
}

int GameManager::GetegAmount()
{
	return egAmount;
}

int GameManager::GetmCost()
{
	return mCost;
}

int GameManager::GetmAmount()
{
	return mAmount;
}

int GameManager::GetssCost()
{
	return ssCost;
}

int GameManager::GetssAmount()
{
	return ssAmount;
}

int GameManager::GetmechCost()
{
	return mechCost;
}

int GameManager::GetmechAmount()
{
	return mechAmount;
}

int GameManager::GetosCost()
{
	return osCost;
}

int GameManager::GetosAmount()
{
	return osAmount;
}
int GameManager::GetHP()
{
	return hp;
}




