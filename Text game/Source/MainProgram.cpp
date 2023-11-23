#include "MainProgram.h"

#include <iostream>
#include <fstream>
#include <filesystem>

MainProgram::MainProgram()
{
	m_bRunning = true;
}

int MainProgram::run()
{
	m_title();
	std::cout << "Press [enter] to start\n";
	std::cin.get();

	m_displayReadMe();

	std::cout << "\nReady?";
	m_input();

	if (m_action == "no")
		m_bRunning = false;

	while (m_bRunning)
	{

	}

	std::cout << "Thanks for playing";

	return 0;
}

void MainProgram::m_title() const
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

void MainProgram::m_displayReadMe() const
{
	std::ifstream readMe("../Readme.txt");

	std::string line;
	while (getline(readMe, line))
	{
		std::cout << line << '\n';
	}

	readMe.close();
}

void MainProgram::m_input()
{
	std::cout << "\n>";

	std::cin >> m_action;

	for (char& i: m_action)
	{
		i = tolower(i);
	}
}