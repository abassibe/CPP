/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 02:29:14 by abassibe          #+#    #+#             */
/*   Updated: 2018/04/20 05:53:48 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpn.hpp"

int		main(int ac, char **av)
{
	int		i = 0;
	std::string		exp;
	if (ac < 2)
	{
		std::cout << "Usage : Rpn \"expression to calculate...\"\n";
		return (-1);
	}
	while (++i < ac)
	{
		exp = av[i];
		rpn		tst(exp);
		tst.print_token();
	}

}
