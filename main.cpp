#include <iostream>
#include "Lib/Point.h"
#include "Lib/Vector.h"
#include "Lib/Line.h"
#include "Lib/Polygon.h"


int main( )
{
	Point A{ 1, 1 };
	Point B{ 0, 0 };

	Point C{ 5, 5 };
	Point D{ 5, 7 };

	Point X { -1, -1};

	Point Z { 0, 1};
	Point Q { -1, 0};

	// Point test
	std::cout << A.distance( B ) << " : Should be 1.41" << std::endl;

	Vector a{ A };
	Vector b{ B };

	// Vector test
	std::cout << ( b == a ) << " : Should be false" << std::endl;
	std::cout << ( a != a ) << " : Should be false" << std::endl;

	std::cout << ( a + b ).point.coordinates[ GeometricEntity::axe::x ] << " : Should be 1" << std::endl;
	std::cout << ( a - 1 ) << " : Should be 0.41" << std::endl;

	std::cout << a * b << " : Should be 0" << std::endl;


	Line p = Line( A, B );
	Line x = Line( X, B );

	Line q = Line( Z, Q );

	// Line Test
	std::cout << p.isPerpendicular(x) << " : Should be true" << std::endl;
	std::cout << p.isParaller(q) << " : Should be true" << std::endl;

	std::cout << p.distance( C ) << " : Distance from p to A. Should be 0" << std::endl;
	std::cout << p.distance( D ) << " : Distance from p to B. Should be 1.41" << std::endl;

	Point K{ 1, 1 };
	Point L{ 2, 1 };
	Point M{ 2, 2 };
	Point N{ 1, 2 };

//	Polygon polygon = {K, L, M, N};
	std::array<Point, 4> points = {K, L, M, N};
	Polygon polygon<4> = {points};

	std::cout << polygon.distance(C) << std::endl;


}