#include "EventBase.h"

#include "Random nums/RandomNums.h"

EventBase::EventBase()
{
	id = randNums();
}