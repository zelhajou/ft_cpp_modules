#include "BitcoinExchange.hpp"

int main()
{

    BitcoinExchange exchange;

    try
    {
        exchange.loadDataBase("data.csv");
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}