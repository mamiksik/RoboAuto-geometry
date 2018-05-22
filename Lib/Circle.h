//
// Created by Martin Miksik on 21/05/2018.
//

#pragma once

#include "Point.h"

class Circle
{
public:
	Circle( Point _center, double _radius ) : center( _center ), radius( _radius ) { }


	double distance( Point point )
	{
		return center.distance( point );
	}


	Circle rotate( float angle, Point rCenter )
	{
		Point newCenter = center.rotate( angle, rCenter );
		return Circle( newCenter, radius );
	}


private:
	Point center;
	double radius;
};
