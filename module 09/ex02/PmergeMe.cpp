#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) : _vec(other._vec), _deq(other._deq) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _vec = other._vec;
        _deq = other._deq;
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

    if (*ptr != '\0' || num < 0 || num > INT_MAX)
        return false;

    return true;
}

bool PmergeMe::parseArgs(int argc, char **argv)
{
    if (argc < 2)
        return false;

    for (int i = 1; i < argc; i++)
    {
        if (!isValidNumber(argv[i]))
            return (false);

        int num = atoi(argv[i]);
        _vec.push_back(num);
        _deq.push_back(num);
    }

    return true;
}

std::vector<int> PmergeMe::getJacob(size_t size)
{
    std::vector<int> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    
    while (jacobsthal.back() < static_cast<int>(size))
    {
        int lastNum = jacobsthal.back();
        int secondLastNum = jacobsthal[jacobsthal.size() - 2];
        
        int next = lastNum + 2 * secondLastNum;
        jacobsthal.push_back(next);
    }
    
    return jacobsthal;
}


std::vector<int> PmergeMe::getInsertPos(size_t size)
{
    std::vector<int> jacobSeq = getJacob(size);
    std::vector<int> order;
    std::vector<bool> used(size, false);
    used[0] = true;

    for (size_t i = 1; i < jacobSeq.size() && jacobSeq[i] < static_cast<int>(size); i++)
    {
        if (!used[jacobSeq[i]]) {
            order.push_back(jacobSeq[i]);
            used[jacobSeq[i]] = true;
        }
        
        for (int j = jacobSeq[i] - 1; j > jacobSeq[i-1]; j--) {
            if (j < (int)size && !used[j]) {
                order.push_back(j);
                used[j] = true;
            }
        }
    }

    for (size_t i = 1; i < size; i++) {
        if (!used[i]) {
            order.push_back(i);
        }
    }

    return order;
}

void PmergeMe::sortVector()
{
    if (_vec.size() <= 1)
        return;

    bool hasStraggler = false;
    int straggler = 0;

    if (_vec.size() % 2 != 0)
    {
        hasStraggler = true;
        straggler = _vec.back();
        _vec.pop_back();
    }

    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < _vec.size(); i += 2)
    {
        int first = _vec[i];
        int second = _vec[i + 1];
        if (first < second)
            std::swap(first, second);
        pairs.push_back(std::make_pair(first, second));
    }

    std::vector<int> mainChain;
    for (size_t i = 0; i < pairs.size(); i++)
    {
        mainChain.push_back(pairs[i].first);
    }

    if (mainChain.size() > 1)
    {
        _vec = mainChain;
        sortVector();
        mainChain = _vec;
    }

    std::vector<int> result = mainChain;

    std::vector<int> pendChain;
    for (size_t i = 0; i < pairs.size(); i++)
    {
        pendChain.push_back(pairs[i].second);
    }

    if (!pendChain.empty())
    {
        std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), pendChain[0]);
        result.insert(pos, pendChain[0]);
    }

    if (pendChain.size() > 1)
    {
        std::vector<int> insertionOrder = getInsertPos(pendChain.size());

        for (size_t i = 0; i < insertionOrder.size(); i++)
        {
            int idx = insertionOrder[i];
            if (idx > 0 && idx < (int)pendChain.size())
            {
                std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(),  pendChain[idx]);
                result.insert(pos,  pendChain[idx]);
            }
        }
    }

    if (hasStraggler)
    {
        std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), straggler);
        result.insert(pos, straggler);
    }

    _vec = result;
}

void PmergeMe::sortDeque()
{
    if (_deq.size() <= 1)
        return;

    bool hasStraggler = false;
    int straggler = 0;

    if (_deq.size() % 2 != 0)
    {
        hasStraggler = true;
        straggler = _deq.back();
        _deq.pop_back();
    }

    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < _deq.size(); i += 2)
    {
        int first = _deq[i];
        int second = _deq[i + 1];
        if (first < second)
            std::swap(first, second);
        pairs.push_back(std::make_pair(first, second));
    }

    std::deque<int> mainChain;
    for (size_t i = 0; i < pairs.size(); i++)
    {
        mainChain.push_back(pairs[i].first);
    }

    if (mainChain.size() > 1)
    {
        _deq = mainChain;
        sortDeque();
        mainChain = _deq;
    }

    std::deque<int> result = mainChain;

    std::deque<int> pendChain;
    for (size_t i = 0; i < pairs.size(); i++)
    {
        pendChain.push_back(pairs[i].second);
    }

    if (!pendChain.empty())
    {
        std::deque<int>::iterator pos = std::lower_bound(result.begin(), result.end(), pendChain[0]);
        result.insert(pos, pendChain[0]);
    }

    if (pendChain.size() > 1)
    {
        std::vector<int> insertionOrder = getInsertPos(pendChain.size());

        for (size_t i = 0; i < insertionOrder.size(); i++)
        {
            int idx = insertionOrder[i];
            if (idx > 0 && idx < (int)pendChain.size())
            {
                std::deque<int>::iterator pos = std::lower_bound(result.begin(), result.end(), pendChain[idx]);
                result.insert(pos, pendChain[idx]);
            }
        }
    }

    if (hasStraggler)
    {
        std::deque<int>::iterator pos = std::lower_bound(result.begin(), result.end(), straggler);
        result.insert(pos, straggler);
    }

    _deq = result;
}

void PmergeMe::sort()
{
    std::vector<int> original = _vec;

    clock_t vecStart = clock();
    sortVector();
    clock_t vecEnd = clock();
    double vecTime = static_cast<double>(vecEnd - vecStart) / CLOCKS_PER_SEC * 1000000;

    clock_t deqStart = clock();
    sortDeque();
    clock_t deqEnd = clock();
    double deqTime = static_cast<double>(deqEnd - deqStart) / CLOCKS_PER_SEC * 1000000;

    // for (size_t i = 1; i < _vec.size(); i++)
    // {
    //     if (_vec[i] < _vec[i - 1])
    //     {
    //         std::cerr << "Error: std::vector is no sorted" << std::endl;
    //         return;
    //     }
    // }

    printSeq(original, "Before");
    printSeq(_vec, "After");

    std::cout << "Time to process a range of " << _vec.size()
              << " elements with std::vector : " << std::fixed << std::setprecision(5)
              << vecTime << " us" << std::endl;

    std::cout << "Time to process a range of " << _deq.size()
              << " elements with std::deque : " << std::fixed << std::setprecision(5)
              << deqTime << " us" << std::endl;
}
