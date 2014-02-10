#include "Player.h"
#include <string>
#include <iostream>

using namespace GameCore;
using namespace std;

playerBase::playerBase(string name, short health, short attack, short defaultSpeed, short defaultArmor, short lvlPoints, short pMaxHealth)
{
	playerName = name;
	playerHealth = health;
	playerAttack = attack;
	playerLevel = 1;
	totalExp = 0;
	XPReq = 100;
	speed = defaultSpeed;
	armor = defaultArmor;
	xpPoints = lvlPoints;
	playerMaxHealth = pMaxHealth;
}
playerBase::playerBase()
{
	playerName = "default";
	playerHealth = 0;
	playerAttack = 0;
	playerLevel = 0;
	totalExp = 0;
	XPReq = 0;
	speed = 0;
}
playerBase::~playerBase()
{

}
string playerBase::getName()
{
	return playerName;
}
short playerBase::getHealth()
{
	return playerHealth;
}
short playerBase::getAttack()
{
	return playerAttack;
}
short playerBase::getLevel()
{
	return playerLevel;
}
short playerBase::getExp()
{
	return totalExp;
}

short playerBase::checkLvL()
{
	if (totalExp >= XPReq)
	{
		cout << "The player leveled up!\n";
		playerLevel++;
		XPReq *= 2;
		xpPoints = xpPoints + 3;
		cout << "Player needs " << XPReq << " to level up" << endl;
		return 1;

	}

	else
	{
		return 0;
	}
}

short playerBase::getSpeed()
{
	return speed;
}

void playerBase::setHealth(short newHealth)
{
	playerHealth = newHealth;
}

short playerBase::getArmor()
{
	return armor;
}

void playerBase::setExp(short monsterExp)
{
	cout << "The player earned " << monsterExp << " Exp\n";
	totalExp = totalExp + monsterExp;
}

short playerBase::getLvlPoints() {
	return xpPoints;
}

void playerBase::setAttack(short newAttack) {
	playerAttack = newAttack;
}

void playerBase::setSpeed(short newSpeed) {
	speed = newSpeed;
}

void playerBase::setLvlPoints(short newLvlPoints) {
	xpPoints = newLvlPoints;
}

short playerBase::getMaxHealth() {
	return playerMaxHealth;
}

void playerBase::setMaxHealth(short newMaxHealth) {
	playerMaxHealth = newMaxHealth;
}