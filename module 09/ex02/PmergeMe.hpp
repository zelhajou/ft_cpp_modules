#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>

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
    std::deque<int> _deq;

    bool isValidNumber(const char *str);
    void printSeq(const std::vector<int> &seq, const std::string &label);
    std::vector<int> getJacob(int n);
    std::vector<int> getInsertPos(std::vector<int> &jacobSeq, size_t pairsSize);

    void sortVector();
    void sortDeque();

public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    bool parseArgs(int argc, char **argv);
    void sort();
};

#endif