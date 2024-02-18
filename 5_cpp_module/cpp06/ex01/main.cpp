#include "Serializer.hpp"

int main(void)
{
    Data ex;

    ex.setName("example");
    std::cout << (Serializer::deserialize(Serializer::serialize(&ex)))->getName() << std::endl;

    Data sc;

    sc.setName("second");
    std::cout << (Serializer::deserialize(Serializer::serialize(&sc)))->getName() << std::endl;
    return (0);
}