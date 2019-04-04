/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 12:24:48 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/01 16:12:47 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int		main()
{
	/*	Bureaucrat	b1("Bruno", 140);
		Bureaucrat	b2("Jean", 12);
		ShrubberyCreationForm		f1("home");
		RobotomyRequestForm		f2(b1.getName());
		PresidentialPardonForm		f3(b2.getName());



		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << b1.getName() << " try to sign " << f1.getName() << std::endl;
		b1.signForm(f1);
		std::cout << b2.getName() << " try to sign " << f1.getName() << std::endl;
		b2.signForm(f1);*/


	ShrubberyCreationForm	form1("Tree");
	RobotomyRequestForm	form2("Sonic");
	PresidentialPardonForm	form3("You");

	std::cout << "Non-functional case:\n\n";

	{
		Bureaucrat	stickMan("StickMan", 150);
		Bureaucrat	stickMan2("StickMan2", 1);
		std::cout << stickMan << std::endl;
		stickMan.signForm(form1);
		std::cout << stickMan2 << std::endl;
		stickMan2.executeForm(form1);
	}

	std::cout << "\nFunctional case:\n\n";
	{
		Bureaucrat	stickMan("StickMan", 1);
		std::cout << stickMan << std::endl;
		stickMan.signForm(form1);
		stickMan.executeForm(form1);
	}
	{
		Bureaucrat	bender("Bender", 1);
		std::cout << bender << std::endl;
		bender.signForm(form2);
		bender.executeForm(form2);
	}
	{
		Bureaucrat	eddyMalou("Eddy Malou", 1);
		std::cout << eddyMalou << std::endl;
		eddyMalou.signForm(form3);
		eddyMalou.executeForm(form3);
	}
}
