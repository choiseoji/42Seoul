#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm(72, 45) { }

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rrf)
{

}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &rrf)
{
    if (this != &rrf)
    {

    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) { }
