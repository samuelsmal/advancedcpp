//
//  main.cpp
//  range_checking_itr
//
//  Created by Samuel von Bausznern on 04.12.13.
//  Copyright (c) 2013 Samuel von Bausznern. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stdexcept>

#include "RangedIterator.h"

struct foo_bar {
  int foofoo_bar;
};

int main(int argc, const char * argv[])
{
  std::srand(static_cast<unsigned>(std::time(0)));
  
  std::vector<int> v;
  
  for (std::size_t i {0}; i < 5; ++i) {
    v.push_back(std::rand());
  }
  
  RangedIterator<std::vector<int>::iterator> r_itr (v.begin(), v.end());
  
  std::cout << "Content of int vector: ";
  std::copy(v.begin(), v.end(),
            std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;
  
  std::cout << "With RangedIterator\n";
  
  try {
    for (int i {0}; i < 6; ++i) {
      std::cout << *r_itr++ << std::endl;
    }
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  
  try {
    for (int i {0}; i < 6; ++i) {
      std::cout << *--r_itr << std::endl;
    }
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  
  std::vector<foo_bar> foo_bar_vector;
  
  for (std::size_t i {0}; i < 5; ++i) {
    foo_bar_vector.emplace_back(foo_bar{std::rand()});
  }
  
  std::cout << "Content of foo_bar vector: ";
  for (auto el : foo_bar_vector) {
    std::cout << el.foofoo_bar << " ";
  }
  std::cout << std::endl;
  
  RangedIterator<std::vector<foo_bar>::iterator> foo_bar_r_itr(foo_bar_vector.begin(), foo_bar_vector.end());
  
  std::cout << "With RangedIterator\n";
  
  try {
    for (int i {0}; i < 6; ++i) {
      std::cout << foo_bar_r_itr++->foofoo_bar << std::endl;
    }
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  
  try {
    for (int i {0}; i < 6; ++i) {
      std::cout << --foo_bar_r_itr->foofoo_bar << std::endl;
    }
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}

