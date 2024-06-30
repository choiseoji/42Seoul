#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    // .csv파일 내용 파싱
    BitcoinExchange bc;
    std::string file_name;

    try
    {
        if (ac != 2)
            throw std::runtime_error("Error: could not open file.");
        file_name = av[1];
        bc.parsingCSV();
        bc.parsingInFile(file_name);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << "\n";
    }
    return (0);
}