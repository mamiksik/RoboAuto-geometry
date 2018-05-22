//
// Created by Martin Miksik on 22/05/2018.
//

#pragma once

#include <stdexcept>
#include "Vector.h"

class Line
{
public:
	Line( Vector A, Vector B ) : vectorA( A ),
	                             vectorB( B ),
	                             a( vectorA.y - vectorB.y ),
	                             b( vectorB.x - vectorA.x ),
	                             c( -b * vectorA.y + -a * vectorA.x ) { };


	double distance( Vector vector )
	{
		return abs( a * vector.x + b * vector.y + c ) / sqrt( pow( a, 2 ) + pow( b, 2 ) );
	};


	bool isParaller( Line line )
	{
		return ( -a / b ) == ( -line.a / b );
	}


	bool isPerpendicular( Line line )
	{
		return ( -a / b ) * ( -line.a / b ) == -1;
	}


	Vector intersection( Line line )
	{
		if ( isParaller( line ) ) {
			throw std::invalid_argument( "Line can not be perpendicular." );
		}

		double x = ( b * line.c - line.b * c ) / ( a * line.b - line.a - b );
		double y = ( line.a * c - a * line.c ) / ( a * line.b - line.a - b );

		return Vector( x, y );
	}


	Vector const vectorA;
	Vector const vectorB;

	double const a;
	double const b;
	double const c;
};