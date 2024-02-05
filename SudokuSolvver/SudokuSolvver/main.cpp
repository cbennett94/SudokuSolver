#include "Board.h"
#include <iostream>
#include <limits>

class invalidInput {};

int main()
{
	int codedBoard[9][9] = { {5,3,0,0,7,0,0,0,0},
							{6,0,0,1,9,5,0,0,0},
							{0,9,8,0,0,0,0,6,0},
							{8,0,0,0,6,0,0,0,3},
							{4,0,0,8,0,3,0,0,1},
							{7,0,0,0,2,0,0,0,6},
							{0,6,0,0,0,0,2,8,0},
							{0,0,0,4,1,9,0,0,5},
							{0,0,0,0,8,0,0,7,9} };
	Board* gameBoard = new Board();
	int input = 0;
	do {
		input = 0;
		try {
			std::cout << "Enter 1 to hardcode the board\nEnter 2 to use the precoded board\n";
			std::cin >> input;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		catch (const invalidInput &)
		{
			std::cout << "Exception caught! \n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (!(input == 1 || input == 2));
	if (input == 1)
	{
		gameBoard->setBoard();
	}
	else
	{
		gameBoard->setBoard(codedBoard);
	}
	std::cout << "Original Board:\n";
	gameBoard->printBoard();
	gameBoard->buildBoard(0, 0);
	std::cout << "Completed Board:\n";
	gameBoard->printBoard();
	return 0;
}