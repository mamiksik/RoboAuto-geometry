//
// Created by Martin Miksik on 21/05/2018.
//

#pragma once

#include <array>

#include "Line.h"

template < int size >
class Polygon
{
public:
	Polygon( std::array < Vector, size > & _points ) : points{ _points } { }


	double distance( Vector point )
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


	bool contains( Vector point )
	{
		double x = point.x;
		double y = point.y;

		bool inside = false;
		int count = 0;
		for ( int i = 0; i < points.size() - 1; ++i ) {

			Line line{ points[ i ], points[ i + 1 ] };
//			double xi = points[ i ].x;
//			double yi = points[ i ].y;

//			double xj = points[ i + 1 ].x;
//			double yj = points[ i + 1 ].y;


//			bool intersect = ( ( yi > y ) != ( yj > y ) ) && ( x < ( xj - xi ) * ( y - yi ) / ( yj - yi ) + xi );

//			if ( intersect ) inside = !inside;

			if ( line.intersection( line ) ) count++;
		}

		std::cout << count << std::endl;

		return count % 2 != 0;
	}


	Polygon < size > rotate( float angle, Vector point )
	{
		auto rotatedPoints = std::array < Vector, size >{ point, point, point, point };
		for ( int i = 0; i < points.size(); ++i ) {
			rotatedPoints[ i ] = points[ i ].rotate( angle, point );
		}

		return Polygon < size >( rotatedPoints );
	}


	QLineSeries *draw( std::string name = "" )
	{
		auto *lineSerie = new QLineSeries();
		for ( int i = 0; i < points.size(); ++i ) {
			lineSerie->append( points[ i ].x, points[ i ].y );
		}

		lineSerie->append( points[ 0 ].x, points[ 0 ].y );
		lineSerie->setName( name.c_str() );

		return lineSerie;
	}


private:
	std::array < Vector, size > points;
//	auto *lineSerie;
};
