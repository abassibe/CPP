/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 12:44:34 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/01 14:12:00 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form(std::string name, int gradeToSign, int grdeToExecute);
		Form(Form const& copy);
		~Form();
		Form	&operator=(Form const& copy);
		void				beSigned(Bureaucrat &bureaucrat);
		std::string const	getName() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		bool				isSigned() const;

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
		Form();
		bool				_isSigned;
		std::string const	_name;
		int const			_gradeToSign;
		int const			_gradeToExecute;
};

std::ostream	&operator<<(std::ostream &o, Form const& form);

#endif
