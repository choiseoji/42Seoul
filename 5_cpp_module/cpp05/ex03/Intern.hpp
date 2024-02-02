#ifndef INTERN_HPP
# define INTERN_HPP
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern &i);
	Intern& operator=(const Intern &i);
	~Intern();

	AForm* makeForm(std::string name, std::string target);
};

#endif
