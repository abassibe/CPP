/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:53:02 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/01 15:33:43 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form()
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	Form("Robotomy Request Form", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& copy) :
	Form(copy), _target(copy._target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const& copy)
{
	_target = copy._target;
	return (*this);
}

void				RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (getGradeToExecute() < executor.getGrade())
		throw Form::GradeTooLowException();
	if (!isSigned())
		throw Form::NotSignedException();
	srand(time(nullptr));
	if (rand() % 2)
	{
		system("afplay -t 3 Drill.wav");
		std::cout << _target << " has been robotomized.\n";
	}
	else
		std::cout << _target << " was not robotomized.\n";
}
