/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:55:35 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/01 15:34:45 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form()
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	Form("Presidential Pardon Form", 145, 137), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& copy) :
	Form(copy), _target(copy._target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const& copy)
{
	_target = copy._target;
	return (*this);
}

void					PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	if (getGradeToExecute() < executor.getGrade())
		throw Form::GradeTooLowException();
	if (!isSigned())
		throw Form::NotSignedException();
	std::cout << _target << " has been pardoned by Zafod Beeblebrox.\n";
}
