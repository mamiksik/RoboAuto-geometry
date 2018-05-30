#include <iostream>
#include "Vector.h"
#include "Line.h"
#include "Polygon.h"
#include "Circle.h"
#include "Drawer.h"

#include <QtCharts>

using namespace QtCharts;


template < typename T >
void assert( T result, T expected )
{
	if ( result != expected ) {
		std::cout << "\033[1;31m Test failed: " << result << " != " << expected << "\033[0m\n";
	} else {
		std::cout << "\033[1;32m Test passed: " << result << " = " << expected << "\033[0m\n";
	}
}


int main( int argc, char *argv[] )
{
	QApplication application( argc, argv );

//	std::string q = " - " + v.x + " - " v.y;

//	std::cout <<  v.distance(C) << " - " << v.x << " - " << v.y<< std::endl;

//	Drawer::draw(v, "nearest");

//	Drawer::show();

	/*Vector O{ 0, 0 };

	Vector A{ 1, 1 };
	Vector B{ -1.7, 1 };
	Vector C{ 5, 5 };

	Vector K{ 2, 2 };
	Vector L{ 4, 2 };
	Vector M{ 4, 4 };
	Vector N{ 2, 4 };

	Vector F{ 3, 3.3 };
	Vector R{ 1.5, 3.6 };

	Vector Q{ 4, 4 };
	Vector W{ 3, 3 };
	Vector E{ -1, 4 };
	Vector T{ 0, 2 };
	Vector U{ -1, 0 };
	Vector I{ 3, 1 };



	std::array < Vector, 4 > point = { K, L, M, N };
	std::array < Vector, 6 > pointl = { Q, W, E, T, U, I };

	Polygon < 4 > o( point );
	Polygon < 6 > l( pointl );


	// Point test
	assert < double >( roundf( A.distance( O ) * 100 ) / 100,  roundf( 1.41 * 100 ) / 100);

	assert < bool >( o.contains( B ), false );
	assert < bool >( o.contains( F ), true );
	assert < bool >( l.contains( F ), false );
//
	Drawer::draw(R, "R");

	Drawer::draw(o, "o");
	Drawer::draw(l, "l");

	assert < bool >( o.contains( R ), false );
	assert < bool >( l.contains( R ), false );
//	assert < bool >( p.intersect( Line(R, Vector(99999, R.y)) ), false );

	Drawer::draw(B, "B");
	Drawer::draw(F, "F");

	Polygon<4> r = o.rotate(25, B);
	Polygon<6> p = l.rotate(-90, B);

	Vector Z {0, 5};
	Drawer::draw(Z, "Z");
	Drawer::draw(p, "p");

	assert < bool >( r.contains( F ), false );
	assert < bool >( r.contains( Z ), false );*/

//	/assert < bool >( p.contains( Z ), true );

//	Drawer::draw(r, "r");

//	Drawer::draw(p, "p");

	Vector O{ 0, 0 };

	Vector A{ 1, 1 };
	Vector B{ -1.7, 1 };
	Vector C{ 5, 5 };

	Vector K{ 2, 2 };
	Vector L{ 0, 2 };
	Vector M{ 0, 0 };
	Vector N{ 2, 0 };

	Vector F{ 3, 3.3 };
	Vector R{ 1.5, 3.6 };

	Vector Q{ 4, 4 };
	Vector W{ 3, 3 };
	Vector E{ -1, 4 };
	Vector T{ 0, 2 };
	Vector U{ -1, 0 };
	Vector I{ 3, 1 };



	std::array < Vector, 4 > point = { K, L, M, N };
	std::array < Vector, 6 > pointl = { Q, W, E, T, U, I };


//	Vector W{ 1, 1 };

	Polygon < 4 > o( point );
	Polygon < 6 > l( pointl );

	auto pol = o.addVector(A, 0);


//	Drawer::draw(o, "o");
//	Drawer::draw(l,"l");
	Drawer::draw(pol, "pol");

	Drawer::show();

	return application.exec();

}

