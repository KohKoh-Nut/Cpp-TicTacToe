#include "IOError.h"
#include "Detect.h"

int main()
{
	for (int i{ 0 }; i <9;)
	{
		IOError::inputUser();

		if (Detect::detectViability() || Detect::detectRepeated()) //if it's not viable
			IOError::error();
		else 
		{
			CoordArray::setCoordinates(IOError::row, IOError::col);
			IOError::outputCoordinates();
			Detect::detectWinLose();
			i++;
		}
	}

	IOError::outputResult(true, ' ');

	return 0;
}