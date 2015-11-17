#include "Steering.h"
#include "MathHelper.h"

// implements the seek steering behavior described on page 56
void Steering::Seek( sf::Vector2f position, sf::Vector2f target, float maxAcceleration, SteeringOutput& steering )
{
	steering.linear = target - position;
	MathHelper::Normalize( steering.linear );
	
	steering.linear *= maxAcceleration;
}
