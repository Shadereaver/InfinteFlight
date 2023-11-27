#include "MainProgram.h"

#include <iostream>
#include <fstream>
#include <filesystem>

MainProgram::MainProgram()
{
	m_bRunning = true;
	m_title = R"( _____          __  _         _  _            __  _  _         _      _	)""\n"
			  R"(|_   _|        / _|(_)       (_)| |          / _|| |(_)       | |    |	|	)""\n"
			  R"(  | |   _ __  | |_  _  _ __   _ | |_   ___  | |_ | | _   __ _ | |__  | |_	)""\n"
			  R"(  | |  | '_ \ |  _|| || '_ \ | || __| / _ \ |  _|| || | / _` || '_ \ | __|	)""\n"
			  R"( _| |_ | | | || |  | || | | || || |_ |  __/ | |  | || || (_| || | | || |_	)""\n"
			  R"( \___/ |_| |_||_|  |_||_| |_||_| \__| \___| |_|  |_||_| \__, ||_| |_| \__|	)""\n"
			  R"(                                                         __/ |				)""\n"
			  R"(                                                        |___/				)""\n\n";
	m_action = "null";
	m_difficulty = eNormal;
}

int MainProgram::run()
{
	std::cout << m_title;
	std::cout << "Press [enter] to start\n";
	std::cin.get();

	m_displayReadMe();

	std::cout << "\nReady?";
	m_input();

	if (m_action == "no" || m_action == "quit")
		m_bRunning = false;

	for (int i = 0; i <= 5; ++i)
	{
		if (i == 5)
		{
			std::cout << "\nSeems you have trouble spelling so, I will set the difficulty to easy for you.";
			m_difficulty = eEasy;
		}
		else
		{
			std::cout << "\n"
						 "Pick a difficulty:\n"
						 "-Easy\n"
						 "-Normal\n"
						 "-Hard";
			m_input();
			
			if (m_action == "easy")
			{
				m_difficulty = eEasy;
				i = 6;
				break;
			}

			else if (m_action == "normal")
			{
				m_difficulty = eNormal;
				i = 6;
				break;
			}

			else if (m_action == "hard")
			{
				m_difficulty = eHard;
				i = 6;
				break;
			}

			else
				std::cout << "Incorrect\n";
		}
	}

	while (m_bRunning)
	{

	}

	std::cout << "-------------------\n"
			     "Thanks for playing!\n"
			     "-------------------";

	return 0;
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
