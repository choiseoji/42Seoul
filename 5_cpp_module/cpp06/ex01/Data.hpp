#ifndef DATA_HPP
# define DATA_HPP
# include <iostream>

struct Data
{
private:
    std::string name;

public:
    Data();
    Data(const Data &d);
    Data& operator=(const Data &d);
    ~Data();

    void setName(std::string name);
    std::string getName(void);
};

#endif