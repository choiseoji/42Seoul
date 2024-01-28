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
# define FROM_HPP
# include "Bureaucrat.hpp"

class Form
{
private:
	const std::string name;
	bool is_signed;
	const int grade_required;
	const int grade_execute;

public:
	Form();
	Form(const Form &f);
	Form& operator=(const Form &f);
	~Form();

	std::string getName();
	bool getIsSigned();
	int getGradeRequired();
	int getGradeExecute();

	void beSigned(Bureaucrat &b);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what(void) const throw()
		{
			return ("Form's grade is too high");
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what(void) const throw()
		{
			return ("Form's grade is too low");
		}
	};
};

#endif
