#pragma once

//Includes
#include <iostream>
#include <string>
#include <fstream>

//Game data
enum Scene
{
	eMainMenu,
	eInWorld
};

struct GameData
{
	bool bRunning;
	Scene scene;
	int numberOfChoices;
	std::string gameName;
} gameData;

//Utility functions
bool validateNumericInput(const std::string& input);
bool loadFile(const std::string& fileName);
bool saveFile(const std::string& fileName);
bool validInput(const std::string& action);
void getInput(std::string& action);

//Main functions
void initialise();
std::string input();
int update(const std::string& action);
void display();
int mainMenu();
int newGame();
int loadGame();
