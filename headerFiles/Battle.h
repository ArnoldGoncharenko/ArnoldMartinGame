#pragma once

#include <cstring>
#include <string>
#include "Monster.h"
#include "Player.h"

namespace GameCore
{
	class battle
	{

	public:
		battle();
		~battle();
		bool calcTurn(short, short);
		void damageDone(monsterBase*, playerBase*, bool);
	};
}
