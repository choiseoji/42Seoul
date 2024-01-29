#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "AForm.hpp"
# include "fstream"

class ShrubberyCreationForm : public AForm
{   
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm &scf);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm &scf);
    ~ShrubberyCreationForm();

    void aboutForm(std::string target);
    // void execute(Bureaucrat const & executor) const;
};

#endif