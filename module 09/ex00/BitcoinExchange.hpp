#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

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
        bool isValidDate(const std::string &date) const;
        bool isValidValue(const float value) const;

};

#endif