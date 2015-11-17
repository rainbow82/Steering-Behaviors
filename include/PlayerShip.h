#pragma once

#include "Entity.h"

class PlayerShip : public Entity
{
private:

	float rotationSpeed;
	float forwardSpeed;
	float backwardSpeed;

public:

	PlayerShip();

	void Update( float elapsedTime, sf::RenderWindow& target );
};