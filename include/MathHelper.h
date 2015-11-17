#pragma once

#include <SFML/System/Vector2.hpp>
#include <cmath>

class MathHelper
{
public:

	static float ToRadians( float degrees ) { return degrees * ( float ) M_PI / 180.f; }
	static float ToDegrees( float radians ) { return radians / ( float ) M_PI * 180.f; }

	static int Clamp( int x, int a, int b ) { return x < a ? a : (x > b ? b : x); }
	static float Clamp( float x, float a, float b ) { return x < a ? a : (x > b ? b : x); }

	static float Max( float a, float b ) { return a > b ? a : b; }
	static float Min( float a, float b ) { return a < b ? a : b; }

	static float Length( const sf::Vector2f& vector );
	static float Normalize( sf::Vector2f& vector );

	// contribution by R. Cisco GSP-315 Sept. 2013
	static sf::Vector2f AsVector( float scalar );

	// contribution by T. Loudiana GSP-315 Sept. 2013
	static float Dot( const sf::Vector2f& a, const sf::Vector2f& b ) { return a.x * b.x + a.y * b.y; }

	// contribution by N. Grande GSP-315 Nov. 2013
	static void ZeroVector( sf::Vector2f& a ) { a.x = a.y = 0.f; }
};