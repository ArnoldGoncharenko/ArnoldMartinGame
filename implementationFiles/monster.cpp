#include "Monster.h"
#include <string>

using namespace std;

namespace GameCore
{
	monsterBase::monsterBase(string name, short health, short attack, short level, short speed, short armor)
	{
		monsterName = name;
		baseHealth = health;
		baseAttack = attack;
		baseLevel = level;
		baseSpeed = speed;
		baseArmor = armor;
	}
	monsterBase::monsterBase()
	{
		monsterName = "default";
		baseHealth = 0;
		baseAttack = 0;
		baseLevel = 0;
		baseSpeed = 0;
	}
	monsterBase::~monsterBase()
	{

	}
	short monsterBase::calcExp()
	{
		short totalExp = ((getDifficulty() + baseLevel) * (baseHealth + baseAttack)) / 2;

		return totalExp;
	}
	string monsterBase::getName()
	{
		return monsterName;
	}
	short monsterBase::getHealth()
	{
		return baseHealth;
	}
	short monsterBase::getAttack()
	{
		return baseAttack;
	}
	short monsterBase::getLevel()
	{
		return baseLevel;
	}
	short monsterBase::getDifficulty()
	{
		return (baseHealth + baseAttack);
	}

	short monsterBase::getBaseSpeed()
	{
		return baseSpeed;
	}

	void monsterBase::setBaseHealth(short newHealth)
	{
		baseHealth = newHealth;
	}

	short monsterBase::getBaseArmor()
	{
		return baseArmor;
	}

	short monsterBase::getExpKill()
	{
		return (baseLevel + getDifficulty());
	}
}