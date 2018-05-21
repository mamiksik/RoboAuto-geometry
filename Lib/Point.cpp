//
// Created by Martin Miksik on 21/05/2018.
//

#include <cmath>
#include "Point.h"


Point::Point( double _x, double _y, double _z ): coordinates{_x, _y, _z}
{
}


double Point::distance( Point point)
{
	return sqrt( pow(coordinates[axe::x] - point.coordinates[axe::x], 2) +
			     pow(coordinates[axe::y] - point.coordinates[axe::y], 2) +
			     pow(coordinates[axe::z] - point.coordinates[axe::z], 2)
	);
}

