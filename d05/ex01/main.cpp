/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 12:24:48 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/01 14:20:18 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int		main()
{
	try
	{
		Bureaucrat	bob("Bob", 200);
		std::cout << "No printable, cause of throwing exception" << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	bernard("Bernard", 0);
		std::cout << "No printable, cause of throwing exception" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	roger("Roger", 2);
		std::cout << roger << std::endl;
		roger.increaseGrade();
		std::cout << roger << std::endl;
		roger.increaseGrade();
		std::cout << roger << std::endl;
		std::cout << "No printable, cause of throwing exception" << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	antoine("Antoine", 149);
		std::cout << antoine << std::endl;
		antoine.decreaseGrade();
		std::cout << antoine << std::endl;
		antoine.decreaseGrade();
		std::cout << antoine << std::endl;
		std::cout << "No printable, cause of throwing exception" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	Bureaucrat	b1("Bruno", 140);
	Bureaucrat	b2("Jean", 12);
	Form		f1("Form42", 65, 45);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << b1.getName() << " try to sign " << f1.getName() << std::endl;
	b1.signForm(f1);
	std::cout << b2.getName() << " try to sign " << f1.getName() << std::endl;
	b2.signForm(f1);
}
