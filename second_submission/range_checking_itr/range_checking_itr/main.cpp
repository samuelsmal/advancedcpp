//
//  main.cpp
//  range_checking_itr
//
//  Created by Samuel von Bausznern on 04.12.13.
//  Copyright (c) 2013 Samuel von Bausznern. All rights reserved.
//

#include <iostream>
#include <vector>

#include "RangedIterator.h"

int main(int argc, const char * argv[])
{
    std::srand(static_cast<unsigned>(std::time(0)));

    std::vector<int> v;
    
    for (std::size_t i {0}; i < 5; ++i) {
        v.push_back(std::rand());
    }
    
    RangedIterator<std::vector<int>::iterator> r_itr {v.begin(), v.end()};
    
    for (int i {0}; i < 6; ++i) {
        std::cout << &r_itr++ << std::endl;
    }
    
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

