#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string name);
    PresidentialPardonForm(const PresidentialPardonForm &ppf);
    PresidentialPardonForm& operator=(const PresidentialPardonForm &ppf);
    ~PresidentialPardonForm();

    void beExecuted(std::string target) const;
};

#endif
