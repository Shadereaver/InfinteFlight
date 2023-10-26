#include <iostream>
#include <string>
#include "Player.h"

void main()
{
    bool bRunning = true;
    std::string input = "";

	std::cout << " _____ _   _  _____   _____   ___  ___  ___ _____ \n"
              << "|_   _| | | ||  ___| |  __ \\ / _ \\ |  \\/  ||  ___|\n"
              << "  | | | |_| || |__   | |  \\// /_\\ \\| .  . || |__  \n"
              << "  | | |  _  ||  __|  | | __ |  _  || |\\/| ||  __| \n"
              << "  | | | | | || |___  | |_\\ \\| | | || |  | || |___ \n"
              << "  \\_/ \\_| |_/\\____/   \\____/\\_| |_/\\_|  |_/\\____/ \n";

    do
    {
	    std::cout << "\n[1] Start game\n[2] Commands/controls\n[3] Quit\n\n>";
        std::cin >> input;

	    switch (stoi(input))
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

            break;
	    }
    } while (bRunning);















    std::cout << "\n\n\n";
    int nums[5] = {1,2,3,4,5};


    for (int num : nums)
    {
	    int altNum = num * 5;

        std::cout << altNum << "\n";
    }
}