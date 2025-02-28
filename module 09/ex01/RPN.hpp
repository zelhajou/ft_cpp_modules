#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>

class RPN
{
private:
    std::stack<int> _stack;
    bool isOperator(const char token) const;
    void performOperation(const char op);
    bool isNumber(const char token) const;

public:
    RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    ~RPN();
    int evaluate(const std::string &expression);
};

#endif