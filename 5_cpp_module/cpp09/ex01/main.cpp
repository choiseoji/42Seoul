#include "RPN.hpp"

int main(int ac, char **av)
{
    try
    {
        if (ac > 2)
            throw std::runtime_error("Error: too many input");
        
        RPN rpn;

        rpn.calculate(av[1]);
        std::cout << rpn.getResult() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}