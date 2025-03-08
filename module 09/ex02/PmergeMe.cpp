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

    if (*ptr != '\0' || num <= 0 || num > INT_MAX)
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

void PmergeMe::printSeq(const std::vector<int> &seq, const std::string &label)
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

std::vector<int> PmergeMe::getJacob(int n)
{
    std::vector<int> jacobsthal;

    jacobsthal.push_back(0);
    if (n > 0)
        jacobsthal.push_back(1);

    for (int i = 2; i <= n; i++)
    {
        int next = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
        jacobsthal.push_back(next);
    }

    return jacobsthal;
}

std::vector<int> PmergeMe::getInsertPos(std::vector<int> &jacobSeq, size_t pairsSize)
{
    std::vector<int> insertionOrder;
    std::vector<bool> inserted(pairsSize, false);
    inserted[0] = true;

    for (size_t i = 1; i < jacobSeq.size(); i++)
    {
        int idx = jacobSeq[i];
        if (idx < (int)pairsSize && !inserted[idx])
        {
            insertionOrder.push_back(idx);
            inserted[idx] = true;
        }

        for (int j = idx - 1; j > jacobSeq[i - 1]; j--)
        {
            if (j >= 0 && j < (int)pairsSize && !inserted[j])
            {
                insertionOrder.push_back(j);
                inserted[j] = true;
            }
        }
    }

    for (size_t i = 1; i < pairsSize; i++)
    {
        if (!inserted[i])
            insertionOrder.push_back(i);
    }

    return insertionOrder;
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
        pairs.push_back(std::make_pair(first, second));
    }

    for (size_t i = 0; i < pairs.size(); i++)
    {
        if (pairs[i].first < pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);
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
        _vec.clear();
    }

    std::vector<int> result;
    if (!mainChain.empty())
        result.push_back(mainChain[0]);

    if (!pairs.empty())
        result.insert(result.begin(), pairs[0].second);

    if (pairs.size() > 1)
    {
        int jacobsthalSize = 3;
        while (getJacob(jacobsthalSize).back() < (int)pairs.size())
            jacobsthalSize++;

        std::vector<int> jacobSeq = getJacob(jacobsthalSize);
        std::vector<int> insertionOrder = getInsertPos(jacobSeq, pairs.size());

        for (size_t i = 0; i < insertionOrder.size(); i++)
        {
            int idx = insertionOrder[i];
            std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), mainChain[idx]);
            result.insert(pos, mainChain[idx]);

            pos = std::lower_bound(result.begin(), result.end(), pairs[idx].second);
            result.insert(pos, pairs[idx].second);
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
        pairs.push_back(std::make_pair(first, second));
    }

    for (size_t i = 0; i < pairs.size(); i++)
    {
        if (pairs[i].first < pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);
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
        _deq.clear();
    }

    std::deque<int> result;
    if (!mainChain.empty())
        result.push_back(mainChain.front());

    if (!pairs.empty())
        result.push_front(pairs[0].second);

    if (pairs.size() > 1)
    {
        int jacobsthalSize = 3;
        while (getJacob(jacobsthalSize).back() < (int)pairs.size())
            jacobsthalSize++;

        std::vector<int> jacobSeq = getJacob(jacobsthalSize);
        std::vector<int> insertionOrder = getInsertPos(jacobSeq, pairs.size());

        for (size_t i = 0; i < insertionOrder.size(); i++)
        {
            int idx = insertionOrder[i];

            std::deque<int>::iterator pos = std::lower_bound(result.begin(), result.end(), mainChain[idx]);
            result.insert(pos, mainChain[idx]);
            
            pos = std::lower_bound(result.begin(), result.end(), pairs[idx].second);
            result.insert(pos, pairs[idx].second);
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

    bool isSorted = true;
    for (size_t i = 1; i < _vec.size(); i++) {
        if (_vec[i] < _vec[i-1]) {
            std::cout << _vec[i] << std::endl;
            std::cout << _vec[i - 1] << std::endl;
            isSorted = false;
            break;
        }
    }

    printSeq(original, "Before");
    printSeq(_vec, "After");

    std::cout << "Time to process a range of " << _vec.size()
              << " elements with std::vector : " << std::fixed << std::setprecision(5)
              << vecTime << " us" << std::endl;

    std::cout << "Time to process a range of " << _deq.size()
              << " elements with std::deque : " << std::fixed << std::setprecision(5)
              << deqTime << " us" << std::endl;
}