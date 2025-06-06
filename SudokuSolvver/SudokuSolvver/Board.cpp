#include "Board.h"
#include <iostream>

//initializes the gameboard as a zeroed 2d array
Board::Board()
{
	//initialize the pointers of rows
	theBoard = new int*[9];
	for (int i = 0; i < 9; i++)
	{
		theBoard[i] = new int[9];
	}
	//initialize the pointers of columns
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			theBoard[i][j] = 0;
		}
	}
}

//prints out the game board in its current state
void Board::printBoard()
{
	//create intial spacing of the board
	std::cout << "_";
	for (int i = 65; i < 74; i++)
	{
		std::cout << char(i);
	}
	//print each row of the board
	std::cout << std::endl;
	for(int i = 0; i < 9; i++) {
		std::cout << char(65 + i);
		for (int j = 0; j < 9; j++) {
			std::cout << theBoard[i][j];
		}
		std::cout << std::endl;
	}
}

//transfer the values of a 2d array to theBoard
void Board::setBoard(int values[9][9])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			theBoard[i][j] = values[i][j];
		}
	}
}

//allows the person to enter a value for each space of the board
void Board::setBoard()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			std::cout << "Enter value for Row " << i+1 << " and Col " << j+1 << ": ";
			std::cin >> theBoard[i][j];
		}
	}
}

//checks the number of times a value appears in a specific row
bool Board::checkRow(int theRow, int theVal)
{
	//used to check if the value appears
	bool found = false;
	//iterate through each element in the specified row to check for the desired val
	for (int i = 0; i < 9; i++)
	{
		if (theBoard[theRow][i] == theVal)
		{
			found = true;
			break;
		}
	}
	return found;
}

//checks the number of times a value appears in a specific column
bool Board::checkCol(int theCol, int theVal)
{
	//used to check if the value appears
	bool found = false;
	//iterate through each element in the specified col to check for the desired val
	for (int i = 0; i < 9; i++)
	{
		if (theBoard[i][theCol] == theVal)
		{
			found = true;
			break;
		}
	}
	return found;
}

//checks the number of times a value appears in a specific box
bool Board::checkBox(int theRow, int theCol, int theVal)
{
	//used to detrmine which box of the sudoku board we are in
	//will handle traversing that box next
	int rowBox = 0;
	int colBox = 0;
	//check for the row location
	if(theRow <= 2)
	{
		rowBox = 0;
	}
	else if (theRow <= 5)
	{
		rowBox = 3;
	}
	else
	{
		rowBox = 6;
	}
	//check for the column location
	if (theCol <= 2)
	{
		colBox = 0;
	}
	else if (theCol <= 5)
	{
		colBox = 3;
	}
	else
	{
		colBox = 6;
	}
	//go through the box to check the number of times that the value appears
	//start in the topleft corner of the box, iterate through rows then columns
	//used to check if the value appears
	bool found = false;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (theBoard[rowBox+i][colBox+j] == theVal)
			{
				found = true;
				break;
			}
		}
	}
	return found;
}

//backtracking to build the sudoku board

bool Board::buildBoard(int theRow, int theCol)
{
	if(theRow > 8)
	{
		return true;
	}
	//to handle if there is already a value in the sqaure to start
	if (theBoard[theRow][theCol] != 0)
	{
		return theCol + 1 > 8 ? buildBoard(theRow + 1, 0) : buildBoard(theRow, theCol + 1);
	}
	//the space is empty
	else
	{
		//we need to loop through the values 1-9 to try to place them
		for (int i = 1; i < 10; i++)
		{
			//check to make sure none of the row, col, or box rules are violated
			if (!(checkRow(theRow, i) || checkCol(theCol, i) || checkBox(theRow, theCol, i)))
			{
				theBoard[theRow][theCol] = i;
				bool next = theCol + 1 > 8 ? buildBoard(theRow + 1, 0) : buildBoard(theRow, theCol + 1);
				if (next)
				{
					return true;
				}
				else
				{
					theBoard[theRow][theCol] = 0;
				}
			}
		}
		return false;
	}
}