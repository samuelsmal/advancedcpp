//
//  test.cpp
//  fraction
//
//  Created by s0991462 on 9/24/13.
//  Copyright (c) 2013 SVB. All rights reserved.
//

#include "test.h"
#include "fraction.h"

bool testfraction() {
	bool testFlag = true;
	Fraction f{2,4}, g{1,3}, h{10,100}, m{-6, -3};

	if (f.counter() != 2 || f.denom() != 4)
	{
		std::cout << "Error: Init." << std::endl;
		testFlag = false;
	}

	Fraction mr{m.reduce()};
	if (mr.counter() != 2 || mr.denom() != 1)
	{
		std::cout << "Error: reduce!" << std::endl;
		testFlag = false;
	}

	Fraction fr{f.reduce()};
	if (fr.counter() != 1 || fr.denom() != 2)
	{
		std::cout << "Error: reduce." << std::endl;
		testFlag = false;
	}

	Fraction fPg = f + g;
	if (fPg.counter() != 5 || fPg.denom() != 6)
	{
		std::cout << "Error: Addition! Result: " << fPg.counter() << " / " << fPg.denom()
		<< " Expected: 5 / 6"  << std::endl;
		testFlag = false;
	}

	Fraction fg = f * g;
	if (fg.counter() != 1 || fg.denom() != 6)
	{
		std::cout << "Error: Multiplication" << std::endl;
		testFlag = false;
	}

	Fraction mfg = m * fg;
	if (mfg.counter() != 1 || mfg. denom() != 3)
	{
		std::cout << "Error: Multiplication" << std::endl;
		testFlag = false;
	}

	return testFlag;
}
