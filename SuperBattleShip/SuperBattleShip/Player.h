#pragma once
#include <iostream>
#include <string>
#include"BattleShip.h"
#include"Carrier.h"
#include"Destroyer.h"
#include"PTBoat.h"
#include"Submarine.h"
#include "Types.h"

using namespace std;

class Player
{
	private:
		string name;
		int score;
		int ships;
		char enemy[10][10];
		char fleet[10][10];
		bool tacNuke;
		Submarine SB;
		PTBoat PT;
		Destroyer DD;
		Carrier CV;
		BattleShip BB;
	public:
		Player(string n);
		~Player();
		void setShips();
		ptr_to_arr getFleet();
		ptr_to_arr getEnemy();
		const char getFleet(int r, int c);

		void printBoard(char board[10][10]);
		bool checkEmpty(int size, int x, int y, char direction);
		bool validPlacement(char ship, int x, int y, char direction);
		void markShip(char ship, int x, int y, char direction);
		int converLetterToInt(char letter);
		void placeShips();
		bool validShot(int x, int y);
		void markResult(int x, int y, Player& p);
		void fire(Player& p);
		bool checkIfWon();
		void detonate(int x, int y, Player& p);
		bool checkNuke(int x, int y);
};