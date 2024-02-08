#include "ScalarConverter.hpp"

int input_error(void)
{
	std::cout << "You need to provide one input value" << std::endl;
	return (0);
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (input_error());
	ScalarConverter::convert(av[1]);
	return (0);
}
