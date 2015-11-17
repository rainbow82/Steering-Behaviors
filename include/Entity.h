#pragma once 

#include <SFML/Graphics.hpp>
#include <string>

class Entity
{
private:

	sf::Texture texture;
	sf::Sprite sprite;
	sf::RectangleShape aabb;
	
	sf::Text debugText;
		
	// prevent copy & assignment
	Entity( const Entity& );
	Entity& operator=( const Entity& );

public:

	Entity() {};

	bool LoadSprite( const std::string& fileName );

	sf::Vector2f GetPosition() const;
	void SetPosition( const sf::Vector2f& position );

	float GetRotation( bool radians = false ) const;
	void SetRotation( float angle );
	
	virtual void Draw( sf::RenderWindow& target );
	virtual void DebugDraw( sf::RenderWindow& target );
	virtual void Update( float elapsedTime, sf::RenderWindow& target );

	bool CollidesWith( const Entity* other );
};