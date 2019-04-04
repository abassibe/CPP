/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 13:23:36 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/26 15:56:34 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"
#include "ZombieEvent.hpp"

static const std::string	_name[10] = {"Roger", "Marc", "Ferdinand", "Albert", "Blaise", "Brigitte", "Gertrude", "Francoise", "Monique","Gislene"};

void	randomChump()
{
	std::srand(time(nullptr));

	int randIndex = std::rand() % 3;
	Zombie	randZombie1 = Zombie("Walker", _name[randIndex]);
	randIndex = std::rand() % 6;
	Zombie	randZombie2 = Zombie("Walker", _name[randIndex]);
	randIndex = std::rand() % 10;
	Zombie	randZombie3 = Zombie("Walker", _name[randIndex]);

	std::cout << "thankfully they can't swim..." << std::endl;
}

int		main()
{
	std::cout << "Three walker appear rigth next corner:" << std::endl;
	Zombie zombieWalker1 = Zombie("Walker", "Glenn");
	Zombie zombieWalker2 = Zombie("Walker", "Abraham");
	Zombie zombieWalker3 = Zombie("Walker", "Carl");

	ZombieEvent		event;

	std::cout << "Followed by a sprinter:" << std::endl;
	event.setZombieType("Sprinter");
	Zombie *zombieSprinter = event.newZombie("Michonne");

	std::cout << "and a Boomer:" << std::endl;
	event.setZombieType("Boomer");
	Zombie *zombieBoomer = event.newZombie("Eugene");

	std::cout << "and a lot of random Walker on the other side of the river:" << std::endl;
	randomChump();

	std::cout << std::endl << "Then Rick arrive and save you. Amazing scenario, see you next week." << std::endl;

	delete zombieSprinter;
	delete zombieBoomer;
}
