#include <iostream>
#include <iomanip>
#include <cmath>

int main(void)
{
	// char cn;
	// int in;
	// float fn;
	// double dn;

	// fn = 42.00f;
	// cn = static_cast<char> (fn);
	// in = static_cast<int> (fn);
	// dn = static_cast<double> (fn);

	// std::cout << "char: " << cn << std::endl;
	// std::cout << "int: " << in << std::endl;
	// std::cout << "float: " << std::fixed << std::setprecision(1) << fn << std::endl;
    // std::cout << "double: " << std::fixed << std::setprecision(1) << dn << std::endl;

	double num;
	char *ptr;
	std::string str;

	std::cin >> str;
	num = strtod(str.c_str(), &ptr);
	if (std::isnan(num))
		std::cout << "is_nan" << "\n";
	else if (std::isinf(num))
		std::cout << "is_inf" << "\n";
	if (*ptr)
		std::cout << "error" << "\n";
	std::cout << num << "\n";
	return (0);
}
