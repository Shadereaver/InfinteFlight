#pragma once
#include "../EventBase.h"
class ResupplyUnsafe : public EventBase
{
	void printEventText() const override;
	void eventResult() const override;
};
