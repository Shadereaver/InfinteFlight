#pragma once

#include <string>
#include <memory>

#include "Events/EventBase.h"

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
	void m_input();
	void m_continue();

	void m_displayReadMe() const;
	void m_seperator();

	void m_takeoff();
	void m_engine(bool& bDoorLock);
	void m_flaps();

	std::unique_ptr<EventBase> m_eventCreator();

	bool m_bRunning;
	std::string m_title;
	std::string m_action;
	Difficulty m_difficulty;
};
