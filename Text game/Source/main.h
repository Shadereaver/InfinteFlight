#pragma once

//Includes
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

//Game data
enum Screen
{
	eMainMenu,
	ePlaying,
	ePause,
	eInventory,
	eNewGameName,
	eNewGameOverwrite,
	eLoadGame
};

struct GameData
{
	bool bRunning;
	bool bRestrictedInput;
	Screen screen;
	std::vector<std::string> availableChoices;
	std::string gameName;

	friend std::ifstream& operator>>(const std::ifstream& is, GameData& data);
	friend std::ofstream& operator<<(std::ofstream& os, const GameData& data);
} gameData;

std::ifstream& operator>>(std::ifstream& is, GameData& data)
{
	is >> data.gameName;
    return is;
}

std::ofstream& operator<<(std::ofstream& os, const GameData& data)
{
    os << data.gameName << "\n";
    return os;
}

//Utility functions
bool loadFile(const std::string& fileName);
bool saveFile(const std::string& fileName);
bool validInput(const std::string& action);
void getInput(std::string& action);
void mainMenuText();
void removeAvailableChoices(const int& numOfElementsToRemove);

//Main functions
void initialise();
std::string input();
int update(const std::string& action);
void display();
int mainMenu(const std::string& action);
int newGame(const std::string& action);
int loadGame(const std::string& action);
