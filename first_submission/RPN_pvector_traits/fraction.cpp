//
//  fraction.cpp
//  Fraction
//
//  Created by s0991462 on 9/24/13.
//  Copyright (c) 2013 SVB. All rights reserved.
//

#include "fraction.h"
#include "util.h"

Fraction& Fraction::reduce() {
  int g = Util::gcd(_counter, _denom);
  _counter /= g;
  _denom /= g;
  return *this;
}

Fraction Fraction::reduce(Fraction f) {
  return f.reduce();
}
