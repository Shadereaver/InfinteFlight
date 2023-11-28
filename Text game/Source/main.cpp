#include "MainProgram.h"

#include <iostream>

int main()
{
	MainProgram mainProgram;
	int programReturnCode = 1;

	while (programReturnCode == 1)
	{
		programReturnCode = mainProgram.run();
	}

	return 0;
}