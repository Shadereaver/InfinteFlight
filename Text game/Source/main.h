#pragma once

//Includes
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

//Game data
enum Scene
{
	eMainMenu,
	ePlaying,
	ePause,
	eInventory
};

struct GameData
{
	bool bRunning;
	Scene scene;
	std::vector<std::string> availableChoices;
	std::string gameName;
} gameData;

//Utility functions
bool loadFile(const std::string& fileName);
bool saveFile(const std::string& fileName);
bool validInput(const std::string& action);
void getInput(std::string& action);
void mainMenuText();

//Main functions
void initialise();
std::string input();
int update(const std::string& action);
void display();
int mainMenu(const std::string& action);
int newGame();
int loadGame();
