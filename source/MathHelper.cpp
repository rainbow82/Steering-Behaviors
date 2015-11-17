#include "MathHelper.h"

float MathHelper::Length( const sf::Vector2f& vector )
{
	return sqrt( pow( vector.x, 2 ) + pow( vector.y, 2 ) );
}

float MathHelper::Normalize( sf::Vector2f& vector )
{
	float length = MathHelper::Length( vector );

	if ( length > 0.f )
	{
		vector /= length;
	}

	return length;
}

// contribution by R. Cisco GSP-315 Sept. 2013
sf::Vector2f MathHelper::AsVector( float scalar )
{
	sf::Vector2f v;
	v.x = sin( scalar );
	v.y = -cos( scalar );
	
	return v;
}