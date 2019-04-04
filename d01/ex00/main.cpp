/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 12:22:13 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/26 13:09:22 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Pony.hpp"

void	ponyOnTheStack()
{
	std::cout << "Creation of ponyStack" << std::endl;
	Pony	ponyStack;
	std::cout << "Destruction of ponyStack" << std::endl;
}

void	ponyOnTheHeap()
{
	std::cout << "Creation of ponyHeap" << std::endl;
	Pony	*ponyHeap = new Pony();
	std::cout << "Destruction of ponyHeap" << std::endl;
	delete ponyHeap;
}

int		main()
{
	ponyOnTheStack();
	ponyOnTheHeap();
	return (0);
}
