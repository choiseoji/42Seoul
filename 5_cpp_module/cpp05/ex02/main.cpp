#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	Bureaucrat bureaucrat("seo", 20);

	AForm *a_form = new ShrubberyCreationForm("shu");   // name이 target
	bureaucrat.signForm(*a_form);   // sign ok
	bureaucrat.executeForm(*a_form);   // execute no

	std::cout << std::endl << "========================" << std::endl << std::endl;

	AForm *b_form = new PresidentialPardonForm("pre");
	bureaucrat.signForm(*b_form);
	bureaucrat.executeForm(*b_form);

	std::cout << std::endl << "========================" << std::endl << std::endl;

	AForm *c_form = new RobotomyRequestForm("rob");
	bureaucrat.signForm(*c_form);
	bureaucrat.executeForm(*c_form);

	return (0);
}
