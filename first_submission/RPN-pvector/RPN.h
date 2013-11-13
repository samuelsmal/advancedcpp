#ifndef RPN_H
#define RPN_H

#include <vector>
#include <iostream>
#include "pvector.h"

class RPN {
 private:
  pvector<int> stack;

  bool parseInput(std::string input);
  void printStack();

  bool shouldTerminate{false}; // Rather ugly hack. Used to clean up.

 public:
  RPN(std::string stack_var) : stack{stack_var} {}
  RPN() : stack{"rpn-stack.txt"} {}
  ~RPN() {}

  void startConsole();
};

#endif // RPN_H
