#include <iostream>
#include "Lib/Point.h"
#include "Lib/Vector.h"
#include "Lib/Line.h"


int main( )
{
	Point A{ 1, 1, 1 };
	Point B{ 1, 1, 0 };

	// Point test
	std::cout << A.distance( B ) << " : Should be 1" << std::endl;

	Vector a{ A };
	Vector b{ B };

	// Vector test
	std::cout << ( b == a ) << " : Should be false"<< std::endl;
	std::cout << ( a != a ) << " : Should be false"<< std::endl;

	std::cout << ( a + b ).point.coordinates[ GeometricEntity::axe::x ] << " : Should be 2" << std::endl;
	std::cout << ( a - 1 ) << " : Should be 0.732"<< std::endl;

	std::cout << ( a * b ).point.coordinates[GeometricEntity::axe::x] << " : Should be -1"<< std::endl;


	Line p = Line( A, a );

	// Line Test
	std::cout << p.distance( A ) << " : Distance from p to A. Should be 0" << std::endl;
	std::cout << p.distance( B ) << " : Distance from p to B. Should be 0.816" << std::endl;
}