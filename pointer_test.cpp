#include <iostream>

void changeToTen(int* val)
{
	*val = 10;
}

int main(int argc, char** argv)
{
	int x = 0;
	
	changeToTen(&x);
	
	std::cout << x;
	
	return 0;
}


