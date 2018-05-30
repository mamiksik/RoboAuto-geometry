//
// Created by Martin Miksik on 21/05/2018.
//

#pragma once

#include <array>
#include <iostream>

#include "Vector.h"
#include "Line.h"

template < int size >
class Polygon : public Drawable
{
public:
	Polygon( std::array < Vector, size >& _points ) : vectors{ _points }, maxX( _points[ 0 ].x )
	{
		for ( int i = 1; i < vectors.size(); ++i ) {
			if ( vectors[ i ].x > maxX ) maxX = vectors[ i ].x;
		}
	}


	template < int newSize = size + 1 >
	Polygon < newSize > addVector( Vector v, int index = size )
	{
		std::array < Vector, newSize > newVectors;

		for ( int i = 0; i < newSize; ++i ) {
			if ( i == index ) {
				newVectors[ i ] = v;
			} else if ( i > index ) {
				newVectors[ i ] = vectors[ i - 1 ];
			} else {
				newVectors[ i ] = vectors[ i ];
			}
		}

		return Polygon < newSize >( newVectors );
	}


	template < class T >
	bool contains( T& object )
	{
		return GeometryMath::contains( * this, object );
	}


	template < class T >
	double distance( T& object )
	{
		return GeometryMath::distance( * this, object );
	}


	QAbstractSeries *draw( std::string name ) override
	{
		auto *lineSeries = new QLineSeries();
		for ( int i = 0; i < vectors.size(); ++i ) {
			lineSeries->append( vectors[ i ].x, vectors[ i ].y );
		}

		lineSeries->append( vectors[ 0 ].x, vectors[ 0 ].y );
		lineSeries->setName( name.c_str() );
		return lineSeries;
	}


	Polygon < size > rotate( double angle, Vector vector = Vector{ 0, 0 } )
	{
		std::array < Vector, size > rotatedPoints = vectors;
		for ( int i = 0; i < vectors.size(); ++i ) {
			rotatedPoints[ i ] = vectors[ i ].rotate( angle, vector );
		}

		return Polygon < size >( rotatedPoints );
	}


	std::array < Vector, size > vectors;
	double maxX;
};
