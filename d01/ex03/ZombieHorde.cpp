/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:23:18 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/26 17:01:48 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ZombieHorde.hpp"

static const std::string	name[10] = {"Roger", "Marc", "Ferdinand", "Albert", "Blaise", "Brigitte", "Gertrude", "Francoise", "Monique","Gislene"};

ZombieHorde::ZombieHorde(int n) : _n(n)
{
	zombies = new Zombie[n];
	std::srand(time(nullptr));

	for (int i = 0; i < n; i++)
	{
		int randIndex = std::rand() % 10;
		zombies[i].type = "Walker";
		zombies[i].name = name[randIndex];
	}
}

ZombieHorde::~ZombieHorde()
{
	delete []zombies;
}

void	ZombieHorde::announce()
{
	for (int i = 0; i < _n; i++)
		zombies[i].announce();
}
