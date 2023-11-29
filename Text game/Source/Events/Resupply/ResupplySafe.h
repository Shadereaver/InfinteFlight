#pragma once
#include "../EventBase.h"
class ResupplySafe : public EventBase
{
	void printEventText() const override;
	void eventResult() const override;
};
