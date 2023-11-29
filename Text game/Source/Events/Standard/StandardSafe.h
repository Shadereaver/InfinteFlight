#pragma once

#include "../EventBase.h"

class StandardSafe : EventBase
{
	void printEventText() const override;
	void eventResult() const override;
};
