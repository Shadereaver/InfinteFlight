#pragma once

#include <string>

class MainProgram
{
public:
	MainProgram();
	int run();

private:
	void m_title() const;
	void m_displayReadMe() const;
	void m_input();

	bool m_bRunning;
	std::string m_action;
};
