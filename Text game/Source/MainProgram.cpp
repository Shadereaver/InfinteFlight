#include "MainProgram.h"

#include <iostream>
#include <fstream>

MainProgram::MainProgram()
{
	bRunning = true;
}

int MainProgram::run()
{
	title();
	std::cout << "Press [enter] to start\n";
	std::cin.get();

	displayReadMe();

	while (bRunning)
	{

	}

	return 0;
}

void MainProgram::title() const
{
	std::cout << " _____          __  _         _  _            __  _  _         _      _\n"
			  << "|_   _|        / _|(_)       (_)| |          / _|| |(_)       | |    | |\n"
			  << "  | |   _ __  | |_  _  _ __   _ | |_   ___  | |_ | | _   __ _ | |__  | |_\n"
			  << "  | |  | '_ \\ |  _|| || '_ \\ | || __| / _ \\ |  _|| || | / _` || '_ \\ | __|\n"
			  << " _| |_ | | | || |  | || | | || || |_ |  __/ | |  | || || (_| || | | || |_\n"
			  << " \\___/ |_| |_||_|  |_||_| |_||_| \\__| \\___| |_|  |_||_| \\__, ||_| |_| \\__|\n"
			  << "                                                         __/ |\n"
			  << "                                                        |___/\n\n";
}

void MainProgram::displayReadMe() const
{
	std::ifstream readMe;

	readMe.open("../../Readme.txt");

	if (readMe.fail())
		std::cout << "bob";

	std::string line;
	while (getline(readMe, line))
	{
		std::cout << line << '\n';
	}

	readMe.close();
}

void MainProgram::input()
{
	std::cout << "\n>";

	std::cin >> action;
}