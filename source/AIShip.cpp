#include "AIship.h"
#include "Steering.h"
#include "GameObjects.h"

using namespace sf;

AIShip::AIShip()
	: maxAccel( 80.f ),
	  maxSpeed( 100.f )
{
}

void AIShip::Update( float elapsedTime, RenderWindow& target )
{
	SteeringOutput steering;
	//Steering::Seek( Entity::GetPosition(), GameObjects::GetPlayer().GetPosition(), maxAccel, steering );

	// the code below implements the kinematic update as described on page 57
	Vector2f position = Entity::GetPosition();
	
	// update our sprite's position based on our current velocity
	position.x += velocity.x * elapsedTime;
	position.y += velocity.y * elapsedTime;
	Entity::SetPosition( position );

	float velLength = MathHelper::Length( velocity );

	// change our ship's facing direction to point at the current movement direction
	// note that this changes the ship's angle instantly - there is no acceleration or deceleration here
	if ( velLength > 0.0f )
	{
		float angle = atan2( velocity.x, -velocity.y );
		Entity::SetRotation( MathHelper::ToDegrees( angle ) );
	}
	
	// integrate the output from our steering behavior into our current velocity
	velocity.x += steering.linear.x * elapsedTime;
	velocity.y += steering.linear.y * elapsedTime;

	// finally, clamp the velocity according to the ship's maximum speed
	if ( velLength > maxSpeed )
	{
		MathHelper::Normalize( velocity );
		velocity *= maxSpeed;
	}
	
	// allow the parent class to run it's update function as well
	Entity::Update( elapsedTime, target );
}