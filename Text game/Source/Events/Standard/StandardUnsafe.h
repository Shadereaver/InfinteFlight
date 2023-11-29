#pragma once
#include "../EventBase.h"
class StandardUnsafe : public EventBase
{
    void printEventText() const override;
	void eventResult() const override;
};
