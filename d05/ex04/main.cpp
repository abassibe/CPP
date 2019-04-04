/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 12:24:48 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/01 18:57:55 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"

int		main(void)
{
	OfficeBlock	ob;
	Intern		*joe = new Intern();
	Bureaucrat	*bob = new Bureaucrat("Bob", 50);
	Bureaucrat	*jule = new Bureaucrat("President", 2);

	try
	{
		ob.doBureaucracy("shrubbery creation", "mars");
	}
	catch (OfficeBlock::MissingInternException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (OfficeBlock::MissingSignatoryException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (OfficeBlock::MissingExecutorException &e)
	{
		std::cout << e.what() << std::endl;
	}

	ob.setIntern(joe);
	ob.setSignatory(bob);
	ob.setExecutor(jule);

	try
	{
		ob.doBureaucracy("shrubbery creation", "mars");
		ob.doBureaucracy("robotomy request", "terre");
		ob.doBureaucracy("presidential pardon", "president");
	}
	catch (std::exception &e)
	{
		std::cout << "ERROR : " << e.what() << std::endl;
	}

	return (0);
}
