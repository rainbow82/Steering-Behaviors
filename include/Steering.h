#pragma once

#include <SFML/System/Vector2.hpp>

struct SteeringOutput
{
	sf::Vector2f linear;
	float angular;
};

class Steering
{
public:

	static void Seek( sf::Vector2f position, sf::Vector2f target, float maxAcceleration, SteeringOutput& steering );
};