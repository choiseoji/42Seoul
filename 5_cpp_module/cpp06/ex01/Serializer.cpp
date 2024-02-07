#include "Serializer.hpp"

Serializer::Serializer(void) { }

Serializer::Serializer(const Serializer &s) { (void)s; }

Serializer& Serializer::operator=(const Serializer &s)
{
    (void)s;
    return (*this);
}

Serializer::~Serializer(void) { }

uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t new_data;

    new_data = reinterpret_cast<uintptr_t>(ptr);
    return (new_data);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    Data* new_data;

    new_data = reinterpret_cast<Data *>(raw);
    return (new_data);
}
