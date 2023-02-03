#pragma once

#include "Ships.h"
#include <iostream>
#include <string>

using namespace std;

class PTBoat : public Ships
{
public:
	PTBoat();
	~PTBoat();
	void fireWeapons();

};