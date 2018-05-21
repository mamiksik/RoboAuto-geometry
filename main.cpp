#include <iostream>
#include "Lib/Point.h"


int main( )
{
	std::cout << "Hello, World!" << std::endl;

	Point A{0, 0, 0};
	Point B{1, 1, 0};

	std::cout << A.distance(B) << std::endl;
}