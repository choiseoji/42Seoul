/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:48:22 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/28 20:54:47 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= sign_grade)
	{
		is_signed = true;
	}
	else
		Form::GradeTooLowException();
}

std::ostream& operator<<(std::ostream &os, Form &f)
{
	os << "[FORM_INFO]" << std::endl << "name: " << f.getName() << std::endl \
	<< "is signed: " << f.getIsSigned() << std::endl << "sign grade: " << f.getSignGrade() \
	<< std::endl << "execute grade: " << f.getExecuteGrade();
	return (os);
}
