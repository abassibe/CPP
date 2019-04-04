/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deserialize.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 04:05:57 by abassibe          #+#    #+#             */
/*   Updated: 2018/04/13 04:51:58 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <ctime>
#include <climits>
#include <iostream>

void	*serialize(void)
{
	srand(time(nullptr));
	char	*str = new char[20];
	char	alnum[63] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
	int		i = 0;

	while (i < 8)
	{
		str[i] = alnum[rand() % 62];
		i++;
	}
	*(reinterpret_cast<int *>(&str[8])) = rand();
	i = 12;
	while (i < 20)
	{
		str[i] = alnum[rand() % 62];
		i++;
	}
	return (reinterpret_cast<void *>(str));
}

Data	*deserialize(void *raw)
{
	Data	*data = new Data;

	data->s1.assign(reinterpret_cast<char *>(raw), 8);
	data->n = *reinterpret_cast<int *>(&reinterpret_cast<char *>(raw)[8]);
	data->s2.assign(&reinterpret_cast<char *>(raw)[12], 8);
	return (data);
}
