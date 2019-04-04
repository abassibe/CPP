/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 12:24:48 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/01 19:06:57 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <exception>
#include <iostream>
#include <string>
#include "CentralBureaucracy.hpp"

int		main(void)
{
	CentralBureaucracy	government;

	try
	{
		government.addBureaucrat(new Bureaucrat("John", 150));
		government.addBureaucrat(new Bureaucrat("Joe", 3));
		government.addBureaucrat(new Bureaucrat("Jonnas", 1));
		government.addBureaucrat(new Bureaucrat("Jim", 15));
		government.addBureaucrat(new Bureaucrat("Janette", 93));
		government.addBureaucrat(new Bureaucrat("Jasphar", 1));
		government.addBureaucrat(new Bureaucrat("Julien", 135));
		government.addBureaucrat(new Bureaucrat("Jemil", 3));
		government.addBureaucrat(new Bureaucrat("Jean", 12));
		government.addBureaucrat(new Bureaucrat("Joeffray", 65));
		government.addBureaucrat(new Bureaucrat("Jacky", 143));
		government.addBureaucrat(new Bureaucrat("Jeremy", 1));
		government.addBureaucrat(new Bureaucrat("Jeff", 5));
		government.addBureaucrat(new Bureaucrat("Jazon", 103));
		government.addBureaucrat(new Bureaucrat("Bernard", 1));
		government.addBureaucrat(new Bureaucrat("Francois", 45));
		government.addBureaucrat(new Bureaucrat("Dude", 91));
		government.addBureaucrat(new Bureaucrat("Jeanemare", 1));
		government.addBureaucrat(new Bureaucrat("Brutus", 110));
		government.addBureaucrat(new Bureaucrat("Cocker", 11));

		government.queueUp("Kriss");
		government.queueUp("Kelvin");
		government.queueUp("Keryan");
		government.queueUp("Kenjy");
		government.queueUp("Kassim");
		government.queueUp("Kerim");
		government.queueUp("Kameron");
		government.queueUp("Killyan");
		government.queueUp("Kyliane");
		government.queueUp("Kerem");
		government.queueUp("Kevin");
		government.queueUp("Kentin");
		government.queueUp("Khalis");
		government.queueUp("Kylan");

		government.doBureaucracy();
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
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
