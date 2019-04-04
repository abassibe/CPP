/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 12:02:23 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/01 16:12:21 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(150)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const& copy) : _name(copy._name)
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const& copy)
{
	_grade = copy._grade;
	return (*this);
}

std::string const	Bureaucrat::getName() const
{
	return (_name);
}

int					Bureaucrat::getGrade() const
{
	return (_grade);
}

void				Bureaucrat::increaseGrade()
{
	if (_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade--;
}

void				Bureaucrat::decreaseGrade()
{
	if (_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade++;
}

void				Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signs " << form.getName() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << _name << " connot signs " << form.getName() << " because: " << e.what() << std::endl;
	}
}

void				Bureaucrat::executeForm(Form const & form)
{
	try
	{
		std::cout << _name << " executes " << form.getName() << std::endl;
		form.execute(*this);
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << _name << " connot executes " << form.getName() << " because: " << e.what() << std::endl;
	}
	catch (Form::NotSignedException &e)
	{
		std::cout << _name << " connot executes " << form.getName() << " because: " << e.what() << std::endl;
	}
}

std::ostream		&operator<<(std::ostream &o, Bureaucrat const& bureaucrat)
{
	o << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (o);
}

Bureaucrat::GradeTooHighException::GradeTooHighException() throw()
{
}

Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const& copy) throw()
{
	(void)copy;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
}

Bureaucrat::GradeTooHighException	&Bureaucrat::GradeTooHighException::operator=(GradeTooHighException const& copy) throw()
{
	(void)copy;
	return (*this);
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high (1 max)");
}

Bureaucrat::GradeTooLowException::GradeTooLowException() throw()
{
}

Bureaucrat::GradeTooLowException::GradeTooLowException(GradeTooLowException const& copy) throw()
{
	(void)copy;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
}

Bureaucrat::GradeTooLowException	&Bureaucrat::GradeTooLowException::operator=(GradeTooLowException const& copy) throw()
{
	(void)copy;
	return (*this);
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low (150 max)");
}
