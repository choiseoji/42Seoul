#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) { }

ScalarConverter::ScalarConverter(const ScalarConverter &sc) { }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &sc)
{
    if (this != &sc)
    {
        ;
    }
    return (*this);
}

ScalarConverter::~ScalarConverter(void) { }

int checkType(std::string num)
{

}

void baseChar(std::string num)
{
    // char에 맞게 캐스팅
    
}

void baseInt(std::string num)
{
    
}

void baseFloat(std::string num)
{
    
}

void baseDouble(std::string num)
{
    
}

void ScalarConverter::convert(std::string num)
{
    int type;

    type = checkType(num);
    switch (type)
    {
        case CHAR:
            baseChar(num);

        case INT:
            baseInt(num);

        case FLOAT:
            baseFloat(num);

        case DOUBLE:
            baseDouble(num);
    }
}
