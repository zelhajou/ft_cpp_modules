#include "RPN.hpp"

RPN::RPN() {
}

RPN::RPN(const RPN &other) {
    _stack = other._stack;
}

RPN &RPN::operator=(const RPN &other) {
    if (this != &other) {
        _stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {
}

bool RPN::isOperator(const std::string &token) const {
    if (token == "+" || token == "-" || token == "*" || token == "/") {
        return true;
    }
    return false;
}

bool RPN::isNumber(const std::string &token) const
{
    if (token.empty() || token.size() > 1) {
        return false;
    }
    if (token[0] >= '0' && token[0] <= '9') {
        return true;
    }
    return false;
}

void PRN::per

int RPN::evaluate(const std::string &expression)
{
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token)
    {
        if (isNumber(token))
        {
            int num = token[0] - '0';
            if (num >= 10)
                throw std::runtime_error("Error");
            _stack.push(num);
        }
        else if (isOperator(token)) {
            performOperation(token);
        }
        else {
            throw std::runtime_error("Error");
        }
    }

    if (_stack.size() != 1)
        throw std::runtime_error("Error");
    
    return _stack.top();
}