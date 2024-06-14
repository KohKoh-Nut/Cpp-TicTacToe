#ifndef IOERROR_H
#define IOERROR_H

#include "CoordArray.h"
#include <iostream>

//a class for input and output
class IOError
{
public:
	static int row;
	static int col;

	static void inputUser();

	static void outputCoordinates();

	static void outputResult(bool tie, char ox);
	
	static void error();
};

#endif