#pragma once

class EventBase
{
public:
	EventBase();
	virtual void printEventText() const = 0;
	virtual void eventResult() const = 0;

private:
	int id;
};

