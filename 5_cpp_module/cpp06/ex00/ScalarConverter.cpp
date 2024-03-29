#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) { }

ScalarConverter::ScalarConverter(const ScalarConverter &sc) { (void)sc; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &sc)
{
    (void)sc;
	return (*this);
}

ScalarConverter::~ScalarConverter(void) { }

void printImpossible(void)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

int is_print(char num)
{
    int n;

    n = static_cast<int>(num);
    if (n >= 32 && n <= 127)
        return (true);
    else
        return (false);
}

int is_nan(double num)
{
    if (num != num)
        return (true);
    else
        return (false);
}

int is_inf(double num)
{
    if (num != 0 && (num * 2 == num))
        return (true);
    else
        return (false);
}

int getType(std::string n)
{
    int i;
	bool dot;

	i = 0;
	dot = false;
	while (n[i])
	{
		if (n[i] == '.')
			dot = true;
		i++;
	}

	if (n == "nanf" || n == "inff" || n == "+inff" || n == "-inff" || (dot == true && n[i - 1] == 'f'))
		return (FLOAT);
	else if (n == "nan" || n == "inf" ||  n == "+inf" || n == "-inf" || dot == true)
		return (DOUBLE);
	else if (i == 1 && std::isalpha(n[i - 1]))
		return (CHAR);
	else
		return (INT);
}

void isChar(std::string n)
{
    if (!std::isalpha(n[0]))
        printImpossible();
    else
    {
        char    char_num;
        double  num;
        char    *ptr;

        num = strtod(n.c_str(), &ptr);
        char_num = static_cast<char>(n[0]);
        if (!is_print(char_num))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: " << char_num << std::endl;

        if (num > 2147483647 || num < -2147483648 || is_nan(num) || is_inf(num))
            std::cout << "int: impossible" << std::endl;
        else
		    std::cout << "int: " << static_cast<int>(char_num) << std::endl;

        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(char_num) << 'f' << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(char_num) << std::endl;
    }
}

void isInt(std::string n)
{
    double  num;
    char	*ptr;

    num = strtod(n.c_str(), &ptr);
    if (*ptr || num > 2147483647 || num < -2147483648
		|| is_nan(num) || is_inf(num))
        printImpossible();
	else
    {
        int int_num;

        int_num = static_cast<int>(num);
        if (is_nan(num) || is_inf(num) || num > CHAR_MAX || num < CHAR_MIN)
		    std::cout << "char: impossible" << std::endl;
        else if (!is_print(static_cast<char>(int_num)))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: " << static_cast<char>(int_num) << std::endl;
		std::cout << "int: " << int_num << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(int_num) << 'f' << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(int_num) << std::endl;
    }
}

void isFloat(std::string n)
{
    char    *ptr;
    double  num;

    errno = 0;
    n = n.substr(0, n.size() - 1);
    num = strtof(n.c_str(), &ptr);
    if (*ptr || (errno == ERANGE))
        printImpossible();
    else
    {
        float float_num;

        float_num = static_cast<float>(num);
        if (is_nan(num) || is_inf(num) || num > CHAR_MAX || num < CHAR_MIN)
		    std::cout << "char: impossible" << std::endl;
        else if (!is_print(static_cast<char>(float_num)))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: " << static_cast<char>(float_num) << std::endl;

        if (float_num > 2147483647 || float_num < -2147483648 || is_nan(float_num) || is_inf(float_num))
            std::cout << "int: impossible" << std::endl;
        else
		    std::cout << "int: " << static_cast<int>(float_num) << std::endl;

        std::cout << "float: " << std::fixed << std::setprecision(1) << float_num << 'f' << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(float_num) << std::endl;
    }
}

void isDouble(std::string n)
{
    char    *ptr;
    double  double_num;

    errno = 0;
    double_num = strtod(n.c_str(), &ptr);
    if (*ptr || (errno == ERANGE))
        printImpossible();
    else
    {
        if (is_nan(double_num) || is_inf(double_num) || double_num > CHAR_MAX || double_num < CHAR_MIN)
		    std::cout << "char: impossible" << std::endl;
        else if (!is_print(static_cast<char>(double_num)))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: " << static_cast<char>(double_num) << std::endl;

        if (double_num > 2147483647 || double_num < -2147483648 || is_nan(double_num) || is_inf(double_num))
            std::cout << "int: impossible" << std::endl;
        else
		    std::cout << "int: " << static_cast<int>(double_num) << std::endl;

        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(double_num) << 'f' << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << double_num << std::endl;
    }
}

void ScalarConverter::convert(std::string num)
{
    int type;

    type = getType(num);
    switch (type)
    {
        case CHAR:
            isChar(num);
            break ;

        case INT:
            isInt(num);
            break ;

        case FLOAT:
            isFloat(num);
            break ;

        case DOUBLE:
            isDouble(num);
            break ;
    }
}
