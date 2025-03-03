#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) : _vec(other._vec), _lst(other._lst) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _vec = other._vec;
        _lst = other._lst;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::isValidNumber(const char *str)
{
    if (!str || str[0] == '\0')
        return false;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }

    char *ptr;
    long num = strtol(str, &ptr, 10);

    if (*ptr != '\0' || num <= 0 || num > INT_MAX)
        return false;

    return true;
}

bool PmergeMe::parseInput(int argc, char **argv)
{
    if (argc < 2)
        return false;

    for (int i = 1; i < argc; i++)
    {
        if (!isValidNumber(argv[i]))
            return (false);

        int num = atoi(argv[i]);
        _vec.push_back(num);
        _lst.push_back(num);
    }

    return true;
}

void PmergeMe::displaySequence(const std::vector<int>& seq, const std::string& label)
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

void PmergeMe::sortVector()
{
    if (_vec.size() <= 1)
        return;
    
    // Step 1
    bool hasStraggler = false;
    int straggler = 0;

    if (_vec.size() % 2 != 0)
    {
        hasStraggler = true;
        straggler = _vec.back();
        _vec.pop_back();
    }

    // Step 2
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < _vec.size(); i += 2)
    {
        int first = _vec[i];
        int second =_vec[i + 1];

        if (first > second)
            pairs.push_back(std::make_pair(first, second));
        else
            pairs.push_back(std::make_pair(second, first));
    }

    // step 3
    std::vector<int> mainChain;
    for (size_t i = 0; i < pairs.size(); i++) {
        mainChain.push_back(pairs[i].first);
    }

    // 


}

void PmergeMe::sort()
{
    std::vector<int> original = _vec;

    // sort vector
    clock_t vecStart = clock();
    // mergeInsertSortVector();
    clock_t vecEnd = clock();
    double vecTime = static_cast<double>(vecEnd - vecStart) / CLOCKS_PER_SEC * 1000000;

    // sort list
    clock_t lstStart = clock();
    // mergeInsertSortList();
    clock_t lstEnd = clock();
    double lstTime = static_cast<double>(lstEnd - lstStart) / CLOCKS_PER_SEC * 1000000;

    displaySequence(original, "Before");
    displaySequence(_vec, "After");

    std::cout << "Time to process a range of " << _vec.size()
            << " elements with std::vector : " << std::fixed << std::setprecision(5)
            << vecTime << " us" << std::endl;

    std::cout << "Time to process a range of " << _lst.size()
            << " elements with std::list : " << std::fixed << std::setprecision(5)
            << lstTime << " us" << std::endl;
}
