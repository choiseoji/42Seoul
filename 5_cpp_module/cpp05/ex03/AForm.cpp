#include "AForm.hpp"

AForm::AForm(void) : name(""), sign_grade(0), execute_grade(0)
{
	this->is_signed = false;
}

AForm::AForm(std::string name, int sign_grade, int execute_grade)
: name(name), sign_grade(sign_grade), execute_grade(execute_grade)
{
	this->is_signed = false;
}

AForm::AForm(const AForm &f) : name(f.name), sign_grade(f.sign_grade), execute_grade(f.execute_grade)
{
	this->is_signed = f.is_signed;
}

AForm& AForm::operator=(const AForm &f)
{
	if (this != &f)
	{
		this->is_signed = f.is_signed;
	}
	return (*this);
}

AForm::~AForm() { }

std::string AForm::getName(void) const
{
	return (this->name);
}

bool AForm::getIsSigned(void) const
{
	return (this->is_signed);
}

int AForm::getSignGrade(void) const
{
	return (this->sign_grade);
}

int AForm::getExecuteGrade(void) const
{
	return (this->execute_grade);
}

void AForm::checkGrade(int grade) const
{
    if (grade < 1)
        throw (AForm::GradeTooHighException());
    else if (grade > 150)
        throw (AForm::GradeTooLowException());
}

void AForm::beSigned(Bureaucrat &b)
{
    if (this->is_signed == true)
        throw (AForm::AlreadySignedException());
    else if (b.getGrade() > sign_grade)
        throw (Bureaucrat::GradeTooLowException());

	this->is_signed = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (this->is_signed == false)
		throw(AForm::UnSignedException());
	else if (executor.getGrade() > execute_grade)
		throw(Bureaucrat::GradeTooLowException());

	this->beExecuted(this->name);
}

std::ostream& operator<<(std::ostream &os, AForm &f)
{
	os << "[FORM_INFO]" << std::endl << "name: " << f.getName() << std::endl \
	<< "is signed: " << f.getIsSigned() << std::endl << "sign grade: " << f.getSignGrade() \
	<< std::endl << "execute grade: " << f.getExecuteGrade();
	return (os);
}
