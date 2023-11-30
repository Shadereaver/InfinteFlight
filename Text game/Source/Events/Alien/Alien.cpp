#include "Alien.h"

#include <iostream>

void Alien::printEventText() const
{
	if (id == 50)
	{
		std::cout << "A UFO mothership hovers above the plane.\n"
					 "-Ignore\n"
					 "-Try to escape\n"
					 "-Make radio contact";
	}

	else if (id < 50)
	{
		std::cout << "A UFO hovers above the plane.\n"
					 "-Ignore\n"
					 "-Try to escape";
	}

	else if (id > 50)
	{
		std::cout << "A UFO flys above the plane.\n"
					 "-Ignore\n"
					 "-Try to escape";
	}
}

WinCondition Alien::eventResult(std::string action) const
{
	if (id == 50)
	{
		if (action == "ignore" || action == "")
		{
			std::cout << "Death: You ignore the mothership and crash into its energy shield.";
			return eDeath;
		}

		else if (action == "try to escape" || action == "escape")
		{
			std::cout << "Death: You try to escape but the mother ship thinks you\n"
						 "are attacking and disintegrates the plane.";
			return eDeath;
		}

		else if (action == "make radio contact")
		{
			std::cout << "Ending: Extraterrestrial assistance\n"
						 "You make radio contact with the mothership and ask them to eleminate the infected,\n"
						 "after a few seconds there is a bright flash of light as all infected are eleminated.\n"
						 "You land near a setelment and begin the reconstruction of society.";
			return eWin;
		}

		else
		{
			std::cout << "You scramble to take a photo, but everyone knows that UFOs disapear when you take a photo.";
			return eSurvive;
		}
	}

	else if (id < 50)
	{
		if (action == "ignore" || action == "")
		{
			std::cout << "You ignore the UFO as it abducts some of the passenges and leaves";
			return eSurvive;
		}

		else if (action == "try to escape" || action == "escape")
		{
			std::cout << "Death: You try to escape but the UFO disintegrates the plane.";
			return eDeath;
		}

		else
		{
			std::cout << "You scramble to take a photo, but everyone knows that UFOs disapear when you take a photo.";
			return eSurvive;
		}
	}

	else
	{
		if (action == "ignore" || action == "")
		{
			std::cout << "Death: You ignore the UFO as it disintegrates the plane.";
			return eDeath;
		}

		else if (action == "try to escape" || action == "escape")
		{
			std::cout << "You stear the plane into thick clouds and lose the UFO.";
			return eSurvive;
		}

		else
		{
			std::cout << "You scramble to take a photo, but everyone knows that UFOs disapear when you take a photo.";
			return eSurvive;
		}
	}
}
