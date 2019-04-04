/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 12:24:48 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/01 14:10:38 by abassibe         ###   ########.fr       */
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
}
