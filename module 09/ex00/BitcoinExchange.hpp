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

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    void loadDataBase(const std::string &filename);
    std::string trim(const std::string &str) const;
    std::string intToString(int num) const;
    bool isValidDate(const std::string &date) const;
    bool isValidValue(const float value) const;
    void processInputFile(const std::string &filename) const;
    void displayDataBase() const;
    float getExchangeRate(const std::string &date) const;
};

#endif