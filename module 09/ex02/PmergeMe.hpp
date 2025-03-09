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
    std::vector<int> getJacob(size_t size);
    std::vector<int> getInsertPos(std::vector<int> &jacobSeq, size_t size);

    void sortVector();
    void sortDeque();

    template<typename T>
    void printSeq(const T &seq, const std::string &label)
    {
        std::cout << label << ": ";
        for (size_t i = 0; i < seq.size(); i++)
        {
            if (i > 0)
                std::cout << " ";
            std::cout << seq[i];
        }
        std::cout << std::endl;
    }

public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    bool parseArgs(int argc, char **argv);
    void sort();
};

#endif