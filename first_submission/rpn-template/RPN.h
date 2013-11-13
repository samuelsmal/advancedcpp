#ifndef RPN_H
#define RPN_H

#include <vector>
#include <iostream>
#include "pvector.h"

export
template <typename T>
class RPN {
 private:
  pvector<T> stack;

  bool parseInput(std::string input); // Returns false if calc is finished.
  void printStack();

 public:
  RPN(std::string stack_var) : stack {stack_var} {}
  RPN() : stack {"rpn-stack.txt"} {}
  ~RPN() {}

  void add();
  void subtract();
  void multiply();
  void divide();

  void pushToStack(T num);
  void popOfStack();

  void startConsole();
};

#include "_RPN.impl"

#endif // RPN_H
