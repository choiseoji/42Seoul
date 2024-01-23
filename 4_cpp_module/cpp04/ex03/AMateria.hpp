#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <iostream>
// # include "ICharacter.hpp"   // 이렇게 하면 양쪽 다 인클루드 하는거 아닌가

class ICharacter;

class AMateria
{
protected:
    std::string type;

public:
    AMateria();
    AMateria(const AMateria &a);
    AMateria& operator=(const AMateria &a);
    ~AMateria();

    AMateria(std::string const & type);
    // 이거 위에 다 private 으로 해야되나..

    std::string const & getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif