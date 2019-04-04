/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 12:45:30 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/01 14:20:56 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _isSigned(false), _name("NoName"), _gradeToSign(1), _gradeToExecute(1)
{
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _isSigned(false),
	_name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const& copy) : _isSigned(copy._isSigned), _name(copy._name),
	_gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
}

Form::~Form()
{
}

Form	&Form::operator=(Form const& copy)
{
	_isSigned = copy._isSigned;
	return (*this);
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getGradeToSign())
		throw Form::GradeTooLowException();
	else
		_isSigned = true;
}

std::string const	Form::getName() const
{
	return (_name);
}

int					Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int					Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

bool				Form::isSigned() const
{
	return (_isSigned);
}

std::ostream	&operator<<(std::ostream &o, Form const& form)
{
	if (form.isSigned())
		o << form.getName() << "can be signed by a grade " << form.getGradeToSign() << "and executed by a grade " << form.getGradeToExecute() << "(Form already signed)";

	if (!form.isSigned())
		o << form.getName() << "can be signed by a grade " << form.getGradeToSign() << "and executed by a grade " << form.getGradeToExecute();
	return (o);
}

Form::GradeTooHighException::GradeTooHighException() throw()
{
}

Form::GradeTooHighException::GradeTooHighException(GradeTooHighException const& copy) throw()
{
	(void)copy;
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{
}

Form::GradeTooHighException	&Form::GradeTooHighException::operator=(GradeTooHighException const& copy) throw()
{
	(void)copy;
	return (*this);
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

Form::GradeTooLowException::GradeTooLowException() throw()
{
}

Form::GradeTooLowException::GradeTooLowException(GradeTooLowException const& copy) throw()
{
	(void)copy;
}

Form::GradeTooLowException::~GradeTooLowException() throw()
{
}

Form::GradeTooLowException	&Form::GradeTooLowException::operator=(GradeTooLowException const& copy) throw()
{
	(void)copy;
	return (*this);
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}
