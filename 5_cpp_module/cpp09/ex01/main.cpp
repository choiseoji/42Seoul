#include "RPN.hpp"

int main(int ac, char **av)
{

    if (ac > 2)
        return (0);  // 에러 문구 추가하기

    try
    {
        RPN rpn;

        rpn.parsing(av[1]);
        rpn.calculate();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}