/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 18:40:38 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/26 18:51:35 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int		main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "The program required one file and two string." << std::endl;
		return (0);
	}
	std::ifstream	ifs(av[1]);
	if (!ifs.is_open())
	{
		std::cout << "Can't open the file: " << av[1] << std::endl;
		return (0);
	}
	if (!av[2][0] || !av[3][0])
	{
		std::cout << "Not enough arguments in one of the string." << std::endl;
		return (0);
	}
	std::string		s1 = av[2];
	std::string		s2 = av[3];
	std::string		buff;
	std::string		tmp;
	while (std::getline(ifs, tmp))
	{
		buff.append(tmp);
		buff.append("\n");
	}
	ifs.close();
	while (buff.find(s1) != std::string::npos)
		buff.replace(buff.find(s1),s1.length(),s2);
	std::string		replace = ".replace";
	std::ofstream	ofs(av[1] + replace);
	ofs << buff;
	ofs.close();
}
