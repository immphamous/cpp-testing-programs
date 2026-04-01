#include <iostream>

#ifdef _WIN32
	#include <windows.h>
#endif

#ifndef CONSOLE_H

#define CONSOLE_H

namespace std
{
	void setcurpos(short int line, short int column)
	{
		#ifdef _WIN32
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			COORD pos = { column, line };
			SetConsoleCursorPosition(hConsole, pos);
		#endif
	}
}

#endif
