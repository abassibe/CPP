/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 12:00:50 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/01 12:39:06 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

class Bureaucrat
{
	public:
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const& copy);
		~Bureaucrat();
		Bureaucrat		&operator=(Bureaucrat const& copy);
		std::string const	getName() const;
		int					getGrade() const;
		void				increaseGrade();
		void				decreaseGrade();

		class	GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException() throw();
				GradeTooHighException(GradeTooHighException const& copy) throw();
				virtual ~GradeTooHighException() throw();
				GradeTooHighException	&operator=(GradeTooHighException const& copy) throw();
				const char	*what() const throw();
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException() throw();
				GradeTooLowException(GradeTooLowException const& copy) throw();
				virtual ~GradeTooLowException() throw();
				GradeTooLowException	&operator=(GradeTooLowException const& copy) throw();
				const char	*what() const throw();
		};

	private:
		Bureaucrat();
		std::string const	_name;
		int					_grade;
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const& bureaucrat);

#endif
