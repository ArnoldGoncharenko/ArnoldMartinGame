#pragma once

#include<cstring>
#include <string>
#include <list>
#include "Item.h"

using namespace std;

namespace GameCore
{
	class weapon : item
	{
		short weaponDamage;
		short weaponDurability;
		short weaponArmorPen; //to be implemented with armor later

	public:
		weapon(short, short);
		weapon();
		void setDurability();
		void setDamage();
	};
}