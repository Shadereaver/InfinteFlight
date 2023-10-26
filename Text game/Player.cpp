#include "Player.h"

int Player::getHealth() const
{
	return mHealth;
}

void Player::setHealth(const int& newHealth)
{
	mHealth = newHealth;
}

Player::Player()
{
	mHealth = 100;
}