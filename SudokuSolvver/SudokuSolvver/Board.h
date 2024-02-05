#pragma once
class Board
{
private:
	int** theBoard;
public:
	Board();
	void setBoard();
	void setBoard(int values[9][9]);
	bool checkRow(int theRow, int theVal);
	bool checkCol(int theCol, int theVal);
	bool checkBox(int theRow, int theCol, int theVal);
	bool buildBoard(int theRow, int theCol);
	void printBoard();
};