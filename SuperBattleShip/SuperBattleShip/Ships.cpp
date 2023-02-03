#include"Ships.h"
#include <iostream>
#include <string>

using namespace std;

//desc: creating a default constructor.
//pre: class has been created.	'
//post: assigned values of "Default", false and 0 to name, placed and  hullpoints.

Ships::Ships()
{
	hullpoints = 0;
	name = "Default";
	placed = false;
}

//desc: destructor
Ships::~Ships()
{
	name = " ";
	hullpoints = -1;
	placed = false;
}

//desc: Accessor method for name
//pre: name has been assigned a value.
//post: we return  the value of name

const string Ships::getName()
{
	return name;
}

//desc: Accessor method for hullPoints
//pre: HullPoints has been assigned a value.
//post: we return  the value of hullPoints
const int Ships::getHullPoint()
{
	return hullpoints;
}

//desc: Accessor method for placed
//pre: HullPoints has been assigned a value.
//post: we return  the value of placed
const bool Ships::getPlaced()
{
	return placed;
}

//desc: mutators for name.
 //pre: n must be assigned a value.
 //post: name feild set to value of n.

void Ships::setName(string n)
{
	name = n;
}

//desc: mutators for Hullpoints
//pre: h must be assigned a value.
//post: Hullpoints feild set to value of h.

void Ships::setHullPoints(int h)
{
	hullpoints = h;
}

//desc: mutators for placed
//pre: p must be assigned a value.
//post: placed feild set to value of p.

void Ships::setPlaced(bool p)
{
	placed = p;
}

//desc: mutators for shooting
//pre: s must be assigned a value
//post: shoot field set to value of s.

void Ships::setShot(bool s)
{
	shot = s;
}

bool Ships::getShot()
{
	return shot;
}

void Ships::hit()
{
	hullpoints = hullpoints -1;
}