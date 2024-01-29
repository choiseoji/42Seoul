/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:39:37 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/28 22:18:12 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <exception>

class Form;

class Bureaucrat
{
private:
	const std::string name;
	int grade;

public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &b);
	Bureaucrat(std::string name, int grade);
	Bureaucrat& operator=(const Bureaucrat &b);
	~Bureaucrat();

	std::string getName();
	int getGrade();
	void increment(int g);
	void decrement(int g);
	void checkGrade(int grade);

	void signForm(Form &f);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what(void) const throw()
		{
			return ("bureaucrat's grade is too high");
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what(void) const throw()
		{
			return ("bureaucrat's grade is too low");
		}
	};
};

std::ostream& operator<<(std::ostream &os, Bureaucrat &b);


#endif
