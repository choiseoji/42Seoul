#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <map>
# include <algorithm>

enum Error{
    DATE_ERROR,
    NEGATIVE_ERROR,
    LARGE_NUM_ERROR,
    NO_DATA,
    NOT_ERROR
};

class BitcoinExchange
{
private:
    std::map<std::string, std::string> csv_data;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &bc);
    BitcoinExchange& operator=(const BitcoinExchange &bc);
    ~BitcoinExchange();

    void parsingCSV();
    void parsingInFile(std::string file_name);
    int  checkData(std::string year, std::string month, std::string day, std::string value);
    float findNearestDate(std::string data, int &flag);
};

#endif