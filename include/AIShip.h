#pragma once

#include "MathHelper.h"
#include "Entity.h"

class AIShip : public Entity
{
private:

	sf::Vector2f velocity;
	float maxAccel;
	float maxSpeed;

public:

	AIShip();

	float GetMaxAcceleration() const { return maxAccel; }
	void SetMaxAcceleration( float a ) { maxAccel = MathHelper::Max( 0.f, a ); }

	float GetMaxSpeed() const { return maxSpeed; }
	void SetMaxSpeed( float s ) { maxSpeed = MathHelper::Max( 0.f, s ); }

	float GetSpeed() const { return MathHelper::Length( velocity ); }

	void Update( float elapsedTime, sf::RenderWindow& target );
};