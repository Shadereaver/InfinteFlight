#pragma once

//Includes
#include <iostream>
#include <string>
#include <fstream>

//Game data
bool bRunning = true;
std::string gameName = "Untitled";

//Boolean functions
bool validateNumericInput(const std::string& stringToOutput);
bool loadFile(const std::string& fileName);
bool saveFile(const std::string& fileName);

//Integer functions
int mainMenu();
int newGame();
int loadGame();
