#pragma once

#include<cstring>
#include <string>

using namespace std;

namespace GameCore
{
	class monsterBase
	{
		string monsterName;
		short baseHealth;
		short baseAttack;
		short baseLevel;
		short baseSpeed;
		short baseArmor;

	public:
		monsterBase(string, short, short, short, short, short);
		monsterBase();
		string getName();
		short getHealth();
		short getAttack();
		short getLevel();
		short getDifficulty();
		short getBaseSpeed();
		short getBaseArmor();
		short getExpKill();
		void setBaseHealth(short);
		~monsterBase();
		short calcExp();
	};
}
