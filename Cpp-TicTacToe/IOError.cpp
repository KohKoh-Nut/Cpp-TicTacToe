#include "IOError.h"

int IOError::row;
int IOError::col;

void IOError::inputUser()
{
	std::cout << "Row:\t";
	std::cin >> row;
	std::cout << "Column:\t";
	std::cin >> col;
}

void IOError::outputCoordinates()
{
	int rowFrame{}, colFrame{};
	for (rowFrame = 0; rowFrame < 5; rowFrame++)
	{
		for (colFrame = 0; colFrame < 5; colFrame++)
			std::cout << CoordArray::getCoordinates(rowFrame, colFrame, true);
		std::cout << '\n';
	}
}

void IOError::outputResult(bool tie,char ox)
{
	if (tie)
		std::cout << "It's a tie.";
	else
		std::cout << ox << " side wins.";

	system("pause");
	exit(0);
}

void IOError::error()
{
	std::cout << "Error. \n\n";
}