#include <iostream>
#include "console.h"
#include <cstdlib>
#include <stdlib.h>

int main(int argc, char** argv) {
	std::cout << "Hello, World!";
	
	std::setcurpos(2, 4);
	std::cout << "Hopefully, in windows";
	
	while(true)
	{
		int line = rand() % 20 + 3;
		int column = rand() % 50;
		
		std::setcurpos(line, column);
		std::cout << "bunnies";
		Sleep(1000);
		std::setcurpos(line, column);
		std::cout << "       ";
	}
	
	return 0;
}
