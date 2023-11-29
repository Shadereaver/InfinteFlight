#pragma once

#include <random>
#include <chrono>

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine generator(seed);

std::uniform_int_distribution<int> distribution(1, 100);

int randNums()
{
	return distribution(generator);
}