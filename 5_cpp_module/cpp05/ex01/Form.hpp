/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:38:12 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/28 22:21:37 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string name;
	bool is_signed;
	const int sign_grade;
	const int execute_grade;

public:
	Form();
	Form(std::string name, int sign_grade, int execute_grade);
	Form(const Form &f);
	Form& operator=(const Form &f);
	~Form();

	std::string getName();
	bool getIsSigned();
	int getSignGrade();
	int getExecuteGrade();
	void checkGrade(int grade);

	void beSigned(Bureaucrat &b);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what(void) const throw()
		{
			return ("form's required grade is too high");
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what(void) const throw()
		{
			return ("form's required grade is too low");
		}
	};

	class AlreadySignedException : public std::exception
	{
	public:
		virtual const char* what(void) const throw()
		{
			return ("it has already been signed");
		}
	};
};

std::ostream& operator<<(std::ostream &os, Form &f);

#endif
