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

	// class WrongFormName : public std::exception
	// {
	// public:
	// 	virtual const char* what(void) const throw()
	// 	{
	// 		return ("This kind of form does not exist");
	// 	}
	// };
};

#endif
