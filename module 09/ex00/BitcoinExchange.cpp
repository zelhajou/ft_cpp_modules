#include "BitcoinExchange.hpp"
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _database(other._database) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        _database = other._database;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

std::string BitcoinExchange::intToString(int num) const
{
    std::stringstream ss;
    ss << num;
    return ss.str();
}

std::string BitcoinExchange::trim(const std::string &str) const
{
    size_t first = str.find_first_not_of(" \t");
    if (first == std::string::npos)
        return "";
    size_t last = str.find_last_not_of(" \t");
    return str.substr(first, last - first + 1);
}

bool BitcoinExchange::isValidValue(const float value) const
{
    if (value >= 0 && value <= 1000)
        return true;
    return false;
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());

    if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        daysInMonth[2] = 29;

    if (day > daysInMonth[month])
        return false;

    return true;
}

void BitcoinExchange::loadDataBase(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    int lineCount = 1;

    if (!file.is_open())
        throw std::runtime_error("Error: Could not open file.");

    std::string line;

    while (line.empty())
    {
        if (!std::getline(file, line))
            throw std::runtime_error("Error: empty database file.");
    }

    std::stringstream ss(line);
    std::string dateHeaderCol;
    std::string valueHeaderCol;

    if (!std::getline(ss, dateHeaderCol, ',') || !std::getline(ss, valueHeaderCol, ','))
        throw std::runtime_error("Error at line " + intToString(lineCount) + ": invalid CSV header");
    if (std::getline(ss, line))
        throw std::runtime_error("Error at line " + intToString(lineCount) + ": More than 2 fields");

    dateHeaderCol = trim(dateHeaderCol);
    valueHeaderCol = trim(valueHeaderCol);

    if (dateHeaderCol != "date" || valueHeaderCol != "exchange_rate")
        throw std::runtime_error("Error at line " + intToString(lineCount) + ": invalid CSV header");

    while (std::getline(file, line))
    {
        lineCount++;

        if (line.empty())
            continue;

        std::stringstream ss(line);
        std::string date;
        std::string valueStr;

        if (!std::getline(ss, date, ',') || !std::getline(ss, valueStr, ','))
            throw std::runtime_error("Error at line " + intToString(lineCount) + ": invalid CSV line");

        if (std::getline(ss, line))
            throw std::runtime_error("Error at line " + intToString(lineCount) + ": more than 2 fields");

        date = trim(date);
        valueStr = trim(valueStr);

        if (date.empty() || valueStr.empty())
        {
            std::cerr << "Error at line " << lineCount << ": empty field" << std::endl;
            continue;
        }

        if (!isValidDate(date))
            throw std::runtime_error("Error at line " + intToString(lineCount) + ": invalid date => " + date);

        std::stringstream ss2(valueStr);
        float value;
        ss2 >> value;

        if (!ss2.eof())
            throw std::runtime_error("Error at line " + intToString(lineCount) + ": invalid value => " + valueStr);
        
      
        if (value < 0)
            throw std::runtime_error("Error at line " + intToString(lineCount) + ": negative value => " + valueStr);
        
        _database[date] = value;
        
    }
    if (_database.empty())
        throw std::runtime_error("Error: empty database");
}

float BitcoinExchange::getExchangeRate(const std::string &date) const
{
    if (_database.empty())
        throw std::runtime_error("Error: empty database");

    std::map<std::string, float>::const_iterator it = _database.upper_bound(date);
    if (it == _database.begin())
        throw std::runtime_error("Error: no exchange rate found for this date");
    --it;
    return it->second;
}

void BitcoinExchange::processInputFile(const std::string &filename) const
{
    std::ifstream file(filename.c_str());

    if (!file.is_open())
        throw std::runtime_error("Error: Could not open file.");

    std::string line;
    if (!std::getline(file, line))
        throw std::runtime_error("Error: empty input file");

    if (line != "date | value")
        throw std::runtime_error("Error: invalid input file header");

    while (std::getline(file, line))
    {
        if (line.empty())
            continue;

        size_t pipePos = line.find('|');
        if (pipePos == std::string::npos)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = trim(line.substr(0, pipePos));
        std::string valueStr = trim(line.substr(pipePos + 1));

        if (date.empty() || valueStr.empty())
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (!isValidDate(date))
        {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }

        std::stringstream ss(valueStr);
        float value;

        ss >> value;   

        if (!ss.eof())
        {
            std::cout << "Error: bad input => " << valueStr << std::endl;
            continue;
        }

        if (!isValidValue(value))
        {
            if (value < 0)
                std::cout << "Error: not a positive number." << std::endl;
            else
                std::cout << "Error: too large a number." << std::endl;
            continue;
        }

        try
        {
            float exchangeRate = getExchangeRate(date);
            std::cout << date << " => " << value << " = " << value * exchangeRate << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << "Error: bad value => " << valueStr << std::endl;
        }
    }
}
