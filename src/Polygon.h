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
	Polygon( std::array < Vector, size > & _points ) : vectors{ _points }, maxX(vectors[ 0 ].x) {
		for ( int i = 1 ; i < vectors.size(); ++i ) {
			if (vectors[ i ].x > maxX) maxX = vectors[ i ].x;
		}
	}


	double distance( Vector point )
	{
		Line line = Line( vectors[ vectors.size() - 1 ], vectors[ 0 ] );
		double distance = line.distance( point );

		for ( int i = 0; i < vectors.size() - 1; ++i ) {

			line = Line( vectors[ i ], vectors[ i + 1 ] );

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


	Polygon < size > rotate( float angle, Vector point )
	{
		std::array < Vector, size > rotatedPoints = vectors;
		for ( int i = 0; i < vectors.size(); ++i ) {
			rotatedPoints[ i ] = vectors[ i ].rotate( angle, point );
		}

		return Polygon < size >( rotatedPoints );
	}


	std::array < Vector, size > getVectors( )
	{
		return vectors;
	}


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


private:
	double maxX;
	std::array < Vector, size > vectors;
};
