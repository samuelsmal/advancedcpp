#include "util.h"

namespace Util {
int gcd(int a, int b) {
  int t {b};
  while (b != 0) {
    t = b;
    b = a % t;
    a = t;
  }
  return t;
}
}

