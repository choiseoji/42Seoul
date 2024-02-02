#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("", false, 25, 5) { }

PresidentialPardonForm::PresidentialPardonForm(std::string name) : AForm(name, false, 25, 5) { }

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ppf) : AForm(ppf.getName(), ppf.getIsSigned(), 25, 5) { }

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &ppf)
{
    if (this != &ppf)
    {
        //
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void) { }

void PresidentialPardonForm::beExecuted(std::string target) const
{
    std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
