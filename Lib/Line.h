//
// Created by Martin Miksik on 21/05/2018.
//

#pragma once

#include "GeometricEntity.h"
#include "Point.h"
#include "Vector.h"

class Line : GeometricEntity
{
public:
//	Line( Point _point, Vector _vector );
	Line( Point _pointA,  Point _pointB);

	double distance( Point point );

	bool isParaller( Line line );

	bool isPerpendicular( Line line);

	Point intersection( Line line);

	Point pointA;
	Point pointB;

	double a;
	double b;
	double c;
};
