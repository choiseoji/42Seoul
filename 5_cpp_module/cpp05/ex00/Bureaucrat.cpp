/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:42:16 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/28 20:31:03 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
{

}

Bureaucrat::Bureaucrat(const Bureaucrat& b) : name(b.name)
{
	this->grade = b.grade;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	checkGrade(grade);
	this->grade = grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b)
{
	if (this != &b)
	{

	}
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{

}

std::string Bureaucrat::getName(void)
{
	return (this->name);
}

int Bureaucrat::getGrade(void)
{
	return (this->grade);
}

void Bureaucrat::increment(int g)
{
	checkGrade(this->grade - g);
	this->grade -= g;
}

void Bureaucrat::decrement(int g)
{
	checkGrade(this->grade + g);
	this->grade += g;
}

void Bureaucrat::checkGrade(int grade)
{
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());  // throw로 객체를 던짐
	else if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
}

std::ostream& operator<<(std::ostream &os, std::exception &e)
{
	os << e.what();
	return (os);
}
