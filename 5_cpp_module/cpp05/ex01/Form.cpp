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

Form::Form(void) : name(""), grade_required(0), grade_execute(0)
{
	this->is_signed = false;
}

Form::Form(const Form &f) : name(f.name), grade_required(f.grade_required), grade_execute(f.grade_execute)
{
	this->is_signed = f.is_signed;
}

Form& Form::operator=(const Form &f)
{
	if (this != &f)
	{
		// 여기 const는 어떻게 할까?? ㅎ
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

int Form::getGradeRequired(void)
{
	return (this->grade_required);
}

int Form::getGradeExecute(void)
{
	return (this->grade_execute);
}

void Form::beSigned(Bureaucrat &b)
{
	// bureaucrat의 등급이 사인할 자격이 된다면 사인해주기
	if (b.getGrade() <= grade_required)
	{
		is_signed = true;
	}
	else
		Form::GradeTooLowException();
}
