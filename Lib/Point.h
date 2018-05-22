//
// Created by Martin Miksik on 21/05/2018.
//

#pragma once

#include "GeometricEntity.h"

class Point : public GeometricEntity
{
public:
	Point( double _x, double _y);

	double distance( Point );

	Point rotate(float angle, Point center);

	// Make it private?
	double coordinates[2];
};
