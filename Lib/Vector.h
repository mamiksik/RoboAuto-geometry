//
// Created by Martin Miksik on 21/05/2018.
//

#pragma once

#include "GeometricEntity.h"
#include "Point.h"

class Vector : GeometricEntity
{
public:
	Vector(Point _point);

	double length( );

	bool operator==( Vector vector );

	bool operator!=( Vector vector );

	Vector operator+( Vector vector );
	double operator+( int i );

	Vector operator-( Vector vector );
	double operator-( int i  );

	Vector operator*( Vector vector );

	// Make it private?
	Point point;
};