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
	int num;

	i = 0;
	dot = false;
	while (n[i])
	{
		if (n[i] == '.')
			dot = true;
		i++;
	}
	num = strtod(n.c_str(), &ptr);

	if (i != 1 &&*ptr && n[i - 1] != 'f')
		return (ERROR);
	else if (dot == true && n[i - 1] == 'f')
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

}

void baseInt(std::string n)
{

}

void baseFloat(std::string n)
{

}

void baseDouble(std::string n)
{
	
}

void ScalarConverter::convert(std::string n)
{
	int type;

	type = getType(n);
	switch(type)
	{
		default:
			std::cout << "invalid_input" << std::endl;
			break ;
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
