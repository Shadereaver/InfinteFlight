#include "main.h"

void main()
{
	std::cout << " _____ _   _  _____   _____   ___  ___  ___ _____ \n"
              << "|_   _| | | ||  ___| |  __ \\ / _ \\ |  \\/  ||  ___|\n"
              << "  | | | |_| || |__   | |  \\// /_\\ \\| .  . || |__  \n"
              << "  | | |  _  ||  __|  | | __ |  _  || |\\/| ||  __| \n"
              << "  | | | | | || |___  | |_\\ \\| | | || |  | || |___ \n"
              << "  \\_/ \\_| |_/\\____/   \\____/\\_| |_/\\_|  |_/\\____/ \n";

    do
    {
        int menuChoice = validatedNumericInput("\n[1] Start game\n[2] Commands/controls\n[3] Quit\n\n>");

	    switch (menuChoice)
	    {
	    case 1:

            break;

	    case 2:

            break;

	    case 3:
            bRunning = false;
            std::cout << "\nThanks for playing.";
            break;

	    default:
            std::cout << "\nInvalid choice\n";
            break;
	    }
    } while (bRunning);
}


int validatedNumericInput(const std::string& stringToOutput)
{
    std::string input = "";
    do
    {
        std::cout << stringToOutput;
        std::cin >> input;

        if (input.find_first_not_of("0123456789") != std::string::npos)
            std::cout << "\nInvalid input\n";

    } while (input.find_first_not_of("0123456789") != std::string::npos);

    return stoi(input);
}
