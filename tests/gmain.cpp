//
// Created by Martin Miksik on 24/05/2018.
//


#include "TestVector.h"

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	int ret = RUN_ALL_TESTS();
	return ret;
}