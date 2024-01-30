#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("", 72, 45) { }

RobotomyRequestForm::RobotomyRequestForm(std::string name) : AForm(name, 72, 45) { }

// RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rrf)
// {

// }

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &rrf)
{
    if (this != &rrf)
    {

    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) { }

void RobotomyRequestForm::beExecuted(std::string target) const
{
    std::cout << "drillll~ 🔩 (drilling noises)" << std::endl;;
    std::cout << target << " has been robotomized successfully 50% of the time" << std::endl;
}
