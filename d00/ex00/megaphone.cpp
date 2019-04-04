/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 00:24:48 by abassibe          #+#    #+#             */
/*   Updated: 2018/03/21 00:48:29 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	to_uper_case(char **str)
{
	int		i;

	i = -1;
	while (str[0][++i])
		if (str[0][i] > 96 && str[0][i] < 123)
			str[0][i] -= 32;
}

int		main(int ac, char **av)
{
	int		i;

	i = 0;
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (++i < ac)
	{
		to_uper_case(&av[i]);
		std::cout << av[i];
	}
	std::cout << std::endl;
	return 1;
}
