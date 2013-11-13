#include "RPN.h"

#include <stdexcept>
#include <cstring>

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::vector;

void RPN::startConsole() {
    if (!stack.empty()) {
        printStack();
    } else {
        cout << endl;
    }

    std::string input;

    while (true) {
        cout << "Command: ";
        std::getline(cin, input);

        if (!parseInput(input) && !shouldTerminate) {
            cout << "Error! Try again." << endl;
        } else if (shouldTerminate) {
          return;
        }

        printStack();
    }
}

void RPN::printStack() {
    cout << endl;
    for (size_t i = 0, e = stack.size(); i < e; ++i) {
        cout << i + 1 << ": " << stack[i] << endl;
    }
}

bool RPN::parseInput(std::string input) {
    if (input.empty())
        return false;

    if (input.at(0) == 'n') {
        if (input.length() > 2) {
            try {
                stack.push_back(
                    std::stoi(
                        input.substr(2, input.length())
                    )
                );
            } catch (const std::invalid_argument& ex) {
                cout << "Input error! Could not convert to int!";
                return false;
            }
        }
    } else if (input.at(0) == 'd') {
        if (stack.size() > 0) stack.pop_back();
    } else if (input.at(0) == 'q') {
        shouldTerminate = true;
    } else if (input.at(0) == '*') {
        if (stack.size() > 1) {
            int a = stack.back();
            stack.pop_back();
            int b = stack.back();
            stack.pop_back();
            stack.push_back(a * b);
        }
    } else if(input.at(0) == '+') {
        if (stack.size() > 1) {
            int a = stack.back();
            stack.pop_back();
            int b = stack.back();
            stack.pop_back();
            stack.push_back(a + b);
        }
    } else if (input.at(0) == '-') {
        if (stack.size() > 1) {
            int a = stack.back();
            stack.pop_back();
            int b = stack.back();
            stack.pop_back();
            stack.push_back(b - a);
        }
    } else if (input.at(0) == '/') {
        if (stack.size() > 1) {
            int a = stack.back();
            stack.pop_back();
            int b = stack.back();
            stack.pop_back();

            if (b == 0) {
                cout << "Division by zero!" << endl;
                stack.push_back(b);
                stack.push_back(a);
            } else {
                stack.push_back(b / a);
            }
        }
    } else {
        cout << "Input parameter is wrong! Try again." << endl << "Your input: " << input << endl;
        return false;
    }
    return true;
}
