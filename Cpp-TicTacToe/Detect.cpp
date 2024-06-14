#include "Detect.h"

bool Detect::detectViability()
{
	if (IOError::row > 2 || IOError::row < 0 || IOError::col > 2 || IOError::col < 0)
		return 1;
	return 0;
}

bool Detect::detectRepeated()
{
	if (CoordArray::getCoordinates(IOError::row, IOError::col, false) != ' ')
		return 1;
	return 0;
}

void Detect::detectWinLose()
{
	if ( condition(0,'r') || condition(1, 'r') || condition(2, 'r') ||
		condition(0, 'c') || condition(1, 'c') || condition(2, 'c') ||
		condition(0, 'd') || condition(0, 'i') )
		IOError::outputResult(false, CoordArray::symbol);

	CoordArray::setSymbol();
}

bool Detect::condition(int rowCol, char rowColDiag)
{
	switch (rowColDiag)
	{
	case 'r':
		return (
			CoordArray::getCoordinates(rowCol, 0, false) == CoordArray::getCoordinates(rowCol, 1, false) &&
			CoordArray::getCoordinates(rowCol, 0, false) == CoordArray::getCoordinates(rowCol, 2, false) &&
			CoordArray::getCoordinates(rowCol, 0, false) != ' '
			);
		break;

	case 'c':
		return (
			CoordArray::getCoordinates(0, rowCol, false) == CoordArray::getCoordinates(1, rowCol, false) &&
			CoordArray::getCoordinates(0, rowCol, false) == CoordArray::getCoordinates(2, rowCol, false) &&
			CoordArray::getCoordinates(0, rowCol, false) != ' '
			);
		break;

	case 'd':
		return (
			CoordArray::getCoordinates(0, 0, false) == CoordArray::getCoordinates(1, 1, false) &&
			CoordArray::getCoordinates(0, 0, false) == CoordArray::getCoordinates(2, 2, false) &&
			CoordArray::getCoordinates(0, 0, false) != ' '
			);
		break;

	case 'i':
		return (
			CoordArray::getCoordinates(0, 2, false) == CoordArray::getCoordinates(1, 1, false) &&
			CoordArray::getCoordinates(0, 2, false) == CoordArray::getCoordinates(2, 0, false) &&
			CoordArray::getCoordinates(0, 2, false) != ' '
			);
		break;
	}

	return false;
}