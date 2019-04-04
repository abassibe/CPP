/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:36:59 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/01 15:32:20 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	Form("Shrubbery Creation Form", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& copy) :
	Form(copy), _target(copy._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const& copy)
{
	_target = copy._target;
	return (*this);
}

void					ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (getGradeToExecute() < executor.getGrade())
		throw Form::GradeTooLowException();
	if (!isSigned())
		throw Form::NotSignedException();
	std::ofstream	ofs;
	std::string		target = _target + "_shrubbery";
	ofs.open(target, std::ios::out | std::ios::app);
	ofs << "           \\/ |    |/" << std::endl;
	ofs << "        \\/ / \\||/  /_/___/_" << std::endl;
	ofs << "         \\/   |/ \\/" << std::endl;
	ofs << "    _\\__\\_\\   |  /_____/_" << std::endl;
	ofs << "           \\  | /          /" << std::endl;
	ofs << "  __ _-----`  |{,-----------~" << std::endl;
	ofs << "            \\ }{" << std::endl;
	ofs << "             }{{" << std::endl;
	ofs << "             }}{" << std::endl;
	ofs << "             {{}" << std::endl;
	ofs << "       , -=-~{ .-^- _" << std::endl;
	ofs << "             `}" << std::endl;
	ofs << "              {" << std::endl;
	ofs.close();
}
