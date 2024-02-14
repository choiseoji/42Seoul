#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	AForm *a_form;
	AForm *b_form;
	AForm *c_form;

	try
	{
		Bureaucrat bureaucrat("seo", 10);

		a_form = new ShrubberyCreationForm("shru");   // name이 target, sign: 145, execute: 137
		bureaucrat.signForm(*a_form);   // sign ok
		bureaucrat.executeForm(*a_form);

		std::cout << std::endl << "========================" << std::endl << std::endl;

		b_form = new PresidentialPardonForm("pre");   // sign: 25, execute: 5
		bureaucrat.signForm(*b_form);
		bureaucrat.executeForm(*b_form);

		std::cout << std::endl << "========================" << std::endl << std::endl;

		c_form = new RobotomyRequestForm("rob");   // sign: 72, execute: 45
		bureaucrat.signForm(*c_form);
		bureaucrat.executeForm(*c_form);

	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	delete a_form;
	delete b_form;
	delete c_form;
	return (0);
}
