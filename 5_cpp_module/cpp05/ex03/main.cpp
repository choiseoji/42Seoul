#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Bureaucrat bureaucrat("seo", 20);
	Intern someRandomIntern;
	AForm *form;

	form = someRandomIntern.makeForm("shrubbery creation", "shu");
	bureaucrat.signForm(*form);
	bureaucrat.executeForm(*form);

	std::cout << std::endl << "========================" << std::endl << std::endl;

	form = someRandomIntern.makeForm("robotomy request", "rob");
	bureaucrat.signForm(*form);
	bureaucrat.executeForm(*form);

	std::cout << std::endl << "========================" << std::endl << std::endl;

	form = someRandomIntern.makeForm("presidential pardon", "pre");
	bureaucrat.signForm(*form);
	bureaucrat.executeForm(*form);

	return (0);
}
