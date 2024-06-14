#include "CoordArray.h"

char CoordArray::coordWithFrame[5][5] = {
	{' ', '/|', ' ', '/|', ' '},
	{'-', '+' , '-', '+' , '-'},
	{' ', '/|', ' ', '/|', ' '},
	{'-', '+' , '-', '+' , '-'},
	{' ', '/|', ' ', '/|', ' '},
};

char CoordArray::coord[3][3] = {
	{' ', ' ', ' '},
	{' ', ' ', ' '},
	{' ', ' ', ' '}
};

char CoordArray::symbol = 'O';

char CoordArray::getCoordinates(int row, int col, bool frame)
{
	if (frame)
		return coordWithFrame[row][col];

	return coord[row][col];
}

void CoordArray::setCoordinates(int row, int col)
{
	coord[row][col] = symbol;

	//sync both arrays
	coordWithFrame[0][0] = coord[0][0];
	coordWithFrame[0][2] = coord[0][1];
	coordWithFrame[0][4] = coord[0][2];

	coordWithFrame[2][0] = coord[1][0];
	coordWithFrame[2][2] = coord[1][1];
	coordWithFrame[2][4] = coord[1][2];

	coordWithFrame[4][0] = coord[2][0];
	coordWithFrame[4][2] = coord[2][1];
	coordWithFrame[4][4] = coord[2][2];
}

void CoordArray::setSymbol()
{
	if (symbol == 'O')
		symbol = 'X';
	else
		symbol = 'O';
}