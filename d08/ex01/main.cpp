/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:46:17 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/03 15:49:39 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "span.hpp"

int		main()
{
	Span sp = Span(5);

	try
	{
		std::cout << sp.shortestSpan() <<std::endl;
	}
	catch (Span::MissingElementException &e)
	{
		std::cout << e.what() <<std::endl;
	}
	try
	{
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(3);
		sp.addNumber(5);
		sp.addNumber(54);
	}
	catch (Span::OutOfRangeException &e)
	{
		std::cout << e.what() <<std::endl;
	}

	std::cout << sp.shortestSpan() <<std::endl;
	std::cout << sp.longestSpan() <<std::endl;
	
	Span sp2	= Span(100);
	try
	{
		sp2.addRandomNumber(100);
	}
	catch (Span::OutOfRangeException &e)
	{
		std::cout << e.what() <<std::endl;
	}
	std::cout << sp2;
	std::cout << sp2.shortestSpan() <<std::endl;
	std::cout << sp2.longestSpan() <<std::endl;
}
