#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>

#include <climits>
#include <iomanip>

class PmergeMe
{

private:
    std::vector<int> _vec;
    std::list<int> _lst;

    bool isValidNumber(const char *str);
    void displaySequence(const std::vector<int>& seq, const std::string& label);

    void sortVector();
    void sortList();

public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    bool parseInput(int argc, char **argv);
    void sort();
};

#endif