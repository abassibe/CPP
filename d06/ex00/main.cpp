/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 02:21:49 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/02 12:50:01 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <math.h>
#include <exception>
#include <iostream>

int		main(int ac, char **av)
{
	std::string		value;
	char			a;
	int				b;
	float			c;
	double			d;
	char			*endPtr = 0;

	if (ac != 2)
		return (0);
	value = av[1];
	std::cout << "char: ";
	a = static_cast<char>(std::atoi(av[1]));
	if (errno)
		std::cout << "impossible\n";
	else if (isprint(a))
		std::cout << '\'' << a << '\'' << std::endl;
	else
		std::cout << "Charactere non affichable\n";
	std::cout << "int: ";
	const long longval = std::strtol(av[1], &endPtr, 10);
	b = static_cast<int>(std::atoi(av[1]));
	if (errno)
		std::cout << "impossible\n";
	else if (longval >= -2147483648 && longval <= 2147483647)
		std::cout << b << std::endl;
	else
		std::cout << "Overflow\n";
	std::cout << "float: ";
	c = static_cast<float>(std::atof(av[1]));
	if (!std::strcmp(av[1], "inf"))
		std::cout << "inff\n";
	else if (!std::strcmp(av[1], "-inf"))
		std::cout << "-inff\n";
	else if (errno)
		std::cout << "impossible\n";
	else
		std::cout << c << std::endl;
	std::cout << "double: ";
	d = static_cast<double>(std::strtod(av[1], nullptr));
	if (!std::strcmp(av[1], "inf"))
		std::cout << "inf\n";
	else if (!std::strcmp(av[1], "-inf"))
		std::cout << "-inf\n";
	else if (errno)
		std::cout << "impossible\n";
	else
		std::cout << d << std::endl;
}
