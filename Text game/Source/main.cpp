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
    gameData.availableChoices = {};

    mainMenuText();
}

std::string input()
{
    std::string action = "";

    getInput(action);

    for (int i = 0; i < action.size(); ++i)
    {
        action[i] = tolower(action[i]);
    }

    while (!validInput(action))
    {
	    std::cout << "\nInvalid\n\n";
        std::cin.clear();
        std::cin.ignore(1000, '\n');

        getInput(action);
    }

	return action;
}

int update(const std::string& action)
{
    if (gameData.scene == eMainMenu)
        return mainMenu(action);

	return 0;
}

void display()
{

}

int mainMenu(const std::string& action)
{
    mainMenuText();

    return 0;
}

void mainMenuText()
{
    std::cout << " _____ _   _  _____   _____   ___  ___  ___ _____ \n"
              << "|_   _| | | ||  ___| |  __ \\ / _ \\ |  \\/  ||  ___|\n"
              << "  | | | |_| || |__   | |  \\// /_\\ \\| .  . || |__  \n"
              << "  | | |  _  ||  __|  | | __ |  _  || |\\/| ||  __| \n"
              << "  | | | | | || |___  | |_\\ \\| | | || |  | || |___ \n"
              << "  \\_/ \\_| |_/\\____/   \\____/\\_| |_/\\_|  |_/\\____/ \n";

    std::cout << "\n--------------\nStart new game\nLoad game\nQuit\n--------------\n";
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
    if (action == "start new game")
        return true;

    if (action == "load game")
        return true;

    if (action == "quit")
        return true;

	if (action == "inventory")
        return true;

    if (action == "pause")
        return true;

    if (std::find(gameData.availableChoices.begin(), gameData.availableChoices.end(), action) != gameData.availableChoices.end())
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
