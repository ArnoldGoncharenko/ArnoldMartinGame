#include "Inventory.h"
#include "Item.h"
#include <istream>
#include <iostream>
#include <list>
#include <string>
#include <cctype>

namespace GameCore
{

	Inventory::Inventory(short size)
	{
		item sword("Shitty sword", 100, "large", "Weapon", 10, 10);
		item* swordPointer = &sword;
		inventory.push_front(sword);
		//delete swordPointer;
		maxSize = size;
	}

	Inventory::Inventory()
	{
		maxSize = 10;
	}

	void Inventory::addItem(item temp)
	{
		if (inventory.size() < maxSize)
		{
			inventory.push_front(temp);
		}
	}

	void Inventory::removeItem(item temp)
	{
		if (inventory.size() > 0)
		{
			inventory.push_front(temp);
		}
	}

	void Inventory::sortItems()
	{
		if (inventory.size() < 0)
		{
			inventory.sort([](item & a, item & b)
			{
				return a.getItemName() < b.getItemName();
			});
		}
	}

	void Inventory::displayItems()
	{
		cout << "mylist contains: ";
		for (list<item>::iterator it = inventory.begin(); it != inventory.end(); ++it)
		{
			cout << *it << endl;
		}
	}

	ostream& operator<<(ostream& os, item& c)
	{
		return os << "\n\n Item name: " << c.getItemName() << "\n Durability: " << c.getDurability()
			<< "\n Item type: " << c.getType() << "\n Damage: " << c.getDamage();;
	}

}
