#pragma once

#include <string>

class MainProgram
{
public:
	MainProgram();
	int run();

private:
	void title() const;
	void displayReadMe() const;
	void input();

	bool bRunning;
	std::string action;
};
