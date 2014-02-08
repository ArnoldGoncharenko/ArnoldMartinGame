#pragma once

#include<cstring>
#include <string>

using namespace std;

namespace GameCore
{
	class playerBase
	{
		string playerName;
		short playerHealth;
		short playerAttack;
		short playerLevel;
		short totalExp;
		short XPReq;
		short speed;
		short armor;

	public:
		playerBase(string, short, short, short, short);
		playerBase();
		string getName();
		short getHealth();
		short getAttack();
		short getLevel();
		short getExp();
		short checkLvL();
		short getSpeed();
		short getArmor();
		void setHealth(short);
		void setExp(short);
		~playerBase();
	};
}
