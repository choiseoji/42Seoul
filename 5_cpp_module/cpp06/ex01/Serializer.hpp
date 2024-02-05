#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include "Data.hpp"

class  Serializer
{
public:
    Serializer();
    Serializer(const Serializer &s);
    Serializer& operator=(const Serializer &s);
    ~Serializer();

    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);

};

#endif
