// Test Master for Assignment 2
// OOP344 - BTP300
// a2test.cpp
// 
// August 27 2011
// Fardad Soleimanloo, Chris Szalwinski
// Version 1.0

#include "string.h"
#include <cstdio>
#include "Battle.h"
#include <iostream>
#include "Item.h"
#include "Inventory.h";
#include <stdlib.h>

using namespace std;
using namespace GameCore;

int main()
	{
		monsterBase monsterExample("Monster", 100, 10, 10, 10, 10);
		battle battleGo;
		Inventory playerInventory(15);
		monsterBase * monsterPointer = &monsterExample;
		playerBase * playerPointer;
		bool finishBattle = 1;
		short choice;

		string playerName = "";

		cout << "Please choose a name\n\n";
		cin >> playerName;

		playerBase player(playerName, 20, 20, 20, 20);
		playerPointer = &player;

		bool attackFirst;
		attackFirst = battleGo.calcTurn(player.getSpeed(), monsterExample.getBaseSpeed());

		cout << "FIGHT\n\n";

		while (finishBattle == 1)
		{
			if (attackFirst == true)
			{
				cout << "Choose an option:\n";
				cout << "1 - Attack 2 - Run\n";
				cin >> choice;
				if (choice == 1)
				{
					battleGo.damageDone(monsterPointer, playerPointer, attackFirst);
					attackFirst = false;
				}

				else if (choice == 2)
				{
					cout << "\n" << player.getName() << " has ran away!\n";
					finishBattle = 0;
				}
				//cout << "Player attacks!";
				if (monsterExample.getHealth() <= 0)
				{
					cout << "\n" << player.getName() << " has won!\n";
					player.setExp(monsterExample.getExpKill());
					player.checkLvL();
					item winitem("random item", rand(), "meduim", "potion", 0, rand());
					playerInventory.addItem(winitem);
					finishBattle = 0;
				}
			}

			else
			{
				battleGo.damageDone(monsterPointer, playerPointer, attackFirst);
				attackFirst = true;
				//cout << "Monster attacks!";
				if (player.getHealth() <= 0)
				{
					finishBattle = 0;
					cout << "The monster has defeated the player, much sadness, such pain, wow \n\n";
				}
			}

		}
		//short testExp = MonsterExample.calcExp();
		return 1;
	}


