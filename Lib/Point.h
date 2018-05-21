//
// Created by Martin Miksik on 21/05/2018.
//

#pragma once

#include "GeometricEntity.h"

class Point : GeometricEntity
{
public:
	Point(int _x, int _y, int _z);

	double distance(Point);

	// Make it private?
	int coordinates[3];
};
