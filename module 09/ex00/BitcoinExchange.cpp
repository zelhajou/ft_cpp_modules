#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _database(other._database)
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        _database = other._database;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
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

    int year = std::stoi(date.substr(0, 4));
    int month = std::stoi(date.substr(5, 2));
    int day = std::stoi(date.substr(8, 2));

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
        throw std::runtime_error("Error at line " + std::to_string(lineCount) + ": invalid CSV header");
    if (std::getline(ss, line))
        throw std::runtime_error("Error at line " + std::to_string(lineCount) + ": More than 2 fields");
        
    dateHeaderCol = trim(dateHeaderCol);
    valueHeaderCol = trim(valueHeaderCol);

    if (dateHeaderCol != "date" || valueHeaderCol != "exchange_rate")
        throw std::runtime_error("Error at line " + std::to_string(lineCount) + ": invalid CSV header");
    
    while (std::getline(file, line))
    {   
        lineCount++;
        
        if (line.empty())
            continue;

        std::stringstream ss(line);
        std::string date;
        std::string valueStr;

        if (!std::getline(ss, date, ',') || !std::getline(ss, valueStr, ','))
            throw std::runtime_error("Error at line " + std::to_string(lineCount) + ": invalid CSV line");
        
        if (std::getline(ss, line))
            throw std::runtime_error("Error at line " + std::to_string(lineCount) + ": more than 2 fields");
        
        date = trim(date);
        valueStr = trim(valueStr);

        if (date.empty() || valueStr.empty())
        {
            std::cerr << "Error at line " << lineCount << ": empty field" << std::endl;
            continue;
        }

        if (!isValidDate(date))
            throw std::runtime_error("Error at line " + std::to_string(lineCount) + ": invalid date => " + date);
       
        try
        {
            size_t processed;
            float value = std::stof(valueStr, &processed);
            if (processed != valueStr.length())
                throw std::runtime_error("Error at line " + std::to_string(lineCount) + ": invalid value => " + valueStr);
            if (value < 0)
                throw std::runtime_error("Error at line " + std::to_string(lineCount) + ": negative value => " + valueStr);
            std::cout << value << std::endl;
            _database[date] = value;
        }
        catch (const std::invalid_argument &e)
        {
            throw std::runtime_error("Error at line " + std::to_string(lineCount) + ": invalid value => " + valueStr);
        }
    }
    if (_database.empty())
        throw std::runtime_error("Error: empty database");
}

void BitcoinExchange::processInputFile(const std::string &filename) const
{
    std::ifstream file
}