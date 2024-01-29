#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm(25, 5) { }

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ppf)
{

}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &ppf)
{
    if (this != &ppf)
    {

    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void) { }
