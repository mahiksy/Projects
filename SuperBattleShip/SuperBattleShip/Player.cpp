#include "Player.h"
#include "Types.h"
#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

	//desc: creating a parameterized consturctor with some defualt values
	//pre: n has been assinged a value
	//post: name must be assign to the value of n
	Player::Player(string n)
{
	name = n;
	score = 0;
	ships = 0;
	tacNuke = true;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			fleet[i][j] = ' ';
		}
	}
	for (int i = 0; i < 10; i++)
	{
			for (int j = 0; j < 10; j++)
			{
				enemy[i][j] = ' ';
			}
	}
}

	//desc: creating destructor
	//pre: the object exists
	//past: the fields of the object are returned and object marked for deletion
	Player::~Player()
{
	name = " ";
	score = -1;
	ships = -1;
	tacNuke = false;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			enemy[i][j] = ' ';
		}
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			fleet[i][j] = ' ';
		}
	}
}

	//desc: decrements ships number by 1 each time it is called.
	//pre: ships needs to be known and has a value.
	//post: ships number needs to be decremented by 1.
	void Player::setShips()
	{
		ships = ships - 1;
	}

	ptr_to_arr Player::getFleet()
	{
		return fleet;
	}

	//desc: accessor method for a secific member of fleet
	//pre: fleet has been assigned values.
	//post: we return the value stored at that specific address
	const char Player::getFleet(int r, int c)
	{
		return fleet[r][c];
	}

	//desc: accessor method for enemy
	//pre: enemy has been assigned values.
	//post: we return enemy
	ptr_to_arr Player::getEnemy()
	{
		return enemy;
	}

	//desc: printing the board game
	//pre: none
	//post: printing the board with required information

	void Player::printBoard(char board[10][10])
	{
		int array[10] = { 0,1,2,3,4,5,6,7,8,9 };
		cout << "Name: " << name << setw(10) << "Score: " << score << endl;
		cout << "  " << endl;
		cout << setw(5) << "A" << setw(4) << "B" << setw(4) << "C" << setw(4) << "D" << setw(4) << "E" << setw(4) << "F"
			<< setw(4) << "G" << setw(4) << "H" << setw(4) << "I" << setw(4) << "J" << endl;

		for (int i = 0; i < 10; i++)
		{
			cout << " ------------------------------------------" << endl;
			cout << array[i];
			for (int j = 0; j < 10; j++)
			{
				cout << " | " << board[i][j];
			}
			cout << endl;
		}
		cout << " ------------------------------------------" << endl;
		cout << CV.getName() << " : " << CV.getHullPoint() << setw(20) << BB.getName() << " : " << BB.getHullPoint() << endl;
		cout << DD.getName() << " : " << DD.getHullPoint() << setw(20) << SB.getName() << " : " << SB.getHullPoint() << endl;
		cout << PT.getName() << " : " << PT.getHullPoint() << endl;
	}

	//desc: checks if the set of postions are empty
	//pre: size, x , y and direction has been assigned
	//post: return the resualt (ture or false)
	bool Player::checkEmpty(int size, int x, int y, char direction)
	{
		if (direction == 'H')
		{
			for (int i = x; i < x + 1 + size; i++)
			{
				if (fleet[i][y] == ' ')
				{
					return true;
				}
				else
				{
					return false;
					break;
				}
			}
		}
		if (direction == 'V')
		{
			for (int i = y; i < y + 1 + size; i++)
			{
				if (fleet[x][i] == ' ')
				{
					return true;
				}
				else
				{
					return false;
					break;
				}
			}
		}
	}

	//desc: checks if the chosen index is vlaid or not
	//pre: ship, x, y, and direction have been assigned a value
	//post: return the resualt if it is false and calls checkEmpty if it is true
	bool Player::validPlacement(char ship, int x, int y, char direction)
	{
		char ships[5] = { 'C','B','D','S','P' };
		int points[5] = { 5,4,3,3,2 };
		for (int i=0; i < 5; i++)
		{
			ships[i];
			if (ships[i] == ship)
			{
				if (direction == 'V')
				{
					if (x + points[i] > 10)
					{
						cout << "incorrect" << endl;
						return false;
					}
					else
					{
						cout << "correct" << endl;
						return checkEmpty(points[i], x, y, direction);
					}
				}
				if (direction == 'H')
				{
					if (y + points[i] > 10)
					{
						return false;
					}
					else
					{
						return checkEmpty(points[i], x, y, direction);
					}
					break;
				}
			}
		}
	}

	//desc: mark the chosen indexes with the correct character
	//pre: ship, x, y, and direction have been assinged values
	//post: replacing the correct character in the chosen indexes and print the board
	void Player::markShip(char ship, int x, int y, char direction)
	{
		char ships[5] = { 'C','B','D','S','P' };
		int points[5] = { 5,4,3,3,2 };

		for (int i = 0; i < 5; i++)
		{
			ships[i];
			if (ships[i] == ship)
			{
				if (direction == 'V')
				{
					for (int j = x; j < x + points[i]; j++)
					{
						fleet[j][y] = ships[i];
					}
					printBoard(fleet);
				}
				if (direction == 'H')
				{
					for (int j = y; j < y + points[i]; j++)
					{
						fleet[x][j] = ships[i];
					}
					printBoard(fleet);
				}
				break;
			}
		}
	}

	//desc: converting char to int
	//pre: letter has been assigned a vlue
	//post: returning an correct integer based on letter
	int Player::converLetterToInt(char letter)
	{
		char letters[10] = { 'A','B','C','D','E','F','G','H','I','J' };
		int number[10] = { 0,1,2,3,4,5,6,7,8,9 };
		int column;

		for (int i = 0; i < 10; i++)
		{
			if (letters[i] == letter)
			{
				column = number[i];
				return column;
				break;
			}
			
		}
	}


	//desc: Placing the ships on the fleet board
	//pre: fleet board must be assigned
	//post: ships must be placed proparly on the fleet board
	void Player::placeShips()
	{
		int row;
		char letter;
		char direct;
		char shipChar[5] = { 'C','B','D','S','P' };
		int size[5] = { 5,4,3,3,2 };
		int chosenShip;
		int repeat = 0;

		cout << name << endl;
		cout << "You need to place 5 ships and you choose which ship you want to place on fleetBoard each time." << endl;
		for (int sSize = 5; sSize>0;sSize--)
		{
				do
				{	
					cout << "Which ship do you want to place? (1-5)" << endl;
					cout << "1.Carrier  2.BattleShip  3.Destroyer  4.Sumarine  5.PTBoat" << endl;
					cin >> chosenShip;

					if(chosenShip<5 && chosenShip>0)
						repeat = 0;
					if (chosenShip > 5 || chosenShip < 1)
					{
						repeat = 1;
						cout << "Invalid number!" << endl;
					}
					
					if (chosenShip == 1 && CV.getPlaced() == true)
					{
						repeat = 1;
						cout << "You have already placed this ship." << endl;
					}
					if (chosenShip == 2 && BB.getPlaced() == true)
					{
						repeat = 1;
						cout << "You have already placed this ship." << endl;
					}
					if (chosenShip == 3 && DD.getPlaced() == true)
					{
						repeat = 1;
						cout << "You have already placed this ship." << endl;
					}
					if (chosenShip == 4 && SB.getPlaced() == true)
					{
						repeat = 1;
						cout << "You have already placed this ship." << endl;
					}
					if (chosenShip == 5 && PT.getPlaced() == true)
					{
						repeat = 1;
						cout << "You have already placed this ship." << endl;
					}
				} while (repeat ==1);

					
				if (chosenShip == 1 && CV.getPlaced() == false)
					cout << "Carrier" << endl;
				if (chosenShip == 2 && BB.getPlaced() == false)
					cout << "Battleship" << endl;
				if (chosenShip == 3 && DD.getPlaced() == false)
					cout << "Destroyer" << endl;
				if (chosenShip == 4 && SB.getPlaced() == false)
					cout << "Submarine" << endl;
				if (chosenShip == 5 && PT.getPlaced() == false)
					cout << "PTBoat" << endl;

				cout << "Please enter an integer form 0-9: " << endl;
				cin >> row;
				while (row > 9 || row < 0)
				{
					cout << "Invalid! Try again1" << endl;
					cout << "Please enter an integer form 0-9: " << endl;
					cin >> row;
				}
				cout << "Please enter an letter form A-J: " << endl;
				cin >> letter;
				while (letter != 'A' && letter != 'B' && letter != 'C'
					&& letter != 'D' && letter != 'E' && letter != 'F' &&
					letter != 'G' && letter != 'H' && letter != 'I' && letter != 'J')
				{
					cout << "invalid!Try agian" << endl;
					cout << "Please enter an letter form A-J: " << endl;
					cin >> letter;
				}
				cout << "Please enter a direction:(H for horizontal or V for vertical)" << endl;
				cin >> direct;
				while (direct != 'V' && direct != 'H')
				{
					cout << "invalid! Please enter a direction:(H for horizontal or V for vertical)" << endl;
					cin >> direct;
				}
				checkEmpty(size[chosenShip - 1], row, converLetterToInt(letter), direct);
				if (false == checkEmpty(size[chosenShip - 1], row, converLetterToInt(letter), direct))
				{
					cout << "It is not emplty! Choose other values" << endl;
					cout << "Please enter an integer form 0-9 :" << endl;
					cin >> row;
					cout << "Please enter an letter form A-J:" << endl;
					cin >> letter;
					cout << " Please enter a direction (H for horizontal or V for vertical) :" << endl;
					cin >> direct;
				}
				validPlacement(shipChar[chosenShip - 1], row, converLetterToInt(letter), direct);
				if (false == validPlacement(shipChar[chosenShip - 1], row, converLetterToInt(letter), direct))
				{
					cout << "It does not fit! Choose other values" << endl;
					cout << "Please enter an integer form 0-9:" << endl;
					cin >> row;
					cout << "Please enter an letter form A-J:" << endl;
					cin >> letter;
					cout << "invalid! Please enter a direction:(H for horizontal or V for vertical)" << endl;
					cin >> direct;
				}
				markShip(shipChar[chosenShip - 1], row, converLetterToInt(letter), direct);
				ships = ships + 1;
				if (chosenShip == 1)
				{
					CV.setPlaced(true);
				}
				if (chosenShip == 2)
				{
					BB.setPlaced(true);
				}
				if (chosenShip == 3)
				{
					DD.setPlaced(true);
				}
				if (chosenShip == 4)
				{
					SB.setPlaced(true);
				}
				if (chosenShip == 5)
				{
					PT.setPlaced(true);
				}
				
		}
	}

	//desc: checking weather shot is accurate or not
	//pre: x and y has been assigned a value
	//post: ??
	bool Player::validShot(int x, int y)
	{
		if (x >= 0 && x <= 9 && y >= 0 && y <= 9 && enemy[x][y] == ' ')

			return true;
		else
			return false;
	}

//desc: finding out weather the chosen index hits a ship or not.
//pre: x and y and &p must be known
//post: if hit: print x on enemyboard and increment 10 point to score
//      if miss: print o on enemyboard and print out a message
//      if ship sunk, decrement enemy's ships num by 1 and print out the msg

	void Player::markResult(int x, int y, Player& p)
	{
		if (enemy[x][y] == ' ')
		{
			if (p.fleet[x][y] == 'C')
			{
				enemy[x][y] = 'X';
				cout << "Hit!" << endl;
				p.CV.hit();
				score = score + 10;
				if (p.CV.getHullPoint()==0)
				{
					cout << "Enemy " << CV.getName() << " Sunk!" << endl;
					p.setShips();
					
				}
			}
			if (p.fleet[x][y] == 'B')
			{
				enemy[x][y] = 'X';
				cout << "Hit!" << endl;
				p.BB.hit();
				score = score + 10;
				if (p.BB.getHullPoint() == 0)
				{
					cout << "Enemy " << BB.getName() << " Sunk!" << endl;
					p.setShips();
					
				}
			}
			if (p.fleet[x][y] == 'D')
			{
				enemy[x][y] = 'X';
				cout << "Hit!" << endl;
				p.DD.hit();
				score = score + 10;
				if (p.DD.getHullPoint() == 0)
				{
					cout << "Enemy " << DD.getName() << " Sunk!" << endl;
					p.setShips();
				}
			}
			if (p.fleet[x][y] == 'S')
			{
				enemy[x][y] = 'X';
				cout << "Hit!" << endl;
				p.SB.hit();
				score = score + 10;
				if (p.SB.getHullPoint() == 0)
				{
					cout << "Enemy " << SB.getName() << " Sunk!" << endl;
					p.setShips();
				}
			}
			if (p.fleet[x][y] == 'P')
			{
				enemy[x][y] = 'X';
				cout << "Hit!" << endl;
				p.PT.hit();
				score = score + 10;
				if (p.PT.getHullPoint() == 0)
				{
					cout << "Enemy " << PT.getName() << " Sunk!" << endl;
					p.setShips();
				}
			}
			if (p.fleet[x][y] == ' ')
			{
				enemy[x][y] = 'O';
				cout << "Miss!" << endl;
			}
		}
	}

	//desc: firing process
	//pre: needs to have access to enemy's player fleet board
	//post: based on enemy's fleetboard, player's enemybaord needs to be marked x or o.
	void Player::fire(Player& p)
	{
		int row;
		char column;
		char nuke;
		int count;
		bool check;

		if (tacNuke == true && ships < 3)
		{
			if (SB.getHullPoint() > 0 || CV.getHullPoint() > 3)
			{
				cout << "Do you want to use your Nuke Shot? (Y/ N)" << endl;
				cin >> nuke;
				if (nuke == 'Y')
				{
					cout << "You need to choose the directions for the center of the Nuke shot." << endl;
					do
					{
						cout << "Please enter an integer form 0 - 9 for row :" << endl;
						cin >> row;
						while (row > 9 || row < 0)
						{
							cout << "Invalid Number! Please enter an integer form 0 - 9 for row :" << endl;
							cin >> row;
						}
						cout << "Please enter a letter form A-J for column :" << endl;
						cin >> column;
						while (column != 'A' && column != 'B' && column != 'C'
							&& column != 'D' && column != 'E' && column != 'F' &&
							column != 'G' && column != 'H' && column != 'I' && column != 'J')
						{
							cout << "Invalid letter! Please enter a letter form A-J for column : " << endl;
							cin >> column;
						}

						converLetterToInt(column);
						checkNuke(row, converLetterToInt(column));
						if (checkNuke(row, converLetterToInt(column)) == true)
						{
							detonate(row, converLetterToInt(column), p);
							tacNuke = false;
							printBoard(enemy);
						}
						if (checkNuke(row, converLetterToInt(column)) == false)
						{
							cout << "It does not fit in the board! Please choose other values: " << endl;
						}
					} while (checkNuke(row, converLetterToInt(column)) == false);
				}
				if (nuke != 'Y' && nuke != 'N')
				{
					cout << "Invalid Letter! Try Again:" << endl;
					cin >> nuke;
				}
				if (nuke == 'N')
				{
					cout << "Nuke is on standby." << endl;
				}

			}
			if (SB.getHullPoint() == 0 && CV.getHullPoint() < 2)
			{
				cout << "DO not have Carrier and Submarine to shoot nuke" << endl;
			}
		}
		for (int i = 1; i <= ships; i++)
		{
			if (i == 1)
			{
				if (CV.getHullPoint() != 0)
				{
					cout << "Carrier" << endl;
					CV.fireWeapons();
					CV.setShot(true);
				}
				else if (BB.getHullPoint() != 0 )
				{
					cout << "Battleship" << endl;
					BB.fireWeapons();
					BB.setShot(true);
				}
				else if (DD.getHullPoint() != 0)
				{
					cout << "Destroyer" << endl;
					DD.fireWeapons();
					DD.setShot(true);
				}
				else if (SB.getHullPoint() != 0 )
				{
					cout << "Submarine" << endl;
					SB.fireWeapons();
					SB.setShot(true);
				}
				else if (PT.getHullPoint() != 0 )
				{
					cout << "PTBoat" << endl;
					PT.fireWeapons();
					PT.setShot(true);
				}
			}
			if (i == 2)
			{
				if (BB.getHullPoint() != 0 && BB.getShot() == false)
				{
					cout << "Battleship" << endl;
					BB.fireWeapons();
					BB.setShot(true);
				}
				else if (DD.getHullPoint() != 0 )
				{
					cout << "Destroyer" << endl;
					DD.fireWeapons();
					DD.setShot(true);
				}
				else if (SB.getHullPoint() != 0 )
				{
					cout << "Submarine" << endl;
					SB.fireWeapons();
					SB.setShot(true);
				}
				else if (PT.getHullPoint() != 0 )
				{
					cout << "PTBoat" << endl;
					PT.fireWeapons();
					PT.setShot(true);
				}
			}
			if (i == 3)
			{
				if (DD.getHullPoint() != 0 && DD.getShot() == false)
				{
					cout << "Destroyer" << endl;
					DD.fireWeapons();
				}
				else if (SB.getHullPoint() != 0)
				{
					cout << "Submarine" << endl;
					SB.fireWeapons();
					SB.setShot(true);
				}
				else if (PT.getHullPoint() != 0)
				{
					cout << "PTBoat" << endl;
					PT.fireWeapons();
					PT.setShot(true);
				}
			}
			if (i == 4)
			{
					if (SB.getHullPoint() != 0 && SB.getShot() == false)
					{
						cout << "Submarine" << endl;
						SB.fireWeapons();
					}
					else if (PT.getHullPoint() != 0 )
					{
						cout << "PTBoat" << endl;
						PT.fireWeapons();
						PT.setShot(true);
					}
			}

			if (i == 5)
			{
					if (PT.getHullPoint() != 0 && PT.getShot() == false)
						cout << "PTBoat" << endl;
					PT.fireWeapons();
			}
			do
			{
				cout << "Please enter an integer form 0 - 9 for row :" << endl;
				cin >> row;
				while (row > 9 || row < 0)
				{
					cout << "Invalid Number! Please enter an integer form 0 - 9 for row :" << endl;
					cin >> row;
				}
				cout << "Please enter a letter form A-J for column :" << endl;
				cin >> column;
				while (column != 'A' && column != 'B' && column != 'C'
					&& column != 'D' && column != 'E' && column != 'F' &&
					column != 'G' && column != 'H' && column != 'I' && column != 'J')
				{
					cout << "Invalid letter! Please enter a letter form A-J for column :" << endl;
					cin >> column;
				}

				converLetterToInt(column);
				validShot(row, converLetterToInt(column));
				if (validShot(row, converLetterToInt(column)) == true)
				{
					check = true;
					markResult(row, converLetterToInt(column), p);
				}
				else
				{
					check = false;
					cout << "This spot has already been chosen. Please choose other spot." << endl;
				}
			} while (check == false);
		}
		CV.setShot(false);
		BB.setShot(false);
		DD.setShot(false);
		PT.setShot(false);
		SB.setShot(false);
		printBoard(enemy);
	}
		

	//desc: checks if one of the players is winner
	//pre: score has been assigned a value
	//post: returns true for win and flase if we do not have a winner yet.
	bool Player::checkIfWon()
	{
		if (score == 170)
		{
			cout << "~~~Player " << name << " is Victorious!~~~" << endl;
			return true;
		}
		else
		{
			return false;
		}

	}

	void Player::detonate(int x, int y, Player& p) 
	{
		if (enemy[x][y] == ' ')
			markResult(x, y, p);
		if (enemy[x-2][y-2] == ' ')
			markResult(x-2, y-2, p);
		if (enemy[x-2][y] == ' ')
			markResult(x-2, y, p);
		if (enemy[x-2][y+2] == ' ')
			markResult(x-2, y+2, p);
		if (enemy[x-1][y-1] == ' ')
			markResult(x-1, y-1, p);
		if (enemy[x-1][y+1] == ' ')
			markResult(x-1, y+1, p);
		if (enemy[x+1][y-1] == ' ')
			markResult(x+1, y-1, p);
		if (enemy[x+1][y+1] == ' ')
			markResult(x+1, y+1, p);
		if (enemy[x+2][y-2] == ' ')
			markResult(x+2, y-2, p);
		if (enemy[x+2][y] == ' ')
			markResult(x+2, y, p);
		if (enemy[x+2][y+2] == ' ')
			markResult(x+2, y+2, p);
	}
	bool Player::checkNuke(int x, int y)
	{
		if (x - 2 >= 0 && x + 2 <= 10 && y - 2 >= 0 && y + 2 <= 10)
		{	
			return true;
		}
		else
			return false;
	}