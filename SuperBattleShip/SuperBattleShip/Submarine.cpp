#include"Submarine.h"
#include <iostream>
#include <string>

using namespace std;

//desc: creating a default destructor.
//pre: class has been created.
//post: assigned values of "Carrier" and 5 to name and hullpoints.
Submarine::Submarine()
{
	setName("Submarine");
	setHullPoints(3);
	setPlaced(false);
}

//desc: creating destructor
//pre: the object exists
//past: the fields of the object are returned and object marked for deletion
Submarine::~Submarine()
{
	setName(" ");
	setHullPoints(-1);
	setPlaced(false);
}

//desc: prinitng out the fire msg
//pre: none
//post: the msg should be printed out for user.
void Submarine::fireWeapons()
{
	cout << "Bearing, set, match: Firing torpedos!" << endl;
}