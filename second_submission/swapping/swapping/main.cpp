//
//  main.cpp
//  swapping
//
//  Created by Samuel von Bausznern on 04.01.14.
//  Copyright (c) 2014 Samuel von Bausznern. All rights reserved.
//

#include <iostream>

void c_swap(int *a, int *b) {
  int c=*a;
  *a=*b;
  *b=c;
}

void swap(int& a, int& b) {
  int c = a;
  a = b;
  b = c;
}

int main(int argc, const char * argv[])
{
  int a = 3;
  int b = 5;
  
  c_swap(&a, &b);
  
  std::cout << a << " " << b << std::endl;
  
  swap(a, b);

  std::cout << a << " " << b << std::endl;
  return 0;
}

