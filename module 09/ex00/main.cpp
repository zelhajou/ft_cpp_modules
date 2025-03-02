#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./btc [input_file]" << std::endl;
        return 1;
    }
    BitcoinExchange exchange;
    try
    {
        exchange.loadDataBase("data.csv");
        exchange.processInputFile(argv[1]);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}