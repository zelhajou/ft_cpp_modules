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

void PmergeMe::displaySequence(const std::vector<int> &seq, const std::string &label)
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


std::vector<int> PmergeMe::getJacobsthalSequence(int n) {
    std::vector<int> jacobsthal;
    
    jacobsthal.push_back(0);
    if (n > 0)
        jacobsthal.push_back(1);
    
    for (int i = 2; i <= n; i++) {
        int next = jacobsthal[i-1] + 2 * jacobsthal[i-2];
        jacobsthal.push_back(next);
    }
    
    return jacobsthal;
}

std::vector<int> PmergeMe::calculateInsertionOrder(std::vector<int>& jacobSeq, size_t pairsSize)
{
    std::vector<int> insertionOrder;
    std::vector<bool> inserted(pairsSize, false);
    inserted[0] = true; // Mark first pair as already processed
    
    for (size_t i = 1; i < jacobSeq.size() && jacobSeq[i] < (int)pairsSize; i++) {
        int idx = jacobSeq[i];
        if (!inserted[idx]) {
            insertionOrder.push_back(idx);
            inserted[idx] = true;
        }
        
        // Fill in between Jacobsthal numbers in descending order
        for (int j = idx - 1; j > jacobSeq[i-1]; j--) {
            if (j >= 0 && j < (int)pairsSize && !inserted[j]) {
                insertionOrder.push_back(j);
                inserted[j] = true;
            }
        }
    }
    
    // Add any remaining indices
    for (size_t i = 1; i < pairsSize; i++) {
        if (!inserted[i])
            insertionOrder.push_back(i);
    }
    
    return insertionOrder;
}


void PmergeMe::sortVector() {
    if (_vec.size() <= 1)
        return;
    
    // Step 1: Handle odd-sized array
    bool hasStraggler = false;
    int straggler = 0;
    
    if (_vec.size() % 2 != 0) {
        hasStraggler = true;
        straggler = _vec.back();
        _vec.pop_back();
    }
    
    // Step 2: Form pairs
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < _vec.size(); i += 2) {
        int first = _vec[i];
        int second = _vec[i + 1];
        pairs.push_back(std::make_pair(first, second));
    }
    
    // Step 3: Sort elements within pairs (larger element first)
    for (size_t i = 0; i < pairs.size(); i++) {
        if (pairs[i].first < pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);
    }
    
    // Step 4: Extract main chain (larger elements)
    std::vector<int> mainChain;
    for (size_t i = 0; i < pairs.size(); i++) {
        mainChain.push_back(pairs[i].first);
    }
    
    // Step 5: Recursively sort main chain
    if (mainChain.size() > 1) {
        _vec = mainChain;
        sortVector();
        mainChain = _vec;
        _vec.clear();
    }
    
    // Step 6: Initialize result with the first element from main chain
    std::vector<int> result;
    if (!mainChain.empty())
        result.push_back(mainChain[0]);
    
    // Step 7: Insert first smaller element
    if (!pairs.empty())
        result.insert(result.begin(), pairs[0].second);
    
    // Step 8: For remaining elements, use Jacobsthal sequence
    if (pairs.size() > 1) {
        // Generate Jacobsthal sequence
        int jacobsthalSize = 3;
        while (getJacobsthalSequence(jacobsthalSize).back() < (int)pairs.size())
            jacobsthalSize++;
        
        std::vector<int> jacobSeq = getJacobsthalSequence(jacobsthalSize);
        
        // Calculate insertion order using our new helper function
        std::vector<int> insertionOrder = calculateInsertionOrder(jacobSeq, pairs.size());

        // Insert elements according to determined order
        for (size_t i = 0; i < insertionOrder.size(); i++) {
            int idx = insertionOrder[i];
            
            // Insert main chain element if not already in result
            if (std::find(result.begin(), result.end(), mainChain[idx]) == result.end()) {
                std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), mainChain[idx]);
                result.insert(pos, mainChain[idx]);
            }
            
            // Insert smaller element
            std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), pairs[idx].second);
            result.insert(pos, pairs[idx].second);
        }
    }
    
    // Step 9: Insert straggler if exists
    if (hasStraggler) {
        std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), straggler);
        result.insert(pos, straggler);
    }
    
    // Step 10: Set final result
    _vec = result;
}

void PmergeMe::sort()
{
    std::vector<int> original = _vec;

    // sort vector
    clock_t vecStart = clock();
    sortVector();
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
