#include <iostream>
#include "RPN.h"
#include <complex> // Doesn't compile. See RPN<T>::divide().
#include "fraction.h"

int main(int argc, char** argv)
{
  RPN<Fraction> rpn_calculator{"Fraction.txt"};
  rpn_calculator.startConsole();
  return 0;
}
