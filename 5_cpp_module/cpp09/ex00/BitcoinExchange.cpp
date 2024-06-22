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

bool compare(const std::pair<std::string, std::string>& a, const std::pair<std::string, std::string>& b)
{
    return a.first <= b.first;
}

bool compareL(const std::pair<std::string, std::string>& a, std::string b)
{
    return a.first <= b;
}

// data.csv 파일을 파싱해서 날짜 부분과 데이터 부분을 각각 key, value로 해서 map에 저장해둔다.
void BitcoinExchange::parsingCSV(void)
{
    std::string     data;
    std::ifstream   file("data.csv");

    if (file.is_open())
    {
        while (file)
        {
            getline(file, data);

            std::istringstream data_stream(data);
            std::string key;
            std::string value;

            getline(data_stream, key, ',');
            getline(data_stream, value);

            csv_data.push_back(std::make_pair(key, value));
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
        while (getline(file, data))
        {
            std::string year;
            std::string month;
            std::string day;
            std::string value;
            std::string date;

            std::istringstream date_stream(data);
            getline(date_stream, date, ' ');

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
                std::cout << fvalue * findNearestDate(date) << std::endl;
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

// csv파일에서 가장 가까운 날짜 찾기
float BitcoinExchange::findNearestDate(std::string date)
{
    int idx;
    float fvalue;
    std::vector<std::pair<std::string, std::string> >::iterator it;
    it = std::lower_bound(csv_data.begin(), csv_data.end(), date, compareL);
    
    idx = it - csv_data.begin();

    if (date != csv_data[idx].first)
        idx--;
    fvalue = strtof(csv_data[idx].second.c_str(), NULL);

    return (fvalue);
}
