#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &bc)
{
    this->csv_data = bc.csv_data;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &bc)
{
    if (this != &bc)
    {
        this->csv_data = bc.csv_data;
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{

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

            csv_data[key] = value;
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

            std::istringstream day_stream(day);
            getline(day_stream, day, ' ');

            flag = checkData(year, month, day, value);
            if (flag == DATE_ERROR)
                std::cout << "Error: bad input => "+ year + "-" + month + "-" + day << std::endl;
            else if (flag == NEGATIVE_ERROR)
                std::cout << "Error: not a positive number." << std::endl;
            else if (flag == LARGE_NUM_ERROR)
                std::cout << "Error: too large number." << std::endl;
            else
            {
                float res = findNearestDate(date, flag);
                if (flag == NO_DATA)
                    std::cout << "Error: data does not exist" << std::endl;
                else
                {
                    float fvalue = strtof(value.c_str(), NULL);
                    std::cout << year + "-" + month + "-" + day + "=>" + value + " = " << fvalue * res << std::endl;
                }
            }
        }
    }
    else
        throw std::runtime_error("Error: could not open file");
}

// format: "date | value" -> "Year-Month-Day" in date
// A valid value must be either a float or a positive integer, between 0 and 1000
int BitcoinExchange::checkData(std::string year, std::string month, std::string day, std::string value)
{
    char *ptr;

    // year check
    float fyear = strtof(year.c_str(), &ptr);
    if (*ptr || fyear < 1)
        return (DATE_ERROR);

    // month check
    float fmonth = strtof(month.c_str(), &ptr);
    if (*ptr || fmonth < 1 || fmonth > 12)
        return (DATE_ERROR);

    // day check
    float fday = strtof(day.c_str(), &ptr);
    if (*ptr)
        return (DATE_ERROR);
    if (fmonth == 1 || fmonth == 3 || fmonth == 5 || fmonth == 7 || fmonth == 8
    || fmonth == 10 || fmonth == 12)
    {
        if (fday < 1 || fday > 31)
            return (DATE_ERROR);
    }
    else if (fmonth == 4 || fmonth == 6 || fmonth == 9 || fmonth == 11)
    {
        if (fday < 1 || fday > 30)
            return (DATE_ERROR);
    }
    else if (fmonth == 2)
    {
        int iyear = static_cast<int>(fyear);
        if (iyear % 4 == 0 && !(iyear % 100 == 0 && iyear % 400 != 0))  // 윤년
        {
            if (fday < 1 || fday > 29)
                return (DATE_ERROR);
        }
        else
        {
            if (fday < 1 || fday > 28)
                return (DATE_ERROR);
        }
    }

    // value check
    float fvalue = strtof(value.c_str(), &ptr);
    if (*ptr)
        return (DATE_ERROR);
    if (fvalue <= 0)
        return (NEGATIVE_ERROR);
    else if (fvalue >= 1000)
        return (LARGE_NUM_ERROR);
    
    return (NOT_ERROR);
}

// csv파일에서 가장 가까운 날짜 찾기
float BitcoinExchange::findNearestDate(std::string date, int &flag)
{
    float res;
    std::string value;
    std::map<std::string, std::string>::iterator it;

    it = csv_data.lower_bound(date);

    if (it->first == date)
        res = strtod(it->second.c_str(), NULL);
    else
    {
        if (it->first == "2009-01-02")
            flag = NO_DATA;
        it--;
        res = strtod(it->second.c_str(), NULL);
    }
    return (res);
}
