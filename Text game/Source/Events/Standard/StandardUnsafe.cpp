#include "StandardUnsafe.h"

#include <iostream>

void StandardUnsafe::printEventText() const
{
	if (id <= 25)
	{
		std::cout << "You see an intact airport do you land?";
	}

	if (id < 60)
	{
		std::cout << "A squad of military jets appear around the plane and tell you to land in a field.\n"
					 "-Land\n"
					 "-Say random letters and numbers\n"	
					 "-Do a barrel roll";
	}

	else if (id >= 60)
	{
		std::cout << "One of the engines bursts into flames!\n"
					 "-Do nothing\n"
					 "-Cut fuel";
	}
}

WinCondition StandardUnsafe::eventResult(std::string action) const
{
	if (id <= 25)
	{
		if (action == "yes")
		{
			std::cout << "Death: While landing you realise that the airport is overrun, but it is too late they are\n"
						 "already jumping into the engine grounding the plane and you will soon be one of them.";
			return eDeath;
		}

		else if (action == "no")
		{
			std::cout << "You believe the airport to be infested so leave.";
			return eSurvive;
		}

		else
		{
			std::cout << "Death: You are so focused on deciding whether to land or not you don't notice that\n" 
						 "you bump the controls and send the plane into an uncontrollable spin and crash.";
			return eDeath;
		}
	}

	if (id < 70)
	{
		if (action == "land")
		{
			std::cout << "Death: You land in the field, but the jets use you as target practice.";
			return eDeath;
		}

		else if (action == "say random letters and numbers" || action == "say")
		{
			std::cout << "You say random letters and numbers into the radio pretending to be some government agent,\n"
						 "it somehow works the jets leave.";
			return eSurvive;
		}

		else if (action == "do a barrel roll")
		{
			std::cout << "Death: The plane does a barrel roll taking out 2 jets and both wings, you crash.\n"
						 "At least it was cool.";
			return eDeath;
		}

		else 
		{
			std::cout << "Death: You decide to ignore them and make a turn, the jets shoot down the plane.";
			return eDeath;
		}
	}

	else
	{
		if (action == "do nothing" || action == "")
		{
			std::cout << "Death: You deside to ignore the problem and hope it will fix itself, this does not work,\n"
						 "the fire ignites the fuel line and causes the plane to explode.";
			return eDeath;
				
		}

		if (action == "cut fuel")
		{
			std::cout << "As you cut the fuel a passenger says through the door that they are an aircraft mechanic\n"
						 "with spare parts, they are able to repair the engine.";
			return eSurvive;
		}

		else
		{
			std::cout << "Death: In a panic you hit what you think is an extinguish fire button,\n"
						 "but instead it dumps all the fuel on the fire and causes the wing to\n"
						 "explode which leads to the plane crashing.";
			return eDeath;
		}
	}
}
