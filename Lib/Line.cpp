//
// Created by Martin Miksik on 21/05/2018.
//

#include <cmath>
#include <iostream>
#include "Line.h"


Line::Line( Point _point, Vector _vector ) : point( _point ), vector( _vector )
{

}


double Line::distance( Point p )
{
	Vector v = vector - Vector( p );
	return abs( ( v * vector).length() ) / abs( vector.length() );
}
