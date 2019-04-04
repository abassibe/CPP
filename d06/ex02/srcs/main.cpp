/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 05:28:47 by abassibe          #+#    #+#             */
/*   Updated: 2018/04/13 06:18:51 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Base.hpp"

int		main()
{
	Base	*testA = new A();
	Base	*testB = new B();
	Base	*testC = new C();
	Base	*testRandom = generator();;

	std::cout << "*****Identify form pointer*****\n";
	identify_from_pointer(testA);
	identify_from_pointer(testB);
	identify_from_pointer(testC);
	identify_from_pointer(testRandom);

	std::cout << "\n*****Identify form pointer*****\n";
	identify_from_reference(*testA);
	identify_from_reference(*testB);
	identify_from_reference(*testC);
	identify_from_reference(*testRandom);
}
