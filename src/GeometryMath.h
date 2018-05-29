//
// Created by Martin Miksik on 29/05/2018.
//

#pragma once

#include<cmath>

#include "Vector.h"
#include "Line.h"
#include "Polygon.h"
#include "Circle.h"

namespace GeometryMath {
	//
	// Distance from Vector to ...
	//

	template <>
	double distance( Vector& v1, Vector& v2 )
	{
		return sqrt( pow( v1.x - v2.x, 2 ) + pow( v1.y - v2.y, 2 ) );
	}


	template <>
	double distance( Vector& v, Line& l )
	{
		double d = sqrt( l.a * l.a + l.b * l.b );
		double d1 = abs( l.a * v.x + l.b * v.y + l.c );
		return d1 / d;
	}


	template < int size >
	double distance( Vector& v, Polygon < size >& p )
	{
		Line line = Line( p.vectors[ p.vectors.size() - 1 ], p.vectors[ 0 ] );
		double distance = line.distance( v );

		for ( int i = 0; i < p.vectors.size() - 1; ++i ) {

			line = Line( p.vectors[ i ], p.vectors[ i + 1 ] );

			double d = line.distance( v );

			if ( d < distance ) {
				distance = d;
			}
		}

		return distance;
	}


	template <>
	double distance( Vector& v, Circle& c )
	{
		Vector d = ( v - c.center );
		return d.length();
	}

	//
	// Distance from line to ...
	//

	template <>
	double distance( Line& l, Vector& v )
	{
		return distance( v, l );
	}


	template <>
	double distance( Line& l1, Line& l2 )
	{
		throw std::invalid_argument( "Unimplemented" );
	}


	template < int size >
	double distance( Line& l, Polygon < size >& p )
	{
		throw std::invalid_argument( "Unimplemented" );
	}


	template <>
	double distance( Line& l, Circle& c )
	{
		return distance( l, c.center );
	}


	//
	// Distance from polygon to ...
	//

	template < int size >
	double distance( Polygon < size >& p, Vector& v )
	{
		Line line = Line( p.vectors[ p.vectors.size() - 1 ], p.vectors[ 0 ] );
		double distance = line.distance( v );

		for ( int i = 0; i < p.vectors.size() - 1; ++i ) {

			line = Line( p.vectors[ i ], p.vectors[ i + 1 ] );

			double d = line.distance( v );

			if ( d < distance ) {
				distance = d;
			}
		}

		return distance;
	}


	template < int size >
	double distance( Polygon < size >& p, Line& l )
	{
		throw std::invalid_argument( "Unimplemented" );
	}


	template < int size1, int size2 >
	double distance( Polygon < size1 >& p1, Polygon < size2 >& p2 )
	{
		throw std::invalid_argument( "Unimplemented" );
	}


	template < int size >
	double distance( Polygon < size >& p, Circle& c )
	{
		return distance( p, c.center );
	}

	//
	// Distance from circle to ...
	//

	template <>
	double distance( Circle& c1, Circle& c2 )
	{
		return distance( c1.center, c1.center );
	}


	template <>
	double distance( Circle& c, Line& l )
	{
		auto v = l.nearestVector( c.center );
		return distance( v, c );
	}


	template < int size >
	double distance( Circle& c, Polygon < size >& p )
	{
		return distance( p, c );
	}


	template <>
	double distance( Circle& c, Vector& v )
	{
		return distance( v, c );
	}

};