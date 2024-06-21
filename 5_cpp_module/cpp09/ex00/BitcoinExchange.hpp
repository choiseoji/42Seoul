#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <map>
# include <vector>
# include <algorithm>

enum Error{
    DATE_ERROR,
    NEGATIVE_ERROR,
    LARGE_NUM_ERROR,
    NOT_ERROR
};

class BitcoinExchange
{
private:
    std::vector<std::pair<int, int>> v[13];   // v[month] = {day, value}
    std::map<float, std::vector<float>> csv_data;  // year와 매핑되어 있는 month 를 담고있는 벡터

public:
    BitcoinExchange();
    // BitcoinExchange(const BitcoinExchange &bc);
    // BitcoinExchange& operator=(const BitcoinExchange &bc);
    ~BitcoinExchange();

    void parsingCSV();
    void parsingInFile(std::string file_name);
    int  checkData(float fyear, float fmonth, float fday, float fvalue);
    // float findNearestDate(float fyear, float fmonth, float fday);
};

#endif