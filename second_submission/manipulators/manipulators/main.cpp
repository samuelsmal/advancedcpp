//
//  main.cpp
//  manipulators
//
//  Created by Samuel von Bausznern on 08.01.14.
//  Copyright (c) 2014 Samuel von Bausznern. All rights reserved.
//

#include <iostream>
#include "manipulator.h"

using namespace std;

ostream& fillWithAsterix(ostream& i) {
  i.width(10); i.fill('*');
  return i;
}

int main(int argc, const char * argv[])
{
  cout << fillWithAsterix << "wooaahh" << endl;
  cout << "wooaahh" << endl;
  cout << fillWithAsterix << 123456789 << endl;
  
  cout << 1.123456789f << endl;
  cout << manipulator::scientific << 1.123456789f << endl;
  cout << 1.123456789f << endl;
  cout << manipulator::reset << 1.123456789f << endl;
  
  return 0;
}

