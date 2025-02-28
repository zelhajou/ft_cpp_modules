#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) : _stack(other._stack) {}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
        _stack = other._stack;
    return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(const char token) const
{
    return token == '+' || token == '-' || token == '*' || token == '/';
}

bool RPN::isNumber(const char token) const
{
    return token >= '0' && token <= '9';
}

void RPN::performOperation(const char op)
{
    if (_stack.size() < 2)
        throw std::runtime_error("Error");

    int b = _stack.top();
    _stack.pop();
    int a = _stack.top();
    _stack.pop();

    switch (op)
    {
    case '+':
        _stack.push(a + b);
        break;
    case '-':
        _stack.push(a - b);
        break;
    case '*':
        _stack.push(a * b);
        break;
    case '/':
        if (b == 0)
            throw std::runtime_error("Error");
        _stack.push(a / b);
        break;
    default:
        throw std::runtime_error("Error");
    }
}

int RPN::evaluate(const std::string &expression)
{
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token)
    {
        if (token.empty())
            continue;

        if (token.length() != 1)
            throw std::runtime_error("Error");

        char c = token[0];

        if (isNumber(c))
        {
            _stack.push(c - '0');
        }
        else if (isOperator(c))
        {
            performOperation(c);
        }
        else
        {
            throw std::runtime_error("Error");
        }
    }

    if (_stack.size() != 1)
        throw std::runtime_error("Error");

    return _stack.top();
}