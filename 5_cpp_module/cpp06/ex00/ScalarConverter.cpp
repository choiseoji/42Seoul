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

	if (n == "+inff" || n == "-inff" || (dot == true && n[i - 1] == 'f'))
		return (FLOAT);
	else if (n == "nan" || n == "+inf" || n == "-inf" || dot == true)
		return (DOUBLE);
	else if (i == 1 && std::isalpha(n[i - 1]))
		return (CHAR);
	else
		return (INT);
}

void baseChar(std::string n)
{
	if (isChar(n))
	{
		std::cout << "char: " << static_cast<char>(n[0]) << std::endl;
		std::cout << "int: " << static_cast<int>(n[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(n[0]) << std::endl;
		std::cout << "double: " << static_cast<double>(n[0]) << std::endl;
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}

void baseInt(std::string n)
{
	toChar(n);
	toInt(n);
	toFloat(n);
	toDouble(n);
}

void baseFloat(std::string n)
{
	int size;
	std::string new_n;

	size = n.length();
	new_n = n.substr(0, size - 1);

	toChar(new_n);
	toInt(new_n);
	toFloat(new_n);
	toDouble(new_n);
}

void baseDouble(std::string n)
{
	toChar(n);
	toInt(n);
	toFloat(n);
	toDouble(n);
}

//////////////////////////////////////////////////////////

int isChar(std::string n)
{
	int	i;

	i = 0;
	while (n[i])
		i++;
	
	if (i == 1 && std::isalpha(n[0]))
		return (i);
	return (0);
}

bool isFloat(std::string n)
{
	int i;
	int dot;

	i = 0;
	dot = 0;
	while (n[i])
	{
		if (n[i] == '.')
			dot = 1;
		i++;
	}
	if (dot && n[i - 1] == 'f')
		return (true);
	return (false);
}

void toChar(std::string n)
{
	double	num;
	char	*ptr;

	num = strtod(n.c_str(), &ptr);
	if (*ptr || std::isnan(num) || std::isinf(num))
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<char>(num)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(num) << std::endl;
}

void toInt(std::string n)
{
	double	num;
	char	*ptr;
	int		i;

	if (isChar(n))
	{
		std::cout << "int: " << static_cast<int>(n[0]) << std::endl;
		return ;
	}
	i = isFloat(n);
	n = n.substr(0, i - 1);

	num = strtod(n.c_str(), &ptr);
	if (*ptr || num > 2147483647 || num < -2147483648
		|| std::isnan(num) || std::isinf(num))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(num) << std::endl;
}

void toFloat(std::string n)
{
	float	num;
	char	*ptr;
	int		i;

	if (isChar(n))
	{
		std::cout << "float: "  << std::fixed << std::setprecision(1) << static_cast<float>(n[0]) << 'f' << std::endl;
		return ;
	}
	
	i = isFloat(n);
	n = n.substr(0, i - 1);

	errno = 0;
	num = strtof(n.c_str(), &ptr);
	if (*ptr || (errno == ERANGE))
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: "  << std::fixed << std::setprecision(1) << static_cast<float>(num) << 'f' << std::endl;
}

void toDouble(std::string n)
{
	double	num;
	char	*ptr;
	int		i;

	if (isChar(n))
	{
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(n[0]) << std::endl;
		return ;
	}
	i = isFloat(n);
	n = n.substr(0, i - 1);

	errno = 0;
	num = strtod(n.c_str(), &ptr);
	if (*ptr || (errno == ERANGE))
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(num) << std::endl;
}

//////////////////////////////////////////////////////////

void ScalarConverter::convert(std::string n)
{
	int type;

	type = getType(n);
	switch(type)
	{
		// default:
		// 	std::cout << "invalid_input" << std::endl;
		// 	break ;
		case CHAR:
			baseChar(n);
			break ;
		case INT:
			baseInt(n);
			break ;
		case FLOAT:
			baseFloat(n);
			break ;
		case DOUBLE:
			baseDouble(n);
			break ;
	}
}
