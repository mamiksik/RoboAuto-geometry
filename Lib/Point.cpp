//
// Created by Martin Miksik on 21/05/2018.
//

#include <cmath>
#include "Point.h"


Point::Point( double _x, double _y) : coordinates{ _x, _y}
{
}


double Point::distance( Point point )
{
	return sqrt( pow( coordinates[ axe::x ] - point.coordinates[ axe::x ], 2 ) +
	             pow( coordinates[ axe::y ] - point.coordinates[ axe::y ], 2 )
	);
}


Point Point::rotate( float angle, Point center )
{
	float s = sin(angle);
	float c = cos(angle);

	double x = coordinates[axe::x] - center.coordinates[axe::x];
	double y = coordinates[axe::y] - center.coordinates[axe::y];

	return Point(
			x * c - y * s,
			x * s + y * c
	);
}

