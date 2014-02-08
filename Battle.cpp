#include "Battle.h"
#include "Monster.h"
#include "Player.h"
#include <string>
#include <stdlib.h>
#include <iostream>

namespace GameCore
{
	battle::battle()
	{

	}
	battle::~battle()
	{

	}
	bool battle::calcTurn(short player, short monster)
	{
		if (player > monster)
		{
			return true;
		}

		else if (player == monster)
		{
			short randomNum = rand() % 101;
			if (randomNum >= 50)
			{
				return true;
			}
			return false;
		}

		return false;
	}

	void battle::damageDone(monsterBase* monster, playerBase* player, bool whodamage)
	{

		if (whodamage == true)
		{
			cout << "The player did " << player->getAttack() << " to the monster!\n";
			monster->setBaseHealth((monster->getHealth()) - player->getAttack());
			cout << "The Monsters current health is: " << monster->getHealth() << "\n";
		}

		else
		{
			cout << "The monster did " << monster->getAttack() << " to the player!\n";
			player->setHealth((player->getHealth()) - monster->getAttack());
			cout << "The players current health is: " << player->getHealth() << "\n";
		}

	}
}
