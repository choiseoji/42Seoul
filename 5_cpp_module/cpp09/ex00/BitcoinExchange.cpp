#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}

// BitcoinExchange::BitcoinExchange(const BitcoinExchange &bc)
// {

// }

// BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &bc)
// {

// }

BitcoinExchange::~BitcoinExchange()
{

}

// data.csv 파일을 파싱해서 날짜 부분과 데이터 부분을 각각 key, value로 해서 map에 저장해둔다.
void BitcoinExchange::parsingCSV(void)
{
    std::string     line;
    std::ifstream   file("data.csv");

    if (file.is_open())
    {
        while (file)
        {
            getline(file, line);

            std::istringstream line_stream(line);
            std::string key;
            std::string value;

            getline(line_stream, key, ',');
            getline(line_stream, value);
        }
    }
    else
        throw std::runtime_error("Error: could not open csv file");
}

void BitcoinExchange::parsingInFile(std::string file_name)
{
    int             flag;
    std::string     data;
    std::ifstream   file(file_name);

    if (file.is_open())
    {
        while (file)
        {
            getline(file, data);

            std::string year;
            std::string month;
            std::string day;
            std::string value;

            std::istringstream data_stream(data);
            getline(data_stream, year, '-');
            getline(data_stream, month, '-');
            getline(data_stream, day, '|');
            getline(data_stream, value);

            float fyear = strtof(year.c_str(), NULL);
            float fmonth = strtof(month.c_str(), NULL);
            float fday = strtof(day.c_str(), NULL);
            float fvalue = strtof(value.c_str(), NULL);

            flag = checkData(fyear, fmonth, fday, fvalue);
            if (flag == DATE_ERROR)
                std::cout << "Error: bad input => "+ year + "-" + month + "-" + day << std::endl;
            else if (flag == NEGATIVE_ERROR)
                std::cout << "Error: not a positive number." << std::endl;
            else if (flag == LARGE_NUM_ERROR)
                std::cout << "Error: too large a number." << std::endl;
            else
            {
                std::cout << year + "-" + month + "-" + day + "=>" + value + " = ";
                // mulData();
                std::cout << std::endl;
            }
        }
    }
    else
        throw std::runtime_error("Error: could not open file");
}

// format: "date | value" -> "Year-Month-Day" in date
// A valid value must be either a float or a positive integer, between 0 and 1000
int BitcoinExchange::checkData(float fyear, float fmonth, float fday, float fvalue)
{
    // year check
    if (fyear < 0)
        return (DATE_ERROR);

    // month check
    if (fmonth < 1 || fmonth > 12)
        return (DATE_ERROR);

    // day check
    if (fmonth == 1 || fmonth == 3 || fmonth == 5 || fmonth == 7 || fmonth == 8
    || fmonth == 10 || fmonth == 12)
    {
        if (fday < 0 || fday > 31)
            return (DATE_ERROR);
    }
    else if (fmonth == 4 || fmonth == 6 || fmonth == 9 || fmonth == 11)
    {
        if (fday < 0 || fday > 30)
            return (DATE_ERROR);
    }
    else if (fmonth == 2)
    {
        if (fday < 0 || fday > 28)
            return (DATE_ERROR);
    }

    // value check
    if (fvalue < 0)
        return (NEGATIVE_ERROR);
    else if (fvalue > 1000)
        return (LARGE_NUM_ERROR);
    
    return (NOT_ERROR);
}
