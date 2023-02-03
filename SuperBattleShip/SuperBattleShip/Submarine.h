#pragma once

#include "Ships.h"
#include <iostream>
#include <string>

using namespace std;

class Submarine : public Ships
{
public:
	Submarine();
	~Submarine();
	void fireWeapons();

};