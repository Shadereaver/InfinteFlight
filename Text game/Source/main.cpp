#include "main.h"

//Main loop
int main()
{
    do
    {
        mainMenu();
    } while (bRunning);
}

//Main menu functions
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
        std::cout << "\n[1] Start new game\n[2] Load game\n[3] Quit\n\n>";

        std::string input;
        std::cin >> input;

        if (!validateNumericInput(input))
            continue;

        int menuChoice = stoi(input);

        switch (menuChoice)
        {
        case 1:
            return newGame();
            break;

        case 2:
            return loadGame();
            break;

        case 3:
            bRunning = false;
            menuLoop = false;
            std::cout << "\nThanks for playing\n.";
            break;

        default:
            std::cout << "\nInvalid\n";
            break;
        }
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
bool validateNumericInput(const std::string& input)
{
    if (input.find_first_not_of("0123456789") != std::string::npos)
    {
        std::cout << "\nInvalid\n";
        return false;
    }

    return true;
}

bool loadFile(const std::string& fileName)
{
    std::ifstream file;
    file.open(fileName);

    if (!file.is_open() || !file.good())
        return false;

    std::getline(file, gameName);

    file.close();
    return true;
}

bool saveFile(const std::string& fileName)
{
    std::ofstream file;
    file.open(fileName);

    if (!file.is_open() || !file.good())
        return false;

    file << gameName;

    return true;
}
