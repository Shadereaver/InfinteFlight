#pragma once
#include "../EventBase.h"
class Alien : public EventBase
{
	void printEventText() const override;
	void eventResult() const override;
};
