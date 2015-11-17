#include <SFML/Window/Keyboard.hpp>
#include "PlayerShip.h"

using namespace sf;

PlayerShip::PlayerShip()
	: rotationSpeed( 120.f ),
	  forwardSpeed ( 175.f ),
	  backwardSpeed( 100.f )
{
}

void PlayerShip::Update( float elapsedTime, RenderWindow& target ) 
{
	Vector2f position;
	float angle;

	if ( Keyboard::isKeyPressed( Keyboard::Left ) )
	{
		angle = GetRotation();
		SetRotation( angle - rotationSpeed * elapsedTime );
	}

	if ( Keyboard::isKeyPressed( Keyboard::Right ) )
	{
		angle = GetRotation();
		SetRotation( angle + rotationSpeed * elapsedTime );
	}

	if ( Keyboard::isKeyPressed( Keyboard::Up ) )
	{
		position = GetPosition();
		angle = GetRotation( true );

		position.x += forwardSpeed * elapsedTime * sin( angle );
		position.y -= forwardSpeed * elapsedTime * cos( angle );

		SetPosition( position );
	}

	if ( Keyboard::isKeyPressed( Keyboard::Down ) )
	{
		position = GetPosition();
		angle = GetRotation( true );

		position.x -= backwardSpeed * elapsedTime * sin( angle );
		position.y += backwardSpeed * elapsedTime * cos( angle );

		SetPosition( position );
	}

	Entity::Update( elapsedTime, target );
}
