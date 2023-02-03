#pragma once
#include <iostream>
#include <string>
#include "Ships.h"

using namespace std;

class Destroyer : public Ships
{
public:
	Destroyer();
	~Destroyer();
	void fireWeapons();
};