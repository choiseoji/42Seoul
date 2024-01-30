#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "AForm.hpp"
# include "fstream"

class ShrubberyCreationForm : public AForm
{
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string name);
    ShrubberyCreationForm(const ShrubberyCreationForm &scf);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm &scf);
    ~ShrubberyCreationForm();

    void beExecuted(std::string target) const;
};

#endif
