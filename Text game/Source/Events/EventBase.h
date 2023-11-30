#pragma once

#include <string>

enum WinCondition
{
	eDeath,
	eWin,
	eSurvive
};

class EventBase
{
public:
	EventBase();
	virtual void printEventText() const = 0;
	virtual WinCondition eventResult(std::string action) const = 0;

protected:
	int id;
};
