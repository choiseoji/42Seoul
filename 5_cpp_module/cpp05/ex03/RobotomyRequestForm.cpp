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
    int random_num;

    std::cout << "drillll~ 🔩 (drilling noises)" << std::endl;
    srand(time(0));
    random_num = rand() % 2;
    switch(random_num)
    {
        case 0:
            std::cout << target <<  " robotomized success!!" << std::endl;
            break ;
        case 1:
            std::cout << target << " robotomized fail!!" << std::endl;
            break ;
    }
}
