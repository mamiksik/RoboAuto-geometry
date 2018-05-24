//
// Created by Martin Miksik on 24/05/2018.
//

#pragma once

#include <gtest/gtest.h>
#include "../src/Line.h"

#define PRECISION 0.00001

TEST( Line, distance )
{
	Vector A(1, 0);
	Vector B(0, 1);
	Vector C(1, 1);

	Line p{A, B};
	ASSERT_NEAR(p.distance(C), 1.41421 / 2 , PRECISION);
}


TEST( Line, segmentDistance )
{
	Vector A(1, 0);
	Vector B(0, 1);

	Vector D(0, 2);
	Vector O(-1, 2);

	Line p{A, B};

	ASSERT_NEAR(p.segmentDistance(D), 1, PRECISION);
	ASSERT_NEAR(p.segmentDistance(O), 1.4142171, PRECISION);
}


TEST( Line, isParaller )
{
	Vector A(0, 0);
	Vector B(1, 1);

	Vector C(-1, 0);
	Vector D(0, 1);

	Line p{A, B};
	Line u{C, D};

	ASSERT_EQ(p.isParaller(u), true);
}

TEST( Line, isPerpendicular )
{
	Vector A(0, 0);
	Vector B(1, 1);

	Vector D(-1, -1);

	Line p{A, B};
	Line u{A, D};

	ASSERT_EQ(p.isPerpendicular(u), true);
}


TEST( Line, intersect )
{
	Vector A(0, 0);
	Vector B(1, 1);

	Vector C(-1, 1);
	Vector D(1, 0);

	Line p{A, B};
	Line u{C, D};

	ASSERT_EQ(p.intersect(u), true);
}

TEST( Line, intersection )
{
	Vector A(0, 0);
	Vector B(2, 2);

	Vector C(0, 2);
	Vector D(2, 0);

	Line p{A, B};
	Line u{C, D};

	Vector I(1, 1);

	ASSERT_EQ(p.intersection(u), I);
}