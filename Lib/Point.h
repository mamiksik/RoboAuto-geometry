//
// Created by Martin Miksik on 21/05/2018.
//

#pragma once

#include "GeometricEntity.h"

class Point : GeometricEntity
{
public:
	Point( double _x, double _y, double _z );

	double distance( Point );

	// Make it private?
	double coordinates[3];
};
