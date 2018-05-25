//
// Created by Martin Miksik on 22/05/2018.
//

#pragma once

#include <stdexcept>
#include "Drawer.h"

#include "Vector.h"


class Line : public Drawable
{
public:
	Line( Vector & _from, Vector & _to, bool _infinite = false ) : from( _from ),
	                                                               to( _to ),
	                                                               a( from.y - to.y ),
	                                                               b( to.x - from.x ),
	                                                               c( -b * from.y + -a * from.x ),
	                                                               infinite( _infinite ) { };


	double distance( Vector vector )
	{
		return abs( a * vector.x + b * vector.y + c ) / sqrt( pow( a, 2 ) + pow( b, 2 ) );
	};


	double segmentDistance( Vector & vector )
	{
		Vector diff = vector - nearestVectorOnLineSegment( vector );
		return diff.length();
	}


	bool isParaller( Line line )
	{
		return ( -a / b ) == ( -line.a / b );
	}


	bool isPerpendicular( Line line )
	{
		return ( -a / b ) * ( -line.a / b ) == -1;
	}

	Vector normalVector()
	{
		return {x, -y};
	}

	bool intersect( Line line )
	{
		Orientation o1 = orientation( line.from );
		Orientation o2 = orientation( line.to );

		Orientation o3 = line.orientation( from );
		Orientation o4 = line.orientation( to );

		bool intersect = false;


		if ( o1 != o2 && o3 != o4 ) intersect = true;

		// Special Cases
		// p1, q1 and p2 are colinear and p2 lies on segment p1q1
		if ( o1 == Orientation::collinear && onSegment( line.from ) ) intersect = true;

		// p1, q1 and q2 are colinear and q2 lies on segment p1q1
		if ( o2 == Orientation::collinear && onSegment( line.from ) ) intersect = true;

		// p2, q2 and p1 are colinear and p1 lies on segment p2q2
		if ( o3 == Orientation::collinear && onSegment( line.to ) ) intersect = true;

		// p2, q2 and q1 are colinear and q1 lies on segment p2q2
		if ( o4 == Orientation::collinear && onSegment( line.to ) ) intersect = true;

		return intersect;
	}


	Vector intersection( Line line )
	{
		if ( ( !infinite && !intersect( line ) ) || isParaller( line ) ) {
			//TODO: Exception
			throw std::invalid_argument("Lines do not intersect");
		}

		double x = ( b * line.c - line.b * c ) / ( a * line.b - line.a - b );
		double y = ( line.a * c - a * line.c ) / ( a * line.b - line.a - b );

		return { x, y };
	}


	Vector nearestVectorOnLine( Vector & vector )
	{
		double x = ( -a * b * vector.y + b * b * vector.x - a * c ) / ( b * b + a * a );
		double y = ( a * a * vector.y - a * b * vector.x - b * c ) / ( b * b + a * a );

		return { x, y };
	}


	Vector nearestVectorOnLineSegment( Vector & vector )
	{
		Vector nearest = nearestVectorOnLine(vector);
		Line p = {nearest, vector};

		auto oFrom = p.orientation(from);
		auto oTo = p.orientation(to);

		if (oFrom == oTo && oTo == Orientation::clockWise){
			return from;
		} else if (oFrom == oTo && oTo == Orientation::counterClockWise){
			return to;
		} else {
			return nearest;
		}
	}


	bool onSegment( Vector v )
	{
		return to.x <= std::max( from.x, v.x ) &&
		       to.x >= std::min( from.x, v.x ) &&
		       to.y <= std::max( from.y, v.y ) &&
		       to.y >= std::min( from.y, v.y );

	}

	QAbstractSeries *draw( std::string name ) override
	{
		auto *series = new QLineSeries();
		series->append( from.x, from.y );
		series->append( to.x, to.y );

		series->setName( name.c_str() );
		return series;
	}


//	std::string operator+(std::string ss)
//	{
//		return from + " - " + to + ss;
//	}

//	operator std::string() const{
//		return from + " - " + to;
//	}


private:

	enum Orientation
	{
		collinear = 0,
		clockWise,
		counterClockWise
	};


	Orientation orientation( Vector v )
	{
		double val = ( ( to.y - from.y ) * ( v.x - to.x ) ) - ( ( to.x - from.x ) * ( v.y - to.y ) );
		if ( val == 0 ) return Orientation::collinear;

		return ( val > 0 ) ? Orientation::clockWise : Orientation::counterClockWise;
	}


	Vector from;
	Vector to;

	double a;
	double b;
	double c;

	bool infinite;
};