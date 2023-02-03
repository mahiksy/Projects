#include<iostream>
#include<string>
#include "player.h"

using namespace std;

int main()
{
	/*
	Player p2("p2");
	Player p1("P1");
	p1.placeShips();
	//p1.printBoard(p1.getFleet());
	p1.fire(p2);
	p1.checkNuke(1, 5);
	p1.checkNuke(5, 7);
	p1.markResult(5, 5, p2);
	p1.detonate(5, 5, p1);
	
	p1.setShips();
	p1.validPlacement('S', 9, 3, 'V');

	p1.printBoard(p1.getEnemy());
	*/
	// actual code//
	
	Player p1("P1");
	Player p2("P2");

	//Placing the ships
	p1.placeShips();
	p2.placeShips();

	//shooting porcess
	while (false == p1.checkIfWon() && false == p2.checkIfWon())
	{
		int currentPlayer = 1;

		if (currentPlayer == 1)
		{
			p1.printBoard(p1.getEnemy());
			p1.fire(p2);
			if (p1.checkIfWon() == true)
			{
				cout << "Player 1 is winner! THank you for playing" << endl;
				break;
			}
			else
				currentPlayer = 2;
		}
		if (currentPlayer == 2)
		{
			p2.printBoard(p2.getEnemy());
			p2.fire(p1);
			if (p2.checkIfWon() == true)
			{
				cout << "Player 2 is winner! Thank you for playing" << endl;
				break;
			}
			else
				currentPlayer = 1;
		}

	}

	system("Pause>0");
	return 0;

}
