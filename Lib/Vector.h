//
// Created by Martin Miksik on 21/05/2018.
//

#pragma once

#include <cmath>
#include <sstream>
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
		return sqrt( pow( x, 2 ) + pow( y, 2 ) );
	}


	double distance( Vector vector )
	{
		return sqrt( pow( vector.x - x, 2 ) + pow( vector.y - y, 2 ) );
	}


	double alpha( )
	{
		return atan2(y, x);
	}


	Vector rotate( float radian )
	{
		float s = sin( radian );
		float c = cos( radian );

		return Vector(
				x * c - y * s,
				x * s + y * c
		);
	}


	Vector rotate( float radian, Vector center )
	{
		float s = sin( radian );
		float c = cos( radian );

		return Vector(
				( x * c - y * s ) + center.x,
				( x * s + y * c ) + center.y
		);
	}

	//TODO: Check
	double angleWith(Vector& vector){
		return abs(alpha() - vector.alpha());
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


	Vector operator!( )
	{
		return Vector( -x, -y );
	}


	Vector operator+( Vector vector )
	{
		return Vector( x + vector.x, y + vector.y );
	}


	double operator+( double i )
	{
		return length() + i;
	}


	Vector operator-( Vector vector )
	{
		return Vector( x - vector.x, y - vector.y );
	}


	double operator-( double i )
	{
		return length() - i;
	}


	Vector operator*( double i )
	{
		return Vector( i * x, i * y );
	}


	double operator*( Vector vector )
	{
		return x * vector.y + y * vector.y;
	}

	std::string operator std::string() const {
		std::ostringstream strs;
		strs << "[" << x << "," << y << "]";
		return strs.str();
	}


	double x;
	double y;
};