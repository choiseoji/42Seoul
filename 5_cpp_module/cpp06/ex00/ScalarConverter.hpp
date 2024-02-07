#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# include <string>
# include <iomanip>
# include <float.h>
# include <errno.h>

# define CHAR 0
# define INT 1
# define FLOAT 2
# define DOUBLE 3

class ScalarConverter
{
public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &s);
	ScalarConverter& operator=(const ScalarConverter &s);
	~ScalarConverter();

	static void convert(std::string num);
};

int isChar(std::string n);

void toChar(std::string n);
void toInt(std::string n);
void toFloat(std::string n);
void toDouble(std::string n);

#endif
