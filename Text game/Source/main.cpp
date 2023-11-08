#include "main.h"

//Main loop
int main()
{
    initialise();

    while (gameData.bRunning)
    {
        const std::string action = input();

        const int errorCode =  update(action);

        if (errorCode != 0)
            return errorCode;

        display();
    }
}

//Main functions
void initialise()
{
	gameData.bRunning = true;
    gameData.gameName = "Untitled";
    gameData.scene = eMainMenu;
    gameData.numberOfChoices = 0;
}

std::string input()
{
    std::string action = "";

    getInput(action);

    while (!validInput(action))
    {
	    std::cout << "\nInvalid";
        std::cin.clear();
        std::cin.ignore(1000, '\n');

        getInput(action);
    }

	return action;
}

int update(const std::string& action)
{
	return 0;
}

void display()
{

}

int mainMenu()
{
    bool menuLoop = true;

    std::cout << " _____ _   _  _____   _____   ___  ___  ___ _____ \n"
              << "|_   _| | | ||  ___| |  __ \\ / _ \\ |  \\/  ||  ___|\n"
              << "  | | | |_| || |__   | |  \\// /_\\ \\| .  . || |__  \n"
              << "  | | |  _  ||  __|  | | __ |  _  || |\\/| ||  __| \n"
              << "  | | | | | || |___  | |_\\ \\| | | || |  | || |___ \n"
              << "  \\_/ \\_| |_/\\____/   \\____/\\_| |_/\\_|  |_/\\____/ \n";

    while (menuLoop)
    {  
        std::cout << "\n--------------\nStart new game\nLoad game\nQuit\n--------------\n>";

        
    }

    return 0;
}

int newGame()
{
    return false;
}

int loadGame()
{
    return false;
}


//Utility functions
bool validInput(const std::string& action)
{
	if (action == "inventory")
        return true;

    if (action == "pause")
        return true;

    if (action.find_first_not_of("0123456789") != std::string::npos)
        return false;

    if (stoi(action) > 0 && stoi(action) <= gameData.numberOfChoices)
        return true;

    return false;
}

void getInput(std::string& action)
{
    std::cout << "Make your choice\n>";
	std::cin >> action;
}

bool loadFile(const std::string& fileName)
{
    std::ifstream file;
    file.open(fileName);

    if (!file.is_open() || !file.good())
        return false;

    std::getline(file, gameData.gameName);

    file.close();
    return true;
}

bool saveFile(const std::string& fileName)
{
    std::ofstream file;
    file.open(fileName);

    if (!file.is_open() || !file.good())
        return false;

    file << gameData.gameName;

    return true;
}
