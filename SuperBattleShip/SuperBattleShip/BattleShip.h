#pragma once
#include "Ships.h"
#include <iostream>
#include <string>

using namespace std;

class BattleShip: public Ships
{
public:
	BattleShip();
	~BattleShip();
	void fireWeapons();
	

};