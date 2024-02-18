#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
    int random_num;

    srand(time(0));
    random_num = rand() % 3;
    switch (random_num)
    {
        case 0:
            std::cout << "create A type" << std::endl;
            return (new A());
        
        case 1:
            std::cout << "create B type" << std::endl;
            return (new B());

        case 2:
            std::cout << "create C type" << std::endl;
            return (new C());
    }
    return (NULL);
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "it is A type" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "it is B type" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "it is C type" << std::endl;
}

void identify(Base& p)
{
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "it is A type" << std::endl;
    } catch (std::bad_cast& ex){
        ;
    }

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "it is B type" << std::endl;
    } catch (std::bad_cast& ex){
        ;
    }

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "it is C type" << std::endl;
    } catch (std::bad_cast& ex){
        ;
    }
}
