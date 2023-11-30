#pragma once
#include "../EventBase.h"
class StandardUnsafe : public EventBase
{
    void printEventText() const override;
	WinCondition eventResult(std::string action) const override;
};
