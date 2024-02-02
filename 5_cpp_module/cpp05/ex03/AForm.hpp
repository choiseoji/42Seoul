/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:38:12 by seojchoi          #+#    #+#             */
/*   Updated: 2024/02/02 21:01:34 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP
#include "Bureaucrat.hpp"

class AForm
{
private:
	const std::string name;
	bool is_signed;
	const int sign_grade;
	const int execute_grade;

public:
	AForm();
	AForm(std::string name, bool is_signed, int sign_grade, int execute_grade);
	AForm(const AForm &f);
	AForm& operator=(const AForm &f);
	virtual ~AForm();

	std::string getName() const;
	bool getIsSigned() const;
	int getSignGrade() const;
	int getExecuteGrade() const;
	void copyArg(const AForm *f);

	void checkGrade(int grade) const;
	void beSigned(Bureaucrat &b) ;
	void execute(Bureaucrat const & executor) const;

	virtual void beExecuted(std::string target) const = 0;

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

	class UnSignedException : public std::exception
	{
	public:
		virtual const char* what(void) const throw()
		{
			return ("This is an unsigned form");
		}
	};

	class WrongFormName : public std::exception
	{
	public:
		virtual const char* what(void) const throw()
		{
			return ("This kind of form does not exist");
		}
	};
};

std::ostream& operator<<(std::ostream &os, AForm &f);

#endif
