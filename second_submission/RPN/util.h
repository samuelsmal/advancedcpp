#ifndef __Util__Util__
#define __Util__Util__

#include <iostream>

namespace Util {
  int gcd(int a, int b);
  inline int lcm(int a, int b) {
    return (a / Util::gcd(a, b)) * b;
  }
  inline void swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
  }
  
  inline void checkChar(std::istream& is, char ch) {
    char c; is >> c;
    if (c != ch) {
      is.putback(c); is.setstate(std::ios::badbit);
    }
  }
  
}

#endif /* defined (__Util__Util__) */
