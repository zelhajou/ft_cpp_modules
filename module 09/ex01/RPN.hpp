#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <sstream>
#include <stdexcept>

class RPN {
    private:
        std::stack<int> _stack;
        bool isOperator(const std::string &token) const;
        void performOperation(const std::string &operation);
        bool isNumber(const std::string &token) const;

    public:
        RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();
        int evaluate(const std::string &expression);        
};

#endif