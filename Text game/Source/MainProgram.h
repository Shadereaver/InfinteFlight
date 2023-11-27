#pragma once

#include <string>

enum Difficulty
{
	eEasy,
	eNormal,
	eHard
};

class MainProgram
{
public:
	MainProgram();
	int run();

private:
	void m_displayReadMe() const;
	void m_input();
	void m_setDifficulty();

	bool m_bRunning;
	std::string m_title;
	std::string m_action;
	Difficulty m_difficulty;
};
