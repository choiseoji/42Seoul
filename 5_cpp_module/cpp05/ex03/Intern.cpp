#include "Intern.hpp"

Intern::Intern(void) { }

Intern::Intern(const Intern &i)
{
	(void)i;
}

Intern& Intern::operator=(const Intern &i)
{
	if (this != &i)
	{
		;
	}
	return (*this);
}

Intern::~Intern() { }

AForm* Intern::makeForm(std::string name, std::string target)
{
	AForm* form;
	int idx = -1;
	std::string l[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	for(int i = 0; i < 3; i++)
	{
		if (l[i] == name)
			idx = i;
	}
	switch(idx)
	{
		default:
			// 에러 메시지 ??
		case 0:
			form = new ShrubberyCreationForm(target);
			break ;
		case 1:
			form = new RobotomyRequestForm(target);
			break ;
		case 2:
			form = new PresidentialPardonForm(target);
			break ;
	}
	std::cout << "Intern creates " << name << std::endl;
	return (form);
}
