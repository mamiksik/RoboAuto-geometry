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
	             pow( point.coordinates[ axe::y ], 2 ) +
	             pow( point.coordinates[ axe::z ], 2 )
	);
}


bool Vector::operator==( const Vector vector )
{
	return point.coordinates[ axe::x ] == vector.point.coordinates[ axe::x ] &&
	       point.coordinates[ axe::y ] == vector.point.coordinates[ axe::y ] &&
	       point.coordinates[ axe::z ] == vector.point.coordinates[ axe::z ];
}


bool Vector::operator!=( const Vector vector )
{
	return point.coordinates[ axe::x ] != vector.point.coordinates[ axe::x ] ||
	       point.coordinates[ axe::y ] != vector.point.coordinates[ axe::y ] ||
	       point.coordinates[ axe::z ] != vector.point.coordinates[ axe::z ];
}


Vector Vector::operator+( const Vector vector )
{
	const Point a = Point( point.coordinates[ axe::x ] + vector.point.coordinates[ axe::x ],
	                       point.coordinates[ axe::y ] + vector.point.coordinates[ axe::y ],
	                       point.coordinates[ axe::z ] + vector.point.coordinates[ axe::z ] );
	return Vector( a );
}


double Vector::operator+( const int i )
{
	return length() + i;
}


Vector Vector::operator-( Vector vector )
{
	const Point a = Point( point.coordinates[ axe::x ] - vector.point.coordinates[ axe::x ],
	                       point.coordinates[ axe::y ] - vector.point.coordinates[ axe::y ],
	                       point.coordinates[ axe::z ] - vector.point.coordinates[ axe::z ] );
	return Vector( a );
}


double Vector::operator-( const int i )
{
	return length() - i;
}


Vector Vector::operator*( Vector vector )
{
	double x = point.coordinates[ axe::y ] * vector.point.coordinates[ axe::z ] -
	           vector.point.coordinates[ axe::y ] * point.coordinates[ axe::z ];

	double y = point.coordinates[ axe::z ] * vector.point.coordinates[ axe::x ] -
	           vector.point.coordinates[ axe::z ] * point.coordinates[ axe::x ];

	double z = point.coordinates[ axe::x ] * vector.point.coordinates[ axe::y ] -
	           vector.point.coordinates[ axe::x ] * point.coordinates[ axe::y ];

	return Vector( Point( x, y, z ) );
}

