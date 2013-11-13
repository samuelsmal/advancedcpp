#ifndef RPN_H
#define RPN_H

#include <vector>
#include <iostream>

class RPN {
    std::vector<int> stack;

    bool parseInput(std::string input);
    void printStack();

    public:
        void startConsole();
        //void startConsole(std::string input);

};

#endif // RPN_H
