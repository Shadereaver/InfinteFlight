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
    gameData.bRestrictedInput = true;
    gameData.screen = eMainMenu;
    gameData.availableChoices = {};

    mainMenuText();
}

std::string input()
{
    std::string action = "";

    getInput(action);

    for (char& i : action)
    {
	    i = static_cast<char>(tolower(i));
    }

    while (!validInput(action) && gameData.bRestrictedInput)
    {
	    std::cout << "\nInvalid\n\n";
        //std::cin.clear();
        //std::cin.ignore(1000, '\n');

        getInput(action);
    }

	return action;
}

int update(const std::string& action)
{
    if (gameData.screen == eMainMenu)
	    return mainMenu(action);

    if (gameData.screen == eNewGameName || gameData.screen == eNewGameOverwrite)
        return newGame(action);

    if (gameData.screen == eLoadGame)
	    return loadGame(action);

	return 0;
}

void display()
{
    if (gameData.bRunning == false)
	    std::cout << "\nThanks for playing!\n";

    else if (gameData.screen == eMainMenu)
        mainMenuText();

    else if (gameData.screen == eNewGameName)
	    std::cout << "\n-------------\n"
				  "Choose a name\n";

    else if (gameData.screen == eNewGameOverwrite)
        std::cout << "\n------------------------------------------\n"
					 "This will overwrite a save, are you sure?\n";
}

int mainMenu(const std::string& action)
{
    if (action == "start new game")
    {
        gameData.bRestrictedInput = false;
	    gameData.screen = eNewGameName;
    }

    else if (action == "load game")
    {
        gameData.bRestrictedInput = false;
	    gameData.screen = eLoadGame;
    }

    else if (action == "quit")
	    gameData.bRunning = false;

    else
        return 1;

    return 0;
}

int newGame(const std::string& action)
{
    if (gameData.screen == eNewGameOverwrite && action == "yes")
    {
        removeAvailableChoices(2);
        gameData.screen = ePlaying;
	    return 0;
    }

    if (gameData.screen == eNewGameOverwrite && action == "no")
    {
	    gameData.screen = eNewGameName;
        gameData.bRestrictedInput = false;
        removeAvailableChoices(2);
        return 0;
    }

    if (loadFile(action))
    {
	    gameData.screen = eNewGameOverwrite;
        gameData.bRestrictedInput = true;
        gameData.availableChoices.emplace_back("yes");
        gameData.availableChoices.emplace_back("no");
        return 0;
    }

    gameData.gameName = action;
    gameData.bRestrictedInput = true;

    if (!saveFile(action))
        return 2;

    gameData.screen = ePlaying;

    return 0;
}

int loadGame(const std::string& action)
{
    return false;
}


//Utility functions
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
    std::cout << ">";
	std::getline(std::cin, action);
}

bool loadFile(const std::string& fileName)
{
    std::ifstream file;
    file.open("Saves/" + fileName + ".txt");

    if (!file.is_open() || !file.good())
        return false;

    file >> gameData;

    file.close();
    return true;
}

bool saveFile(const std::string& fileName)
{
    std::ofstream file;
    file.open("Saves/" + fileName + ".txt");

    if (!file.is_open() || !file.good())
        return false;

    file << gameData;

    file.close();
    return true;
}

void removeAvailableChoices(const int & numOfElementsToRemove)
{
    for (int i = 0; i < numOfElementsToRemove; ++i)
    {
	    gameData.availableChoices.pop_back();
    }
}


