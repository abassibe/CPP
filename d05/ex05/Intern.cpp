/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 16:18:10 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/01 17:57:56 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

std::string
Intern::_names[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};

Intern::Intern()
{
	_functions[0] = &Intern::newPresidential;
	_functions[1] = &Intern::newRobotomy;
	_functions[2] = &Intern::newShrubbery;
}

Intern::Intern(Intern const& copy)
{
	(void)copy;
}

Intern::~Intern()
{
}

Intern		&Intern::operator=(Intern const& copy)
{
	(void)copy;
	return (*this);
}

Form	*Intern::newShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

Form	*Intern::newRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

Form	*Intern::newPresidential(std::string target)
{
	return (new PresidentialPardonForm(target));
}

Form		*Intern::makeForm(std::string form, std::string target)
{
	try
	{
		return searchForm(form, target);
	}
	catch (std::exception &e)
	{
		std::cout << form << " : form not found... :(" << std::endl;
		return NULL;
	}
}

Form*		Intern::searchForm(std::string name, std::string target)
{
	for (int i = 0; i < 3; i += 1)
	{
		if (name == this->_names[i])
			return (this->*_functions[i])(target);
	}
	std::cout << "Form not found" << std::endl;
	return (NULL);
}

