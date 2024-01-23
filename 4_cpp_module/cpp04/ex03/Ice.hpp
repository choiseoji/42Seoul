#ifndef ICE_HPP
# define ICE_HPP
# include "AMateria.hpp"

class Ice : virtual public AMateria
{
public:
    Ice();
    Ice(const Ice &ice);
    Ice& operator=(const Ice &ice);
    ~Ice();

    void setType();
    std::string const & getType();
    AMateria* clone() const;
    void use(ICharacter& target);

};

#endif