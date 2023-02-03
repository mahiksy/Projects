#include"Carrier.h"
#include <iostream>
#include <string>

using namespace std;

//desc: creating a default destructor.
//pre: class has been created.
//post: assigned values of "Carrier" and 5 to name and hullpoints.
Carrier:: Carrier()
{
	setName("Carrier");
	setHullPoints(5);
	setPlaced(false);
}

//desc: creating destructor
//pre: the object exists
//past: the fields of the object are returned and object marked for deletion
Carrier::~Carrier()
{
	setName(" ");
	setHullPoints(-1);
	setPlaced(false);
}

//desc: prinitng out the fire msg
//pre: none
//post: the msg should be printed out for user.
void Carrier::fireWeapons()
{
	cout << "Launching planes for airstrike!" << endl;
}

