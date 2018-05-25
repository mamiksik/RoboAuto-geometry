//
// Created by Martin Miksik on 21/05/2018.
//

#pragma once

#include <array>
#include <iostream>

#include "Line.h"

template < int size >
class Polygon : public Drawable
{
public:
	Polygon( std::array < Vector, size > & _points ) : vectors{ _points }, maxX( _points[ 0 ].x )
	{
		for ( int i = 1; i < vectors.size(); ++i ) {
			if ( vectors[ i ].x > maxX ) maxX = vectors[ i ].x;
		}
	}


	bool contains( Vector point )
	{
		double x = point.x;
		double y = point.y;

		bool inside = false;
		int count = 0;

		Vector rayEnd( maxX + 1, point.y );

		Line ray{ point, rayEnd };

		Line line{ vectors[ vectors.size() - 1 ], vectors[ 0 ] };
		if ( line.intersect( ray ) ) count++;

		for ( int i = 0; i < vectors.size() - 1; ++i ) {

			line = Line{ vectors[ i ], vectors[ i + 1 ] };

			if ( line.intersect( ray ) ) count++;
		}

		return count % 2 != 0;
	}


	double distance( Vector vector )
	{
		Line line = Line( vectors[ vectors.size() - 1 ], vectors[ 0 ] );
		double distance = line.distance( vector );

		for ( int i = 0; i < vectors.size() - 1; ++i ) {

			line = Line( vectors[ i ], vectors[ i + 1 ] );

			double d = line.distance( vector );

			if ( d < distance ) {
				distance = d;
			}
		}

		return distance;
	};


	QAbstractSeries *draw( std::string name ) override
	{
		auto *lineSeries = new QLineSeries();
		for ( int i = 0; i < getVectors().size(); ++i ) {
			lineSeries->append( getVectors()[ i ].x, getVectors()[ i ].y );
		}

		lineSeries->append( getVectors()[ 0 ].x, getVectors()[ 0 ].y );
		lineSeries->setName( name.c_str() );
		return lineSeries;
	}


	std::array < Vector, size > getVectors( )
	{
		return vectors;
	}


	Polygon < size > rotate( double angle, Vector vector = Vector{0, 0} )
	{
		std::array < Vector, size > rotatedPoints = vectors;
		for ( int i = 0; i < vectors.size(); ++i ) {
			rotatedPoints[ i ] = vectors[ i ].rotate( angle, vector );
		}

		return Polygon < size >( rotatedPoints );
	}


private:
	double maxX;
	std::array < Vector, size > vectors;
};
