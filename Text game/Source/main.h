#pragma once

//Includes
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <nlohmann/json.hpp>

//Game data
enum Scene
{
	eMainMenu,
	ePlaying,
	ePause,
	eInventory,
	eNewGame,
	eLoadGame
};

enum SubScene
{
	eNewGameName,
	eNewGameOverwrite
};

struct GameData
{
	bool bRunning;
	bool bRestrictedInput;
	Scene scene;
	SubScene subScene;
	std::vector<std::string> availableChoices;
	std::string gameName;

	friend std::ostream& operator<<(std::ostream& os, const GameData& gameData)
	{
		return os << gameData.gameName;
	}

	friend std::istream& operator >>(std::istream& is, GameData& gameData)
	{
		return is >> gameData.gameName;
	}
} gameData;


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
