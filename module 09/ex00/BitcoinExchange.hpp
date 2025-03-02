#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

class BitcoinExchange
{
private:
    std::map<std::string, float> _database;
    std::string trim(const std::string &str) const;
    std::string intToString(int num) const;
    bool isValidDate(const std::string &date) const;
    bool isValidValue(const float value) const;
    float getExchangeRate(const std::string &date) const;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    void loadDataBase(const std::string &filename);
    void processInputFile(const std::string &filename) const;
};

#endif