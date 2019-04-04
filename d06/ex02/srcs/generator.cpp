/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 05:17:12 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/02 12:59:42 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>
#include "Base.hpp"

Base	*generator()
{
	srand(time(nullptr));
	int		random = rand() % 3;
	Base	*ret;

	switch (random)
	{
		case 0:
			ret = new A();
			break;
		case 1:
		ret = new B();
			break;
		case 2:
		ret = new C();
			break;
	}
	return (ret);
}

void	identify_from_pointer(Base *p)
{
	A	*testA;
	B	*testB;
	C	*testC;

	if ((testA = dynamic_cast<A *>(p)))
		std::cout << "A\n";
	else if ((testB = dynamic_cast<B *>(p)))
		std::cout << "B\n";
	else if ((testC = dynamic_cast<C *>(p)))
		std::cout << "C\n";
}

void	identify_from_reference(Base &p)
{
	try
	{
		A	&testA = dynamic_cast<A &> (p);
		(void)testA;
		std::cout << "A\n";
		return ;
	}
	catch (std::bad_cast)
	{
		;
	}

	try
	{
		B	&testB = dynamic_cast<B &> (p);
		(void)testB;
		std::cout << "B\n";
	}
	catch (std::bad_cast)
	{
		;
	}

	try
	{
		C	&testC = dynamic_cast<C &> (p);
		(void)testC;
		std::cout << "C\n";
	}
	catch (std::bad_cast)
	{
		;
	}
}
