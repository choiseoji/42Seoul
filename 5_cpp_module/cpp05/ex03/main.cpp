#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
	AForm *shu_form;
	AForm *rob_form;
	AForm *pre_form;

	try
	{
		Bureaucrat bureaucrat("seo", 20);
		Intern someRandomIntern;

		shu_form = someRandomIntern.makeForm("shrubbery creation", "shu");
		bureaucrat.signForm(*shu_form);
		bureaucrat.executeForm(*shu_form);

		std::cout << std::endl << "========================" << std::endl << std::endl;

		rob_form = someRandomIntern.makeForm("robotomy request", "rob");
		bureaucrat.signForm(*rob_form);
		bureaucrat.executeForm(*rob_form);

		std::cout << std::endl << "========================" << std::endl << std::endl;

		pre_form = someRandomIntern.makeForm("presidential pardon", "pre");
		bureaucrat.signForm(*pre_form);
		bureaucrat.executeForm(*pre_form);

	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	delete shu_form;
	delete rob_form;
	delete pre_form;
	return (0);
}
