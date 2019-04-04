/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 12:24:48 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/01 17:59:56 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int		main(void)
{
	Form	*f1;
	Form	*f2;
	Form	*f3;
	Form	*f4;
	Intern	i1;
	Bureaucrat	b1 = Bureaucrat("Mr. Abraham", 42);

	f1 = i1.makeForm("robotomy request", "Marvin");
	f2 = i1.makeForm("presidential pardon", "Marvin");
	f3 = i1.makeForm("shrubbery creation", "Marvin");
	std::cout << *f1 << std::endl;
	std::cout << *f2 << std::endl;
	std::cout << *f3 << std::endl;

	b1.signForm(*f1);
	b1.executeForm(*f1);

	f4 = i1.makeForm("TEST", "Marvin");

	return (0);
}
