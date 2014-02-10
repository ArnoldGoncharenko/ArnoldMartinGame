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
	bool gameOn = true;
	cout << "Welcome to the land of Demonic Wizard Farmer." << endl;
	cout << "An evil Demonic Wizard Farmer has taken over" << endl;
	cout << "the world. Your task is to kill the Demonic" << endl;
	cout << "Wizard Farmer. Good luck." << endl;

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

	playerBase player(playerName, 100, 5, 5, 0, 10, 100);
	playerPointer = &player;

	//* stats variables
	short ptsToAttack = 0;
	short ptsToSpeed = 0;
	short ptsToHealth = 0;

	cout << "Assing your level points:" << endl;

	bool pointsAssigned = false;

	while (pointsAssigned == false) {
		cout << "You currently have " << player.getLvlPoints() << " points to assign. " << endl;
		cout << "You have " << player.getAttack() << " Points in strength. " << endl;
		cout << "How many points to Strength?" << endl; //attack
		cin >> ptsToAttack;

		if (ptsToAttack > player.getLvlPoints()) {
			cout << "You do not have enough points. ";
		}
		else {
			player.setAttack(player.getAttack() + ptsToAttack);
			cout << "Your Strength is now " << player.getAttack() << endl;
			pointsAssigned = true;
			player.setLvlPoints(player.getLvlPoints() - ptsToAttack);
			cout << "You now have " << player.getLvlPoints() << " points to assign." << endl;
			ptsToAttack = 0;

		}
	}

	pointsAssigned = false;

	while (pointsAssigned == false) {
		cout << "You have " << player.getSpeed() << " Points in agility. " << endl;
		cout << "How many points to Agility?" << endl; //speed
		cin >> ptsToSpeed;

		if (ptsToSpeed > player.getLvlPoints()) {
			cout << "You do not have enough points. " << endl;
		}
		else {
			player.setSpeed(player.getSpeed() + ptsToSpeed);
			cout << "Your speed is now " << player.getSpeed() << endl;
			pointsAssigned = true;
			player.setLvlPoints(player.getLvlPoints() - ptsToSpeed);
			cout << "You now have " << player.getLvlPoints() << " points to assign." << endl;
			ptsToSpeed = 0;
		}
	}

	pointsAssigned = false;
	while (pointsAssigned == false) {
		cout << "You have " << player.getMaxHealth() << " health points. " << endl;
		cout << "How many points to endurance? Each point adds 5 to health." << endl; //health
		cin >> ptsToHealth;

		if (ptsToHealth > player.getLvlPoints()) {
			cout << "You do no have enough points. " << endl;
		}
		else {
			player.setMaxHealth(player.getMaxHealth() + ptsToHealth * 5); // Each points adds 5 to health. Check if good.
			cout << "Your health is now " << player.getMaxHealth() << endl;
			player.setHealth(player.getMaxHealth());
			pointsAssigned = true;
			player.setLvlPoints(player.getLvlPoints() - ptsToHealth);
			cout << "You now have " << player.getLvlPoints() << " points to assign." << endl;
			ptsToHealth = 0;
		}
	}

	pointsAssigned = false;

	while (gameOn == true) {

		cout << "What would you like to do?" << endl;
		cout << "1 - Fight" << endl;
		cout << "2 - Exit" << endl;
		cout << "3 - Check Level" << endl;
		cout << "4 - Assign experience points\n" << endl;
		cout << "5 - View Inventory\n" << endl;

		cin >> choice;
		if (choice == 1) {
			finishBattle = 1;
		}

		else if (choice == 2) {
			gameOn = false;
		}
		else if (choice == 3) {
			cout << "\n" << "Level " << player.getLevel() << "\n" << endl;
		}
		else if (choice == 4) 
		{
			while (pointsAssigned == false) {
				cout << "You have " << player.getLvlPoints() << " points to assign." << endl;
				cout << "Would you like to assign to: " << endl;

				cout << "1 - Strength; 2 - Agility; 3 - Endurance; 4 - Stop assigning " << endl; // **** Choices

				short assignPts;
				cin >> assignPts;
				if (assignPts == 1) {
					cout << "You have " << player.getAttack() << " points in Strength" << endl;
					cout << "How much would you like to assign?" << endl;
					cin >> ptsToAttack;
					if (ptsToAttack > player.getLvlPoints()) {
						cout << "You do not have enough points" << endl;
					}
					else {
						player.setAttack(player.getAttack() + ptsToAttack);
						pointsAssigned = true;
						ptsToAttack = 0;
					}

				}
				else if (assignPts == 2) {
					cout << "You have " << player.getSpeed() << " points in Agility." << endl;
					cout << "How much would you like to assign?" << endl;
					cin >> ptsToSpeed;
					if (ptsToSpeed > player.getLvlPoints()) {
						cout << "You do not have enough points" << endl;
					}
					else {
						player.setSpeed(player.getSpeed() + ptsToSpeed);
						ptsToSpeed = 0;
						pointsAssigned = true;

					}
				}
				else if (assignPts == 3) {
					cout << "You have " << player.getMaxHealth() << " health Points." << endl;
					cout << "How much would you like to assign? ( each points is 5 HP )" << endl;
					cin >> ptsToHealth;
					if (ptsToHealth > player.getLvlPoints()) {
						cout << "You do not have enough points" << endl;
					}
					else {
						player.setMaxHealth(player.getMaxHealth() + ptsToHealth);
						ptsToHealth = 0;
						pointsAssigned = true;
					}
				}
				else if (assignPts == 4){
					pointsAssigned = true;
				}
				else {
					cout << "Invalid input. " << endl;
				}

			}
			pointsAssigned = false;

		}
		else if (choice == 5)
		{
			playerInventory.displayItems();
		}
		else 
		{
			cout << "Nope\n" << endl;
		}


		cout << "FIGHT\n\n";
		bool attackFirst;
		attackFirst = battleGo.calcTurn(player.getSpeed(), monsterExample.getBaseSpeed());

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
					item winItem("random item", rand(), "meduim", "potion", 0, rand());
					item * winItemPointer = &winItem;
					playerInventory.addItem(*winItemPointer);
					//delete winItemPointer;
					monsterExample.setBaseHealth(10);
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
}


