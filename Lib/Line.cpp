//
// Created by Martin Miksik on 21/05/2018.
//

#include <cmath>
#include <iostream>
#include "Line.h"

Line::Line( Point _pointA, Point _pointB ) : pointA( _pointA ),
                                             pointB( _pointB ),
                                             a( _pointA.coordinates[ axe::y ] - _pointB.coordinates[ axe::y ] ),
                                             b( _pointB.coordinates[ axe::x ] - _pointA.coordinates[ axe::x ] ),
                                             c( -b * _pointA.coordinates[ axe::y ] +
                                                -a * _pointA.coordinates[ axe::x ] ) { }


double Line::distance( Point p )
{
	return abs( a * p.coordinates[ axe::x ] + b * p.coordinates[ axe::y ] + c ) / sqrt( pow( a, 2 ) + pow( b, 2 ) );
}


bool Line::isParaller( Line line )
{
	return ( -a / b ) == ( -line.a / b );
}


bool Line::isPerpendicular( Line line )
{
	return ( -a / b) * (-line.a / b ) == -1;
}


Point Line::intersection( Line line )
{
	if ( isParaller( line )) {
		throw std::invalid_argument("Line can not be perpendicular.");
	}

	double x = (b * line.c - line.b * c) / (a * line.b - line.a - b);
	double y = (line.a * c - a * line.c) / (a * line.b - line.a - b);

	return Point(x, y);
}
