#ifndef DETECT_H
#define DETECT_H

#include "IOError.h"
#include "CoordArray.h"

//a class to detect
class Detect
{
public:
	//detect whether the coordinates are out of range
	static bool detectViability();

	//detect whether the coordinates are already used
	static bool detectRepeated();

	//detect whether someone has won
	static void detectWinLose();

	//the conditions for the detection of win lose
	static bool condition(int rowCol, char rowColDiag);
};

#endif