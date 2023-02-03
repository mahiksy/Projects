#pragma once
#include <iostream>
#include <string>

using namespace std;

class Ships 
{
	private:
		string name;
		int hullpoints;
		bool placed;
		bool shot;
	public:
		Ships();
		~Ships();
		const string getName();
		const int getHullPoint();
		const bool getPlaced();
		void setName(string n);
		void setHullPoints(int h);
		void setPlaced(bool p);
		void setShot(bool s);
		bool getShot();
		void hit();
		virtual void fireWeapons()=0;
};	