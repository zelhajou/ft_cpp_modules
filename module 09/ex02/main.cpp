#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    PmergeMe sorter;

    if (!sorter.parseInput(argc, argv))
    {
        std::cout << "Error" << std::endl;
        return 1;
    }

    sorter.sort();
}