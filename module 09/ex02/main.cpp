#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    PmergeMe sorter;

    if (!sorter.parseArgs(argc, argv))
    {
        std::cout << "Error" << std::endl;
        return 1;
    }

    sorter.sort();
}