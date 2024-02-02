#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("", false, 72, 45) { }

RobotomyRequestForm::RobotomyRequestForm(std::string name) : AForm(name, false, 72, 45) { }

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rrf) : AForm(rrf.getName(), rrf.getIsSigned(), 72, 45) { }

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &rrf)
{
    if (this != &rrf)
    {
        const AForm* basePtr = &rrf;
        copyArg(basePtr);
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) { }

void RobotomyRequestForm::beExecuted(std::string target) const
{
    std::cout << "drillll~ 🔩 (drilling noises)" << std::endl;;
    std::cout << target << " has been robotomized successfully 50% of the time" << std::endl;
}
