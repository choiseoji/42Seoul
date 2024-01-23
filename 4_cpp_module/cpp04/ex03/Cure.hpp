#ifndef Cure_HPP
# define Cure_HPP
# include "AMateria.hpp"

class Cure : virtual public AMateria
{
public:
    Cure();
    Cure(const Cure &cure);
    Cure& operator=(const Cure &cure);
    ~Cure();

    std::string const & getType();
    AMateria* clone() const;
    void use(ICharacter& target);
};

#endif