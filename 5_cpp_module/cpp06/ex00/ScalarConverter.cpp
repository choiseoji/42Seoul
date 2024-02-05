#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() { }

ScalarConverter::ScalarConverter(const ScalarConverter &s)
{
	(void)s;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &s)
{
	if (this != &s)
	{

	}
	return (*this);
}

ScalarConverter::~ScalarConverter() { }

///////////////////////////////////////////////////////////

int getType(std::string n)
{
	int i;
	bool dot;
	char *ptr;

	i = 0;
	dot = false;
	while (n[i])
	{
		if (n[i] == '.')
			dot = true;
		i++;
	}
	strtod(n.c_str(), &ptr);

	// if (i != 1 && *ptr && n[i - 1] != 'f')
	// 	return (ERROR);
	if (dot == true && n[i - 1] == 'f')
		return (FLOAT);
	else if (dot == true)
		return (DOUBLE);
	else if (i == 1 && std::isalpha(n[i - 1]))
		return (CHAR);
	else
		return (INT);
}

void baseChar(std::string n)
{
	char num;

	num = n[0];
	std::cout << "char: " << num << std::endl;
	std::cout << "int: " << static_cast<int>(num) << std::endl;
	std::cout << "float: "  << std::fixed << std::setprecision(1) << static_cast<float>(num) << 'f' << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(num) << std::endl;
}

// void baseInt(std::string n)
// {

// }

// void baseFloat(std::string n)
// {

// }

void baseDouble(std::string n)
{
	double num;

	num = strtod(n.c_str(), NULL);

	// char
	if (std::isnan(num) || std::isinf(num))
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<char>(num)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(num) << std::endl;

	// int
	if (num > 2147483647 || num < -2147483648
		|| std::isnan(num) || std::isinf(num))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(num) << std::endl;

	// float, double 은 범위 체크만 해주면 됨
	errno = 0;
	strtof(n.c_str(), NULL);
	if (errno == ERANGE)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: "  << std::fixed << std::setprecision(1) << static_cast<float>(num) << 'f' << std::endl;

	errno = 0;
	if (errno == ERANGE)
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(num) << std::endl;
}

void ScalarConverter::convert(std::string n)
{
	int type;

	type = getType(n);
	type = 3;   // double로 하려고 임의로 바꾸기
	switch(type)
	{
		// default:
		// 	std::cout << "invalid_input" << std::endl;
		// 	break ;
		case CHAR:
			baseChar(n);
			break ;
		// case INT:
		// 	baseInt(n);
		// 	break ;
		// case FLOAT:
		// 	baseFloat(n);
		// 	break ;
		case DOUBLE:
			baseDouble(n);
			break ;
	}
}
