//
// Created by Martin Miksik on 21/05/2018.
//

#include "GeometricEntity.h"
#include "Point.h"
#include "Vector.h"

class Line : GeometricEntity
{
public:
	Line(Point _point, Vector _vector);

	double distance(Point point);

	Point point;
	Vector vector;
};
