#define QT

#include <iostream>
#include "Lib/Vector.h"
#include "Lib/Line.h"
#include "Lib/Polygon.h"

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

	Vector O{ 0, 0 };

	Vector A{ 1, 1 };
	Vector B{ -1.7, 1 };
	Vector C{ 5, 5 };

	Vector K{ 2, 2 };
	Vector L{ 4, 2 };
	Vector M{ 4, 4 };
	Vector N{ 1, 4 };

	Vector F{ 3.3, 3.3 };
	Vector R{ 1.5, 3.3 };

	Vector Q{ 4, 4 };
	Vector W{ 3, 3 };
	Vector E{ -1, 4 };
	Vector T{ 0, 2 };
	Vector U{ -1, 0 };
	Vector I{ 3, 1 };

	Line p = Line( A, C );

	std::array < Vector, 4 > point = { K, L, M, N };
	std::array < Vector, 6 > pointl = { Q, W, E, T, U, I };

	Polygon < 4 > o( point );
	Polygon < 6 > l( pointl );


	// Point test
	assert < bool >( o.contains( R ), true );
	assert < double >( roundf( A.distance( O ) * 100 ) / 100,  roundf( 1.41 * 100 ) / 100);

	assert < bool >( o.contains( B ), false );
	assert < bool >( o.contains( F ), true );

	assert < bool >( o.contains( R ), true );
	assert < bool >( l.contains( R ), true );

	auto *chart = new QChart();
	chart->addSeries( B.draw( "B" ) );
	chart->addSeries( F.draw( "F" ) );
	chart->addSeries( R.draw( "R" ) );
	chart->addSeries( p.draw( "p" ) );
	chart->addSeries( o.draw( "o" ) );
	chart->addSeries( l.draw( "l" ) );

	chart->addSeries( ( o.rotate( 10, O ) ).draw( "o rotated" ) );

	chart->setTitle( "Data" );
	chart->createDefaultAxes();
	chart->axisX()->setRange( -10, 10 );
	chart->axisY()->setRange( -10, 10 );


	auto *chartView = new QChartView( chart );

	chartView->setRenderHint( QPainter::Antialiasing );
	chartView->setRubberBand( QChartView::RectangleRubberBand );

	QMainWindow window;
	window.setCentralWidget( chartView );
	window.resize( 400, 400 );
	window.show();

	return application.exec();

//	Vector a{ A };
//	Vector b{ B };
//
//	// Vector test
//	std::cout << ( b == a ) << " : Should be false" << std::endl;
//	std::cout << ( a != a ) << " : Should be false" << std::endl;
//
//	std::cout << ( a + b ).point.coordinates[ GeometricEntity::axe::x ] << " : Should be 1" << std::endl;
//	std::cout << ( a - 1 ) << " : Should be 0.41" << std::endl;
//
//	std::cout << a * b << " : Should be 0" << std::endl;
//
//
//	Line p = Line( A, B );
//	Line o = Line( X, B );
//
//	Line q = Line( Z, Q );
//
//	// Line Test
//	std::cout << p.isPerpendicular( o ) << " : Should be true" << std::endl;
//	std::cout << p.isParaller( q ) << " : Should be true" << std::endl;
//
//	std::cout << p.distance( C ) << " : Distance from p to A. Should be 0" << std::endl;
//	std::cout << p.distance( D ) << " : Distance from p to B. Should be 1.41" << std::endl;
//
//	Point K{ 1, 1 };
//	Point L{ 2, 1 };
//	Point M{ 2, 2 };
//	Point N{ 1, 2 };

//	Polygon polygon = {K, L, M, N};
//	std::vector<double> t(1000);
//	std::vector<double> x(t.size());

//	std::vector<double> x(1),y(1);
//	x.at(0) = (A.coordinates[Point::axe::x]);
//	y.at(0) = (A.coordinates[Point::axe::y]);

//	plt::scatter < int >( 2, 2 );
//
//	plt::xkcd();
//	plt::legend();
//	plt::grid( true );
//	plt::save( "xkcd.png" );

}

