#include "Serializer.hpp"

int main(void)
{
    Data ex;

    ex.name = "example";
    std::cout << (Serializer::deserialize(Serializer::serialize(&ex)))->name << std::endl;

    Data sc;

    sc.name = "second";
    std::cout << (Serializer::deserialize(Serializer::serialize(&sc)))->name << std::endl;
    return (0);
}
