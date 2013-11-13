#include <iostream>
#include "pset.h"
#include <string>
#include "fraction.h"
#include <complex>

int main()
{
  pset<std::string> string_set {"string.pset"};
  std::string s{"woo ooo"};
  string_set.insert(s);

  string_set.insert(std::string{"Wooo ooo"});
  string_set.insert(std::string{"Halll ooooooo oooooo ooooo"});
  string_set.insert(std::string{"pushed back"});
  string_set.erase(std::string{"pushed back"});
  string_set.insert(std::string{"xerased"});
  string_set.erase(--string_set.end());

  pset<Fraction> fraction_set {"fraction.pset"};
  Fraction f{1, 2};
  fraction_set.insert(f);
/*
  pset<std::complex<double>> pstring_set_complex_double {"complex_double.pset"};
  std::complex<double> cd{1.1, 1.2};
  pstring_set_complex_double.insert(cd);
  pstring_set_complex_double.insert(std::complex<double>{1.12,2.23});
  pstring_set_complex_double.insert(std::complex<double>{3.14,3.31});
  pstring_set_complex_double.insert(std::complex<double>{0.0,0.0});
  pstring_set_complex_double.erase(std::complex<double>{0.0,0.0});
  pstring_set_complex_double.insert(std::complex<double>{1.0,1.0});
  pstring_set_complex_double.erase(--pstring_set_complex_double.end());

  pset<std::complex<int>> pstring_set_complex_int {"complex_int.pset"};
  pstring_set_complex_int.insert(std::complex<int>{1,2});
  pstring_set_complex_int.insert(std::complex<int>{2,3});
  pstring_set_complex_int.insert(std::complex<int>{0,0});
  pstring_set_complex_int.erase(--pstring_set_complex_int.end());*/

  return 0;
}
