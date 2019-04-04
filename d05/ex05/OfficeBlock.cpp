/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 18:02:24 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/01 18:55:03 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock() : _intern(nullptr), _signatory(nullptr), _executor(nullptr)
{
}

OfficeBlock::OfficeBlock(Intern *intern, Bureaucrat *signatory, Bureaucrat *executor) :
	_intern(intern), _signatory(signatory), _executor(executor)
{
}

OfficeBlock::~OfficeBlock()
{
}

OfficeBlock::OfficeBlock(OfficeBlock const& copy) :
	_intern(copy._intern), _signatory(copy._signatory), _executor(copy._executor)
{
}

OfficeBlock		&OfficeBlock::operator=(OfficeBlock const& copy)
{
	_intern = copy._intern;
	_signatory = copy._signatory;
	_executor = copy._executor;
	return (*this);
}

void	OfficeBlock::setIntern(Intern *intern)
{
	_intern = intern;
}

void	OfficeBlock::setSignatory(Bureaucrat *signatory)
{
	_signatory = signatory;
}

void	OfficeBlock::setExecutor(Bureaucrat *executor)
{
	_executor = executor;
}

void	OfficeBlock::doBureaucracy(std::string form, std::string target)
{
	if (_intern == nullptr)
		throw OfficeBlock::MissingInternException();
	if (_signatory == nullptr)
		throw OfficeBlock::MissingSignatoryException();
	if (_executor == nullptr)
		throw OfficeBlock::MissingExecutorException();
	Form	*newForm = _intern->makeForm(form, target);
	_signatory->signForm(*newForm);
	_executor->executeForm(*newForm);
}

OfficeBlock::MissingInternException::MissingInternException() throw()
{
}

OfficeBlock::MissingInternException::MissingInternException(MissingInternException const& copy) throw()
{
	(void)copy;
}

OfficeBlock::MissingInternException::~MissingInternException() throw()
{
}

OfficeBlock::MissingInternException	&OfficeBlock::MissingInternException::operator=(MissingInternException const& copy) throw()
{
	(void)copy;
	return (*this);
}

const char	*OfficeBlock::MissingInternException::what() const throw()
{
	return ("Intern is missing");
}

OfficeBlock::MissingSignatoryException::MissingSignatoryException() throw()
{
}

OfficeBlock::MissingSignatoryException::MissingSignatoryException(MissingSignatoryException const& copy) throw()
{
	(void)copy;
}

OfficeBlock::MissingSignatoryException::~MissingSignatoryException() throw()
{
}

OfficeBlock::MissingSignatoryException	&OfficeBlock::MissingSignatoryException::operator=(MissingSignatoryException const& copy) throw()
{
	(void)copy;
	return (*this);
}

const char	*OfficeBlock::MissingSignatoryException::what() const throw()
{
	return ("Signatory is missing");
}

OfficeBlock::MissingExecutorException::MissingExecutorException() throw()
{
}

OfficeBlock::MissingExecutorException::MissingExecutorException(MissingExecutorException const& copy) throw()
{
	(void)copy;
}

OfficeBlock::MissingExecutorException::~MissingExecutorException() throw()
{
}

OfficeBlock::MissingExecutorException	&OfficeBlock::MissingExecutorException::operator=(MissingExecutorException const& copy) throw()
{
	(void)copy;
	return (*this);
}

const char	*OfficeBlock::MissingExecutorException::what() const throw()
{
	return ("Executor is missing");
}
