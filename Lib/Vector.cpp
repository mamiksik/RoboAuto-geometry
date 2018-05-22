//
// Created by Martin Miksik on 21/05/2018.
//

#include <cmath>
#include <iostream>
#include "Vector.h"


Vector::Vector( Point _point ) : point{ _point }
{
}


double Vector::length( )
{
	return sqrt( pow( point.coordinates[ axe::x ], 2 ) +
	             pow( point.coordinates[ axe::y ], 2 )
	);
}


bool Vector::operator==( const Vector vector )
{
	return point.coordinates[ axe::x ] == vector.point.coordinates[ axe::x ] &&
	       point.coordinates[ axe::y ] == vector.point.coordinates[ axe::y ];
}


bool Vector::operator!=( const Vector vector )
{
	return point.coordinates[ axe::x ] != vector.point.coordinates[ axe::x ] ||
	       point.coordinates[ axe::y ] != vector.point.coordinates[ axe::y ];
}


Vector Vector::operator+( const Vector vector )
{
	const Point a = Point( point.coordinates[ axe::x ] + vector.point.coordinates[ axe::x ],
	                       point.coordinates[ axe::y ] + vector.point.coordinates[ axe::y ] );
	return Vector( a );
}


double Vector::operator+( const int i )
{
	return length() + i;
}


Vector Vector::operator-( Vector vector )
{
	const Point a = Point( point.coordinates[ axe::x ] - vector.point.coordinates[ axe::x ],
	                       point.coordinates[ axe::y ] - vector.point.coordinates[ axe::y ] );
	return Vector( a );
}


double Vector::operator-( const int i )
{
	return length() - i;
}


double Vector::operator*( Vector vector )
{
	return point.coordinates[ axe::x] * vector.point.coordinates[ axe::x ] +
	       point.coordinates[ axe::y] * vector.point.coordinates[ axe::y ];
}

