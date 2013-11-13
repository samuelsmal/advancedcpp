//
//  main.cpp
//  fraction
//
//  Created by s0991462 on 9/24/13.
//  Copyright (c) 2013 SVB. All rights reserved.
//

#include <iostream>

#include "fraction.h"
#include "test.h"

int main(/*int argc, const char * argv[]*/) {
	if (testfraction())
	{
		std::cout << "Everything working fine." << std::endl;
	}
	else
	{
		std::cout << "Errors occured: Debug!" << std::endl;
	}

	Fraction f{1,2}, g{4,10};
	Fraction fg{f*g};

	std::cout << "f: " << f << " g: " << g << " reduced g: " << g.reduce() << "\n"
		<< "f*g: " << fg << " reduced f*g: " << fg.reduce() << std::endl;

    return 0;
}

