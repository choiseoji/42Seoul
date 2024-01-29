#include "Form.hpp"

Form::Form(void) : name(""), sign_grade(0), execute_grade(0)
{
	this->is_signed = false;
}

Form::Form(std::string name, int sign_grade, int execute_grade) 
: name(name), sign_grade(sign_grade), execute_grade(execute_grade)
{
	this->is_signed = false;
}

Form::Form(const Form &f) : name(f.name), sign_grade(f.sign_grade), execute_grade(f.execute_grade)
{
	this->is_signed = f.is_signed;
}

Form& Form::operator=(const Form &f)
{
	if (this != &f)
	{
		this->is_signed = f.is_signed;
	}
	return (*this);
}

Form::~Form() { }

std::string Form::getName(void)
{
	return (this->name);
}

bool Form::getIsSigned(void)
{
	return (this->is_signed);
}

int Form::getSignGrade(void)
{
	return (this->sign_grade);
}

int Form::getExecuteGrade(void)
{
	return (this->execute_grade);
}

void Form::checkGrade(int grade)
{
    if (grade < 1)
        throw (Form::GradeTooHighException());
    else if (grade > 150)
        throw (Form::GradeTooLowException());
}

void Form::beSigned(Bureaucrat &b)
{
    if (this->is_signed == true)
        throw (Form::AlreadySignedException());
    else if (b.getGrade() > sign_grade)
        throw (Form::GradeTooLowException());   // 여기 예외 처리 tooLow가 맞는건지 잘 모르겠음
    
	is_signed = true;
}

std::ostream& operator<<(std::ostream &os, Form &f)
{
	os << "[FORM_INFO]" << std::endl << "name: " << f.getName() << std::endl \
	<< "is signed: " << f.getIsSigned() << std::endl << "sign grade: " << f.getSignGrade() \
	<< std::endl << "execute grade: " << f.getExecuteGrade();
	return (os);
}