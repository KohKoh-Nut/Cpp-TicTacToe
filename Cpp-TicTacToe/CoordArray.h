#ifndef COORDARRAY_H
#define COORDARRAY_H

//a class to store the array of coordinates
class CoordArray
{
private:
	//an array to store the coordinates and the frame
	static char coordWithFrame[5][5];

	//an array to store the coordinates
	static char coord[3][3];

public:
	//O or X
	static char symbol;

	static char getCoordinates(int row, int col, bool frame);

	static void setCoordinates(int row, int col);

	static void setSymbol();
};

#endif