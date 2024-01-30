#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("", 25, 5) { }

PresidentialPardonForm::PresidentialPardonForm(std::string name) : AForm(name, 25, 5) { }

// PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ppf)
// {

// }

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &ppf)
{
    if (this != &ppf)
    {

    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void) { }

void PresidentialPardonForm::beExecuted(std::string target) const
{
    std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
