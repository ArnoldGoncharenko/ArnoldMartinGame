#pragma once

#include<cstring>
#include <string>
#include <list>

using namespace std;

namespace GameCore
{
	class item
	{
		string itemName;
		short itemValue;
		string itemSize;
		string itemType;
		short itemDamage;
		short itemDurability;

	public:
		item(string, short, string, string, short, short);
		item();
		string getItemName();
		short getItemValue();
		string getItemSize();
		string getType();
		short getDamage();
		short getDurability();
	};
}