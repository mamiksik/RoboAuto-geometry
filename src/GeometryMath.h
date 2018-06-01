//
// Created by Martin Miksik on 29/05/2018.
//

#pragma once

#include<cmath>

#include "Vector.h"
#include "Line.h"
#include "Polygon.h"
#include "Circle.h"

using namespace Geometry;

namespace GeometryMath {
	//
	// Distance from Vector to ...
	//

	template <>
	struct Container < Vector, Vector >
	{
		static double distance( const Vector& v1, const Vector& v2 )
		{
			return std::sqrt( pow( v1.x - v2.x, 2 ) + pow( v1.y - v2.y, 2 ) );
		}
	};

	template <>
	struct Container < Vector, Line >
	{
		static double distance( const Vector& v, const Line& l )
		{
			double d = std::sqrt( l.a * l.a + l.b * l.b );
			double d1 = std::abs( l.a * v.x + l.b * v.y + l.c );
			return d1 / d;
		}
	};

	template < std::size_t size >
	struct Container < Vector, Polygon < size>>
	{
		static double distance( const Vector& v, const Polygon < size >& p )
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
	};


	template <>
	struct Container < Vector, Circle >
	{
		static double distance( const Vector& v, const Circle& c )
		{
			auto d = ( v - c.center );
			return d.length();
		}
	};

	//
	// Distance from line to ...
	//

	template <>
	struct Container < Line, Vector >
	{
		static double distance( const Line& l, const Vector& v )
		{
			return GeometryMath::Container < Vector, Line >::distance( v, l );
		}
	};


	template <>
	struct Container < Line, Line >
	{
		static double distance( const Line& l1, const Line& l2 )
		{
			throw std::invalid_argument( "Unimplemented" );
		}
	};


	template < std::size_t size >
	struct Container < Line, Polygon < size > >
	{
		static double distance( const Line& l, const Polygon < size >& p )
		{
			throw std::invalid_argument( "Unimplemented" );
		}
	};


	template <>
	struct Container < Line, Circle >
	{
		static double distance( const Line& l, const Circle& c )
		{
			return GeometryMath::Container < Line, Vector >::distance( l, c.center );
		}
	};


	//
	// Distance from polygon to ...
	//

	template < std::size_t size >
	struct Container < Polygon < size >, Vector >
	{
		static double distance( const Polygon < size >& p, const Vector& v )
		{
			Line line{ p.vectors[ p.vectors.size() - 1 ], p.vectors[ 0 ] };
			double distance = line.distance( v );

			for ( int i = 0; i < p.vectors.size() - 1; ++i ) {

				line = Line( p.vectors[ i ], p.vectors[ i + 1 ] );

				double d = line.distance( v );

//			if ( d < distance ) {
//				distance = d;
//			}
				distance = std::min( d, distance );
			}

			return distance;
		}


		static bool contains( const Polygon < size >& p, const Vector& v )
		{
			int count = 0;

			Vector rayEnd( p.maxX + 1, v.y );

			Line ray{ v, rayEnd };

			Line line{ p.vectors[ p.vectors.size() - 1 ], p.vectors[ 0 ] };
			count += line.intersect( ray );

			for ( int i = 0; i < p.vectors.size() - 1; ++i ) {

				line = Line{ p.vectors[ i ], p.vectors[ i + 1 ] };
				count += line.intersect( ray );
			}

			return count % 2 != 0;
		}
	};


	template < std::size_t size >
	struct Container < Polygon < size >, Line >
	{
		static double distance( const Polygon < size >& p, const Line& l )
		{
			throw std::invalid_argument( "Unimplemented" );
		}


		static bool contains( const Polygon < size >& p, const Line& l )
		{
			typedef GeometryMath::Container < Polygon < size >, Vector > spocification;
			return !l.infinite && spocification::contains( p, l.from ) && spocification::contains( p, l.to );
		}
	};


	template < std::size_t size1, std::size_t size2 >
	struct Container < Polygon < size1 >, Polygon < size2 > >
	{
		static double distance( const Polygon < size1 >& p1, const Polygon < size2 >& p2 )
		{
			throw std::invalid_argument( "Unimplemented" );
		}


		static bool contains( const Polygon < size1 >& p1, const Polygon < size2 >& p2 )
		{
			for ( Vector v: p2.vectors ) {
				if ( !GeometryMath::Container < Polygon < size1 >, Vector >::contains( p1, v ) ) {
					return false;
				}
			}

			return true;
		}
	};


	template < std::size_t size >
	struct Container < Polygon < size >, Circle >
	{
		static double distance( const Polygon < size >& p, const Circle& c )
		{
			return GeometryMath::Container < Polygon < size >, Vector >::distance( p, c.center );
		}


		static bool contains( const Polygon < size >& p, const Circle& c )
		{
			int count = 0;
			Line l{ p.vectors[ p.vectors.size() - 1 ], p.vectors[ 0 ] };
			count += c.intersect( l );

			for ( int i = 0; i < p.vectors.size() - 1; ++i ) {

				l = Line{ p.vectors[ i ], p.vectors[ i + 1 ] };

				count += c.intersect( l );
			}

			return count == 0 && GeometryMath::Container < Polygon < size >, Vector >::contains( p, c.center );
		}
	};

	//
	// Distance from circle to ...
	//

	template <>
	struct Container < Circle, Circle >
	{
		static double distance( const Circle& c1, const Circle& c2 )
		{
			return GeometryMath::Container < Vector, Vector >::distance( c1.center, c1.center );
		}


		static bool contains( const Circle& p1, const Circle& p2 )
		{
			return distance( p1, p2 ) + p2.radius < p1.radius;
		}
	};


	template <>
	struct Container < Circle, Vector >
	{
		static double distance( const Circle& c, const Vector& v )
		{
			return GeometryMath::Container < Vector, Vector >::distance( c.center, v );
		}


		static bool contains( const Circle& c, const Vector& v )
		{

			return distance( c, v ) <= c.radius;
		}
	};


	template <>
	struct Container < Circle, Line >
	{
		static double distance( const Circle& c, const Line& l )
		{
			auto v = l.nearestVector( c.center );
			return GeometryMath::Container < Vector, Circle >::distance( v, c );
		}


		static bool contains( const Circle& c, const Line& l )
		{
			typedef GeometryMath::Container < Circle, Vector > specification;
			return !l.infinite && specification::contains( c, l.from ) && specification::contains( c, l.to );
		}
	};

	template < std::size_t size >
	struct Container < Circle, Polygon < size >>
	{
		static double distance( const Circle& c, const Polygon < size >& p )
		{
			return GeometryMath::Container < Polygon < size >, Circle >::distance( p, c );
		}


		static bool contains( const Circle& c, const Polygon < size >& p )
		{
			int count = 0;
			Line l{ p.vectors[ p.vectors.size() - 1 ], p.vectors[ 0 ] };
			count += c.intersect( l );

			for ( int i = 0; i < p.vectors.size() - 1; ++i ) {

				l = Line{ p.vectors[ i ], p.vectors[ i + 1 ] };

				count += c.intersect( l );
			}

			for ( auto vec : p.vectors ) {
				count += !c.intersect( l );
			}

			return count == 0;
		}
	};

};