#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string name);
    RobotomyRequestForm(const RobotomyRequestForm &rrf);
    RobotomyRequestForm& operator=(const RobotomyRequestForm &rrf);
    ~RobotomyRequestForm();

    void beExecuted(std::string target) const;
};

#endif
