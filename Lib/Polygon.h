//
// Created by Martin Miksik on 21/05/2018.
//

#pragma once

#include <vector>
#include <array>
#include "Point.h"
#include "Line.h"

template < int size >
class Polygon
{
public:
	Polygon( std::array < Point, size > & _points ) : points{ _points } { }


	double distance( Point point )
	{
		Line line = Line( points[ points.size() - 1 ], points[ 0 ] );

		double distance = line.distance( point );

		for ( int i = 0; i < points.size() - 1; ++i ) {

			line = Line( points[ i ], points[ i + 1 ] );

			double d = line.distance( point );

			if ( d < distance ) {
				distance = d;
			}
		}

		return distance;
	};


	bool isWithin( Point point )
	{
		double x = point.coordinates[ Point::axe::x ];
		double y = point.coordinates[ Point::axe::y ];

		bool inside = false;
		for ( int i = 0; i < points.size() - 1; ++i ) {

			double xi = points[ i ].coordinates[ Point::axe::x ];
			double yi = points[ i ].coordinates[ Point::axe::y ];

			double xj = points[ i + 1 ].coordinates[ Point::axe::x ];
			double yj = points[ i + 1 ].coordinates[ Point::axe::y ];


			bool intersect = ( ( yi > y ) != ( yj > y ) ) && ( x < ( xj - xi ) * ( y - yi ) / ( yj - yi ) + xi );

			if ( intersect ) inside = !inside;
		}

		return inside;
	}


	Polygon < size > rotate( float angle, Point point )
	{
		std::array < Point, size > rotatedPoints;
		for ( int i = 0; i < points.size(); ++i ) {
			rotatedPoints[i] = points[i].rotate(angle, point);
		}

		return Polygon<size>(rotatedPoints);
	}


private:
	std::array < Point, size > points;
};
