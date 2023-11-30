#include "StandardSafe.h"

#include <iostream>

void StandardSafe::printEventText() const
{
	if (id == 1)
	{
		std::cout << "You hear the radio burst into life and a voice tells you to land,\n"
					 "when you look out the window you see a military airfield.\n"
					 "-Land\n"	
					 "-Ignore\n"
					 "-Attempt to ask who they are";
	}

	else if (id < 50)
	{
		std::cout << "You see a small storm cloud and think it will cause some turbulance.\n"
					 "-Fly faster\n"
					 "-Turn and avoid\n"
					 "-Continue on";
	}

	else if (id >= 50)
	{
		std::cout << "One of the passengers starts accusing other passengers of theft and getting into fights,\n"
					 "how do you deal with them?\n"
					 "-Throw them out of the plane\n"
					 "-Tie them up\n"
					 "-Authorise the passengers to \"deal\" with them";
	}
}

WinCondition StandardSafe::eventResult(std::string action) const
{
	if (id == 1)
	{
		if (action == "land")
		{
			std::cout << "Ending: rescued\n"
						 "You land the plane at the airfield and military personel escort you to a camp of survivors.\n";
			return eWin;
		}

		else if (action == "ignore" || action == "")
		{
			std::cout << "You ignore the call and continue flying, but wander what would of happened if you did land.";
			return eSurvive;
		}

		else if (action == "attempt to ask who they are" || action == "ask")
		{
			std::cout << "You try to ask who they are but realise the radio is damaged,\n"
						 "by the time you fix it you have lost sight and contact of the air field.";
			return eSurvive;
		}

		else
		{
			std::cout << "You panic and nearly crash while attempting to land. While turning around to\n"
						 "make another attempt, they tell you to leave as they no longer trust you to land safely.";
			return eSurvive;
		}
	}

	else if (id < 50)
	{
		if (action == "fly faster" || action == "faster")
		{
			std::cout << "You fly faster to get through the storm faster, but it just makes the turbulance worse.";
			return eSurvive;
		}

		else if (action == "turn and avoid" || action == "turn" || action == "avoid")
		{
			std::cout << "You turn to avoid the storm but end up flying through a thicker part"
						 " of the storm causing the turbulance to last longer.";
			return eSurvive;
		}

		else if (action == "continue on" || action == "continue" || action == "")
		{
			std::cout << "You decide to just fly though and find that the turbulance is not as bad as you think";
			return eSurvive;
		}

		else
		{
			std::cout << "You try to go under the storm but realising it is a bad idea pull up to go over,\n"
						 "you make it but now most of the passangers are in g-LOC.";
			return eSurvive;
		}
	}
	else
	{
		if (action == "throw them out of the plane" || action == "throw")
		{
			std::cout << "You throw the rowdy passenger off the plane and tell the other\n"
						 "passengers that is what happens if the get too rowdy.";
			return eSurvive;
		}

		else if (action == "tie them up")
		{
			std::cout << "You tie the passenger up.";
			return eSurvive;
		}

		else if (action == "authorise the passengers to \"deal\" with them" || action == "authorise the passengers to deal with them" || action == "authorise")
		{
			std::cout << "You tell the passengers they can do what they want to the rowdy passenger,\n"
						 "for the next hour all you can hear is shouting and the passenger screaming and\n"
						 "a request for \"clean up\" in the isle.";
			return eSurvive;
		}

		else
		{
			std::cout << "You punch the rowdy passenger and tell them to be quiet, which was very effective.";
			return eSurvive;
		}
	}
}
