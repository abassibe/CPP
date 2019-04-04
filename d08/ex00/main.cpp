/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 12:55:17 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/03 14:02:13 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <deque>
#include <vector>
#include <iostream>
#include "easyfind.hpp"

int		main()
{
	{
		try
		{
			int				test[10] = {54, 4, 56, 564, 6548, 4869, 54, 1, 21, 54};
			std::list<int>	list(test, test + 10);

			std::cout << easyfind(list, 4) << std::endl;;
		}
		catch (std::logic_error &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		try
		{
			int					test[10] = {54, 4, 56, 564, 6548, 4869, 54, 1, 21, 54};
			std::deque<int>		list(test, test + 10);

			std::cout << easyfind(list, 564) << std::endl;;
		}
		catch (std::logic_error &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		try
		{
			int					test[10] = {54, 4, 56, 564, 6548, 4869, 54, 1, 21, 54};
			std::vector<int>		list(test, test + 10);

			std::cout << easyfind(list, 21) << std::endl;;
		}
		catch (std::logic_error &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
