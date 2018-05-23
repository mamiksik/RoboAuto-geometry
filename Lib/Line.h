//
// Created by Martin Miksik on 22/05/2018.
//

#pragma once

#include <stdexcept>
#include <QtCharts>
//#include <opencl-c.h>
//#include <cmath>
#include "Vector.h"

using namespace QtCharts;

class Line
{
public:
	Line( Vector A, Vector B, bool _infinite = true ) : vectorA( A ),
	                                                    vectorB( B ),
	                                                    a( vectorA.y - vectorB.y ),
	                                                    b( vectorB.x - vectorA.x ),
	                                                    c( -b * vectorA.y + -a * vectorA.x ),
	                                                    infinite( _infinite ) { };


	double distance( Vector vector )
	{
		return abs( a * vector.x + b * vector.y + c ) / sqrt( pow( a, 2 ) + pow( b, 2 ) );
	};


	int orientation( Vector v )
	{
		int val = ( vectorA.y - vectorB.y ) * ( v.x - vectorA.x ) -
		          ( vectorA.x - vectorB.x ) * ( v.y - vectorA.y );

		if ( val == 0 ) return 0;  // colinear

		return ( val > 0 ) ? 1 : 2;
	}


	bool onSegment( Vector v )
	{
		if ( vectorB.x <= std::max( vectorA.x, v.x ) && vectorB.x >= std::min( vectorA.x, v.x ) &&
		     vectorB.y <= std::max( vectorA.y, v.y ) && vectorB.y >= std::min( vectorA.y, v.y ) )
			return true;

		return false;
	}


	/*bool isParaller( Line line )
	{
		return ( -a / b ) == ( -line.a / b );
	}


	bool isPerpendicular( Line line )
	{
		return ( -a / b ) * ( -line.a / b ) == -1;
	}*/


	bool intersection( Line line )
	{
//		if ( isParaller( line ) ) {
//			throw std::invalid_argument( "Line can not be paraller." );
//		}

		int o1 = orientation( line.vectorA );
		int o2 = orientation( line.vectorB );

		int o3 = line.orientation( vectorA );
		int o4 = line.orientation( vectorB );

		bool intersect = false;

		if ( o1 != o2 && o3 != o4 ) intersect = true;

		// Special Cases
		// p1, q1 and p2 are colinear and p2 lies on segment p1q1
		if ( o1 == 0 && onSegment( line.vectorA ) ) intersect = true;

		// p1, q1 and q2 are colinear and q2 lies on segment p1q1
		if ( o2 == 0 && onSegment( line.vectorA ) ) intersect = true;

		// p2, q2 and p1 are colinear and p1 lies on segment p2q2
		if ( o3 == 0 && onSegment( line.vectorB ) ) intersect = true;

		// p2, q2 and q1 are colinear and q1 lies on segment p2q2
		if ( o4 == 0 && onSegment( line.vectorB ) ) intersect = true;

		if (intersect) {
			lineS->append( line.vectorA.x, line.vectorA.y );
			lineS->append( line.vectorB.x, line.vectorB.y );
		}
		return intersect;
//		double x = ( b * line.c - line.b * c ) / ( a * line.b - line.a - b );
//		double y = ( line.a * c - a * line.c ) / ( a * line.b - line.a - b );

//		return Vector( x, y );
	}


	QLineSeries *draw( std::string name = "" )
	{
//		auto *line = new QLineSeries();
		lineS->append( vectorA.x, vectorA.y );
		lineS->append( vectorB.x, vectorB.y );

		lineS->setName( name.c_str() );

		return lineS;
	}


	Vector vectorA;
	Vector vectorB;

	double a;
	double b;
	double c;

	bool infinite;

	QLineSeries *lineS = new QLineSeries();
};