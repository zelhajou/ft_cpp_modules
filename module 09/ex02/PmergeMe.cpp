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

std::string PmergeMe::containerToStr(const std::vector<int> &container)
{
    std::stringstream ss;

    for (size_t i = 0; i < container.size(); i++)
    {
        if (i > 0)
            ss << " ";
        ss << container[i];
    }
    
    return ss.str();
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

    std::cout << "Before: " << containerToStr(original) << std::endl;
    std::cout << "After: " << containerToStr(_vec) << std::endl;

    (void)vecTime;
    (void)lstTime;
}
