#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
    PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm &ppf);
    PresidentialPardonForm& operator=(const PresidentialPardonForm &ppf);
    ~PresidentialPardonForm();

};

#endif