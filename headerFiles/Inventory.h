#pragma once

#include<cstring>
#include <string>
#include <list>
#include "Item.h"
#include <iosfwd>

using namespace std;

namespace GameCore
{
	class Inventory
	{
		list<item> inventory;
		short maxSize;

	public:
		Inventory(short);
		Inventory();
		void addItem(item);
		void removeItem(item);
		void sortItems();
		void displayItems();
	};

	extern ostream& operator<< (ostream&, item&);
}