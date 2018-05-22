//
// Created by Martin Miksik on 21/05/2018.
//

#pragma once

#include <cmath>

enum Axe {
	x = 0,
	y,
	z
};

class Vector
{
public:
	Vector( double _x, double _y): x(_x), y(_y){};

	double length( )
	{
		return sqrt( pow( x, 2 ) +
		             pow( y, 2 )
		);
	}


	Vector rotate(float angle, Vector center)
	{
		return Vector( 0, 0 );
	}


	bool operator==( Vector vector )
	{
		return x == vector.x && y == vector.y;
	}


	bool operator!=( Vector vector )
	{
		return x != vector.x || y != vector.y;
	}


	Vector operator+( Vector vector )
	{
		return Vector( x + vector.x, y + vector.y);
	}


	double operator+( int i )
	{
		return length() + i;
	}


	Vector operator-( Vector vector )
	{
		return Vector( x - vector.x, y - vector.y);
	}


	double operator-( int i )
	{
		return length() - i;
	}


	double operator*( Vector vector )
	{
		return x * vector.y + y * vector.y;
	}


	const double x;
	const double y;
};