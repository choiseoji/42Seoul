#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# include <iomanip>
# define CHAR 0
# define INT 1
# define FLOAT 2
# define DOUBLE 3

class ScalarConverter {

public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &sc);
    ScalarConverter& operator=(const ScalarConverter &sc);
    ~ScalarConverter();

    static void convert(std::string num);
};

#endif