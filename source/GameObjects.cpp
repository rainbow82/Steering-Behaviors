#include "GameObjects.h"
#include <Windows.h>

using namespace sf;

GameObjects& GameObjects::Instance()
{
	static GameObjects instance;
	return instance;
}

PlayerShip& GameObjects::GetPlayer()
{
	return GameObjects::Instance().player;
}

AIShip& GameObjects::GetAI()
{
	return GameObjects::Instance().ai;
}

Font& GameObjects::GetFont()
{
	return GameObjects::Instance().font;
}

void GameObjects::LogMessage( const char* file, int line, int severity, const char *fmt, ... )
{
	va_list			argptr;

	HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo( hConsole, &csbi );

	switch( severity )
	{
		case LOG_WARNING:
			SetConsoleTextAttribute( hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY );
		break;

		case LOG_ERROR:
			SetConsoleTextAttribute( hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY );
		break;

		default:
		break;
	}
	
	printf( "\n[%s : %d] ", file, line );

	va_start( argptr, fmt );
	vprintf( fmt, argptr );
	va_end( argptr );

	SetConsoleTextAttribute( hConsole, csbi.wAttributes );
}