/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:42:16 by seojchoi          #+#    #+#             */
/*   Updated: 2024/02/01 20:10:18 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name("")
{
	this->grade = 0;
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
		this->grade = b.grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat(void) { }

std::string Bureaucrat::getName(void) const
{
	return (this->name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

void Bureaucrat::increment(int num)
{
	checkGrade(this->grade - num);
	this->grade -= num;
}

void Bureaucrat::decrement(int num)
{
	checkGrade(this->grade + num);
	this->grade += num;
}

void Bureaucrat::checkGrade(int grade)
{
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
}

std::ostream& operator<<(std::ostream &os, Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (os);
}
