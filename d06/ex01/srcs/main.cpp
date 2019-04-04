/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 04:05:30 by abassibe          #+#    #+#             */
/*   Updated: 2018/04/13 04:43:57 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Data.hpp"

int		main()
{
	void	*raw;
	Data	*data;

	raw = serialize();
	data = deserialize(raw);
	std::cout << "S1 = \"" << data->s1 << "\"\nn = " << data->n << "\nS2 = \"" << data->s2 << "\"\n";
	return (0);
}
