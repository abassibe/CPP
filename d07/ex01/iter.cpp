/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 10:51:14 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/03 11:25:02 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	print(int const& val)
{
	std::cout << val << std::endl;
}

template<typename T>void	iter(T *array, unsigned int length, void (*f)(T const&))
{
	for (unsigned int i = 0; i < length; i++)
		f(array[i]);
}

int		main()
{
	int		array[] = {2, 654 ,5, 4584 ,4 ,415, 84, 5468, 887};


	iter(array, 9, print);
	return (0);
}
