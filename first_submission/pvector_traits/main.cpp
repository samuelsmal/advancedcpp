#include <iostream>
#include <string>
#include <complex>

#include "pvector.h"
#include "fraction.h"

int main()
{
  pvector<std::string> v {"string.txt"};
  v.push_back("Wooo ooo");
  v.push_back("Halll ooooooo oooooo ooooo");
  v.push_back("pushed back");
  v.pop_back();

  pvector<Fraction> pv_fraction{"fraction.pv"};
  pv_fraction.push_back({1,2});
  pv_fraction.push_back({3,4});
  pv_fraction.pop_back();

  pvector<std::complex<double>> pv_complex_double {"complex_double.txt"};
  pv_complex_double.push_back({1.12,2.23});
  pv_complex_double.push_back({3.14,3.31});
  pv_complex_double.push_back({0.0,0.0});
  pv_complex_double.pop_back();

  pvector<std::complex<int>> pv_complex_int {"complex_int.txt"};
  pv_complex_int.push_back({1,2});
  pv_complex_int.push_back({2,3});
  pv_complex_int.push_back({0,0});
  pv_complex_int.pop_back();
  return 0;
}
