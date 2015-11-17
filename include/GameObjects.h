#pragma once 

#include <SFML/Graphics.hpp>
#include "PlayerShip.h"
#include "AIShip.h"

enum LogType
{
	LOG_NONE,
	LOG_WARNING,
	LOG_ERROR
};

#define FILE ( strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__ )

#define LOG(m, ...) GameObjects::LogMessage( FILE, __LINE__, LOG_NONE, m, __VA_ARGS__ )
#define LOG_WARNING(m, ...) GameObjects::LogMessage( FILE, __LINE__, LOG_WARNING, m, __VA_ARGS__ )
#define LOG_ERROR(m, ...) GameObjects::LogMessage( FILE, __LINE__, LOG_ERROR, m, __VA_ARGS__ )

class GameObjects
{
private:

	PlayerShip player;
	AIShip ai;
	sf::Font font;

	// singleton
	GameObjects() {};
	GameObjects( const GameObjects& );
	GameObjects& operator=( const GameObjects& );

public:

	static GameObjects& Instance();

	static PlayerShip& GetPlayer();
	static AIShip& GetAI();
	static sf::Font& GetFont();

	static void LogMessage( const char* file, int line, int severity, const char *fmt, ... );
};