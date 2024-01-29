#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm(145, 137) { }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &scf)
{
    
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &scf)
{
    if (this != &scf)
    {

    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) { }

void ShrubberyCreationForm::aboutForm(std::string target)
{
    std::string file_name;

    file_name = target+"_shrubbery";
    std::ofstream file(file_name);
    if (file.is_open())
    {
        file << "아스키 트리 심어주기";
    }
}

// void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
// {
//     // form is_signed check

//     // check bureaucrat's grade

// }
