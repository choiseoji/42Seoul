/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:39:37 by seojchoi          #+#    #+#             */
/*   Updated: 2024/02/01 20:08:45 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <exception>

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

	std::string getName() const;
	int getGrade() const;
	void increment();
	void decrement();
	void checkGrade(int grade);

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
