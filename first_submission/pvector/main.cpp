#include <iostream>
#include "pvector.h"
#include <string>

int main()
{
  pvector<std::string> v {"string.txt"};

  v.push_back("Wooo ooo");
  v.push_back("Halll ooooooo oooooo ooooo");
  v.push_back("pushed back");
  v.pop_back();
  return 0;
}
