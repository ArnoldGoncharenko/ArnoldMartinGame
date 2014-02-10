#include "Item.h"
#include <iostream>
#include <string>

using namespace std;

namespace GameCore
{

	item::item(string itemNameTemp, short value, string size, string type, short damage, short durability)
	{
		itemName = itemNameTemp;
		itemValue = value;
		itemSize = size;
		itemType = type;
		itemDamage = damage;
		itemDurability = durability;
	}

	item::item()
	{
		itemName = " ";
		itemValue = 0;
		itemSize = "small";
		itemType = "default";
		itemDamage = 0;
		itemDurability = 1;
	}

	string item::getItemName()
	{
		return itemName;
	}

	short item::getItemValue()
	{
		return itemValue;
	}

	string item::getItemSize()
	{
		return itemSize;
	}

	string item::getType()
	{
		return itemSize;
	}

	short item::getDamage()
	{
		return itemDamage;
	}

	short item::getDurability()
	{
		return itemDurability;
	}
}