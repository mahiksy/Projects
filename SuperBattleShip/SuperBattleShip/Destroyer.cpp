#include"Destroyer.h"
#include <iostream>
#include <string>

using namespace std;

//desc: creating a default destructor.
//pre: class has been created.
//post: assigned values of "Carrier" and 5 to name and hullpoints.
Destroyer::Destroyer()
{
	setName("Destroyer");
	setHullPoints(3);
	setPlaced(false);
}

//desc: //desc: creating destructor
//pre: the object exists
//past: the fields of the object are returned and object marked for deletion
Destroyer::~Destroyer()
{
	setName(" ");
	setHullPoints(-1);
	setPlaced(false);
}

//desc: prinitng out the fire msg
//pre: none
//post: the msg should be printed out for user.
void Destroyer::fireWeapons()
{
	cout << "Launching depthcharges!Boom goes the dynamite!" << endl;
}