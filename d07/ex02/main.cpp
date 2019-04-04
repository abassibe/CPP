/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 04:00:19 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/03 12:09:50 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int		main()
{
	Array<char>	emptyTest;
	Array<char>	test(12);

	std::cout << "*****Try to underflow*****\n";
	try
	{
		test[-10] = 'a';
		std::cout << test[0] << std::endl;
	}
	catch (Array<char>::OutOfRangeException::OutOfRangeException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "*****Try to overerflow*****\n";
	try
	{
		test[100] = 'a';
		std::cout << test[0] << std::endl;
	}
	catch (Array<char>::OutOfRangeException::OutOfRangeException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "*****Regular try*****\n";
	try
	{
		test[0] = 'H';
		test[1] = 'e';
		test[2] = 'l';
		test[3] = 'l';
		test[4] = 'o';
		test[5] = ' ';
		test[6] = 'W';
		test[7] = 'o';
		test[8] = 'r';
		test[9] = 'l';
		test[10] = 'd';
		test[11] = 0;
		std::cout << test[0];
		std::cout << test[1];
		std::cout << test[2];
		std::cout << test[3];
		std::cout << test[4];
		std::cout << test[5];
		std::cout << test[6];
		std::cout << test[7];
		std::cout << test[8];
		std::cout << test[9];
		std::cout << test[10];
		std::cout << test[11] << std::endl;
	}
	catch (Array<char>::OutOfRangeException::OutOfRangeException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "Size = " << test.size() << std::endl;
}
