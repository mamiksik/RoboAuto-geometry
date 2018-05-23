//
// Created by Martin Miksik on 21/05/2018.
//

#pragma once

#include <cmath>
#include "Drawable.h"

enum Axe
{
	x = 0,
	y,
	z
};

class Vector : public Drawable
{
public:
	Vector( double _x, double _y ) : x( _x ), y( _y ) { };


	double length( )
	{
		return sqrt( pow( x, 2 ) +
		             pow( y, 2 )
		);
	}


	double distance( Vector vector )
	{
		return sqrt( pow( vector.x - x, 2 ) + pow( vector.y - y, 2 ) );
	}


	Vector rotate( float angle, Vector center )
	{
		float s = sin( angle * M_PI / 180 );
		float c = cos( angle * M_PI / 180 );

		double nx = x - center.x;
		double ny = y - center.y;

		// rotate point
		float xnew = x * c - y * s;
		float ynew = x * s + y * c;

		// translate point back:
		nx = xnew + center.x;
		ny = ynew + center.y;

		return Vector( nx, ny );
	}


	QAbstractSeries *draw( std::string name ) override
	{
		auto *point = new QScatterSeries();

		point->setMarkerShape( QScatterSeries::MarkerShapeCircle );
		point->setMarkerSize( 10.0 );

		point->append( x, y );
		point->setName( name.c_str() );

		return point;
	}


	bool operator==( Vector vector )
	{
		return x == vector.x && y == vector.y;
	}


	bool operator!=( Vector vector )
	{
		return x != vector.x || y != vector.y;
	}


	Vector operator+( Vector vector )
	{
		return Vector( x + vector.x, y + vector.y );
	}


	double operator+( int i )
	{
		return length() + i;
	}


	Vector operator-( Vector vector )
	{
		return Vector( x - vector.x, y - vector.y );
	}


	double operator-( int i )
	{
		return length() - i;
	}


	double operator*( Vector vector )
	{
		return x * vector.y + y * vector.y;
	}


	double x;
	double y;
};