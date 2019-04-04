/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 03:31:01 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/26 19:52:48 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

void	print_si()
{
	std::string		tmp;
	do
	{
		std::cin >> tmp;
		if (std::cin.eof())
			exit (0);
		std::cout << tmp << '\n';
	}
	while (1);
}

void	print_file(int ac, char **av)
{
	std::ifstream	ifs;
	std::string		tmp;

	for (int i = 1; i < ac; i++)
	{
		ifs.open(av[i]);
		if (ifs.is_open())
		{
			while (std::getline(ifs, tmp))
				std::cout << tmp << '\n';
			ifs.close();
		}
		else
			std::cout << "cat o' nine tails: " << av[i] << ": No such file or directory" << std::endl;
	}
}

int		main(int ac, char **av)
{
	if (ac == 1)
		print_si();
	else
		print_file(ac, av);
}
