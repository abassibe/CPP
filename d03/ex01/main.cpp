/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 04:26:01 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/28 11:09:28 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <thread>
#include <chrono>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int		main()
{
	FragTrap f1("ClapTrap_v1");
	ScavTrap s1("ScavTrap_v1");

	std::cout << "--------------ClapTrap_v1 turn----------------\n";
	f1.meleeAttack("Badass ennemy");
	f1.rangedAttack("Badass ennemy");
	f1.takeDamage(50);
	f1.takeDamage(10);
	f1.takeDamage(40);
	f1.beRepaired(150);
	std::cout << "VaultHunter.EXE !\n";
	std::this_thread::sleep_for (std::chrono::seconds(3));
	f1.vaulthunterDotExe("Badass ennemy");
	std::cout << "\nWAIT ! I'm sure I can do better !\n\n";
	std::this_thread::sleep_for (std::chrono::seconds(3));
	f1.vaulthunterDotExe("Badass ennemy");
	std::cout << "\nNO NO DON'T LEAVE ! This time its the right one !\n\n";
	std::this_thread::sleep_for (std::chrono::seconds(3));
	f1.vaulthunterDotExe("Badass ennemy");
	std::cout << "\nONE MORE TRY !\n\n";
	std::this_thread::sleep_for (std::chrono::seconds(3));
	f1.vaulthunterDotExe("Badass ennemy");
	std::this_thread::sleep_for (std::chrono::seconds(3));
	f1.vaulthunterDotExe("Badass ennemy");
	std::cout << "\nOh...Doesn't matters...go one\n\n";

	std::cout << "--------------ScavTrap_v1 turn----------------\n";
	s1.meleeAttack("Badass ennemy");
	std::cout << std::endl;
	s1.takeDamage(50);
	std::cout << std::endl;
	s1.takeDamage(10);
	std::cout << std::endl;
	s1.takeDamage(40);
	std::cout << std::endl;
	s1.beRepaired(150);
	std::cout << std::endl;
	std::cout << "challengeNewcomer !\n";
	s1.challengeNewComer();
	std::cout << std::endl;
	std::this_thread::sleep_for (std::chrono::seconds(1));
	std::cout << "challengeNewcomer !\n";
	s1.challengeNewComer();
	std::cout << std::endl;
	std::this_thread::sleep_for (std::chrono::seconds(1));
	std::cout << "challengeNewcomer !\n";
	s1.challengeNewComer();
	std::cout << std::endl;
}
