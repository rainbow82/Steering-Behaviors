#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <random>
#include <conio.h>

#include "GameObjects.h"
#include "AIShip.h"

using namespace sf;

const Color cornflowerBlue( 100, 149, 237, 255 );

bool LoadResources();
void SetRandomPosition( Entity& e, Vector2u& size );
bool UpdateEvents( RenderWindow& window );
void UpdateDisplay( Text& text, AIShip& ai );
int UpdateFps();

int main()
{
	// Load game assets
	if ( !LoadResources() )
	{
		LOG( "<press any key to continue>" );
		_getch();
		return EXIT_FAILURE;
	}

    // Create the main window
    RenderWindow window( VideoMode( 800, 600 ), "GSP 315" );
	window.setFramerateLimit( 60 );

	Text text( "", GameObjects::GetFont(), 16 );
	srand( (unsigned int) time( NULL ) );
	
	Clock gameTime;

	AIShip &ai = GameObjects::GetAI();
	PlayerShip &player = GameObjects::GetPlayer();

	SetRandomPosition( ai, window.getSize() );
	SetRandomPosition( player, window.getSize() );
    
	// Start the game loop
    while ( window.isOpen() )
    {
		float elapsed = gameTime.restart().asSeconds();

		if ( !UpdateEvents( window ) )
		{
			window.close();
		}

		// update the AI acceleration and speed
		if ( Keyboard::isKeyPressed( Keyboard::Add ) )
		{
			ai.SetMaxAcceleration( ai.GetMaxAcceleration() + 0.5f );
		}

		if ( Keyboard::isKeyPressed( Keyboard::Subtract ) )
		{
			ai.SetMaxAcceleration( ai.GetMaxAcceleration() - 0.5f );
		}

		if ( Keyboard::isKeyPressed( Keyboard::Multiply ) )
		{
			ai.SetMaxSpeed( ai.GetMaxSpeed() + 0.5f );
		}

		if ( Keyboard::isKeyPressed( Keyboard::Divide ) )
		{
			ai.SetMaxSpeed( ai.GetMaxSpeed() - 0.5f );
		}

		// Update entities
		player.Update( elapsed, window );
		ai.Update( elapsed, window );

        // Begin Drawing
        window.clear( cornflowerBlue );

		player.Draw( window );
		ai.Draw( window );

		player.DebugDraw( window );
		ai.DebugDraw( window );

		// Update and draw the stats text
		UpdateDisplay( text, ai );
        window.draw( text );

        // Update the window
        window.display();
    }

	LOG( "<press any key to continue>" );
	_getch();

    return EXIT_SUCCESS;
}

bool LoadResources()
{
    if ( !GameObjects::GetFont().loadFromFile( "resources\\cour.ttf" ) )
	{
		LOG_ERROR( "Could not load font" );
		return false;
	}
	
	if ( !GameObjects::GetPlayer().LoadSprite( "resources\\plane1.png" ) )
	{
		LOG_ERROR( "Could not load sprite" );
		return false;
	}

	if ( !GameObjects::GetAI().LoadSprite( "resources\\plane2.png" ) )
	{
		LOG_ERROR( "Could not load sprite" );
		return false;
	}

	LOG( "All resources loaded successfully" );
	return true;
}

void SetRandomPosition( Entity& e, Vector2u& size )
{
	e.SetPosition( Vector2f( (float)(rand() % size.x), (float)(rand() % size.y) ) );
}

bool UpdateEvents( RenderWindow& window )
{
	Event event;
    
	while ( window.pollEvent(event) )
	{
		if ( event.type == Event::Closed )
		{
			LOG( "Closed event caught - exiting" );
			return false;
		}
	}

	if ( Keyboard::isKeyPressed( Keyboard::Escape ) )
	{
		LOG( "Escape pressed - exiting" );
		return false;
	}

	return true;
}

void UpdateDisplay( Text& text, AIShip& ai )
{
	static const char stats[] =
		"%d FPS\n"
		"AI Speed: %.1f\n"
		"AI Max Accel (numpad +,-): %.1f\n"
		"AI Max Speed (numpad *,/): %.1f";

	char data[128];

	sprintf_s( data, sizeof( data ), stats, UpdateFps(), ai.GetSpeed(), ai.GetMaxAcceleration(), ai.GetMaxSpeed() );
	text.setString( data );
}

int UpdateFps()
{
	static Clock clock;
	static int frameCount = 0;
	static int fps = 0;

	frameCount++;

	if ( clock.getElapsedTime().asSeconds() >= 1.f )
	{
		fps = frameCount;

		if ( fps < 20 )
		{
			LOG_WARNING( "Low framerate: %d", fps );
		}

		clock.restart();
		frameCount = 0;
	}

	return fps;
}