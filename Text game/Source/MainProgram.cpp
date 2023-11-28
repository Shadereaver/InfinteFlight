#include "MainProgram.h"

#include <iostream>
#include <fstream>
#include <filesystem>

MainProgram::MainProgram()
{
	m_bRunning = false;
	m_title = R"( _____          __  _         _  _            __  _  _         _      _	)""\n"
			  R"(|_   _|        / _|(_)       (_)| |          / _|| |(_)       | |    |	|	)""\n"
			  R"(  | |   _ __  | |_  _  _ __   _ | |_   ___  | |_ | | _   __ _ | |__  | |_	)""\n"
			  R"(  | |  | '_ \ |  _|| || '_ \ | || __| / _ \ |  _|| || | / _` || '_ \ | __|	)""\n"
			  R"( _| |_ | | | || |  | || | | || || |_ |  __/ | |  | || || (_| || | | || |_	)""\n"
			  R"( \___/ |_| |_||_|  |_||_| |_||_| \__| \___| |_|  |_||_| \__, ||_| |_| \__|	)""\n"
			  R"(                                                         __/ |				)""\n"
			  R"(                                                        |___/				)""\n";
	m_action = "null";
	m_difficulty = eNormal;
}

int MainProgram::run()
{
	std::cout << m_title;

	m_continue();

	m_displayReadMe();

	std::cout << "\nReady?";
	m_input();

	if (m_action == "no" || m_action == "quit")
		return 0;

	else if (m_action == "maybe" || m_action == "probably")
		std::cout << "Well no time to think just play and find out.\n";

	else if (m_action != "yes")
		std::cout << "Don't know what you said but I will assume it was a yes.\n\n";

	for (int i = 0; i <= 5; ++i)
	{
		if (i == 5)
		{
			std::cout << "\nSeems you have trouble spelling so, I will set the difficulty to easy for you.\n";
			m_difficulty = eEasy;
			break;
		}
		
		std::cout << "Pick a difficulty:\n"
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
			std::cout << "Not a difficulty!\n\n";
	}

	if (m_difficulty != eEasy)
		m_takeoff();

	m_seperator();
	std::cout << "You are in the air and hear over the radio \"ATTENTION ALL PILOTS DO NOT LAND\""
				 "\nfollowed by groans, growls, screams, and finaly static, your infinite journey starts.\n";

	while (m_bRunning)
	{

	}

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
	std::cout << "\n> ";

	std::getline(std::cin, m_action);

	for (char& i: m_action)
	{
		i = tolower(i);
	}
	std::cout << '\n';
}

void MainProgram::m_continue()
{
	std::cout << "\nPress [enter] to continue\n";
	std::cin.ignore();
	m_seperator();
}

void MainProgram::m_takeoff()
{
	bool bDoorLock = false;
	do
	{
		m_seperator();
		std::cout << "Time for takeoff!\n\n";

		m_engine(bDoorLock);
		m_seperator();
		m_flaps();

		if (!bDoorLock && m_difficulty == eHard)
		{
			std::cout << "Missing: A terrorist enters the cockpit and hijacks the plane,"
						 " you are never heard from again.\n\n";
		}

		else if (m_difficulty == eHard)
		{
			std::cout << "You hear a thud on your door folowed by the sounds of struggeling and decide"
						 "\nto look through the peephole, you see the cabin crew tossing out a terrorist\n\n";
		}
	} while (!bDoorLock && m_difficulty == eHard);
}

void MainProgram::m_engine(bool& bDoorLock)
{
	bool bEngine = false;
	while (!bEngine)
	{
		std::cout << "What's first:\n"
					 "-Get up and leave\n"
					 "-Do nothing\n"
					 "-Turn engines on";

		if (bDoorLock == false)
			std::cout << "\n-Lock door";

		else 
			std::cout << "\n-Unlock door";

		m_input();

		if (m_action == "lock door" && !bDoorLock)
		{
			std::cout << "You lock the door.\n\n";
			bDoorLock = true;
			m_seperator();
		}

		else if (m_action == "unlock door" && bDoorLock)
		{
			std::cout << "You unlock the door.\n\n";
			bDoorLock = false;
			m_seperator();
		}

		else if (m_action == "turn engines on")
		{
			std::cout << "You turn the engines on.\n\n";
			bEngine = true;
		}

		else if (m_action == "turn engine on")
		{
			std::cout << "Death: You turn one engine on causing the plane to spin in to the airport,"
						 " no one on the plane survives.\n\n";
			m_seperator();
		}

		else if (m_action == "get up and leave" || m_action == "get up")
		{
			std::cout << "Ending: Fired\nHey at least you survive until food funds run out!";
			m_continue();
		}
		
		else if (m_action == "do nothing" || m_action == "")
		{
			std::cout << "Death: Another plane coming to land collides with your plane, no one survives.";
			m_continue();
		}

		else
		{
			std::cout << "Death: You push a bunch of random buttons and activate the ejector seat\n"
						 "without opening the roof, you are turned in to a pancake.";
			m_continue();
		}
	}
}

void MainProgram::m_flaps()
{
	std::cout << "You are now on the runway.\n\n";

	bool bFlaps = false;
	while (!bFlaps)
	{
		std::cout << "What do you do:\n"
					 "-Pull up\n"
					 "-Push down\n"
					 "-Turn to avoid fence";

		m_input();

		if (m_action == "pull up")
		{
			std::cout << "You pull up and are now leaving the ground.\n\n";
			bFlaps = true;
		}

		else if (m_action == "push down")
		{
			std::cout << "Death: You push down and cause the plane to nose dive, squashing the cockpit.";
			m_continue();
		}

		else if (m_action == "turn" || m_action == "avoid" || m_action == "turn to avoid fence")
		{
			std::cout << "Death: You turn the plane towards the air traffic control tower and crash,"
						 " the tower falls and suqashes the plane.";
			m_continue();
		}

		else
		{
			std::cout << "Death: The plane goes through the fence and hits multiple cars, rupturing the cabin."
						 " The plane falls into the ocean and you are unable to escape and drown.";
			m_continue();
		}
	}
}

void MainProgram::m_seperator()
{
	std::cout << "-----------------------------------------------------------------\n";
}