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
		short playerMaxHealth;
		short playerAttack;
		short playerLevel;
		short totalExp;
		short XPReq;
		short speed;
		short armor;
		short xpPoints;

	public:
		playerBase(string, short, short, short, short, short, short);
		playerBase();
		string getName();

		short getHealth();
		void setHealth();

		short getAttack();
		void setAttack(short);

		short getSpeed();
		void setSpeed(short);

		short getLvlPoints();
		void setLvlPoints(short);

		short getMaxHealth();
		void setMaxHealth(short);

		short getLevel();
		short getExp();
		short checkLvL();
		short getArmor();
		void setHealth(short);
		void setExp(short);
		~playerBase();
	};
}