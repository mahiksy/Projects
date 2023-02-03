#pragma once
#include <iostream>
#include <string>
#include "Ships.h"

using namespace std;

class Carrier: public Ships
{

public:
	Carrier();
	~Carrier();
	void fireWeapons();
};