/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 04:26:01 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/28 12:27:33 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <thread>
#include <chrono>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

int		main()
{
	ClapTrap f1("ClapTrap_v1");
	FragTrap f2("FragTrap_v1");
	ScavTrap f3("ScavTrap_v1");
	NinjaTrap s1("NinjaTrap_v1");

	std::cout << "--------------ClapTrap_v1 turn----------------\n";
	f1.meleeAttack("Badass ennemy");
	f1.rangedAttack("Badass ennemy");
	f1.takeDamage(50);
	f1.takeDamage(10);
	f1.takeDamage(40);
	f1.beRepaired(150);
	std::cout << "--------------FragTrap_v1 turn----------------\n";
	std::cout << "VaultHunter.EXE !\n";
	std::this_thread::sleep_for (std::chrono::seconds(3));
	f2.vaulthunterDotExe("Badass ennemy");
	std::cout << "\nWAIT ! I'm sure I can do better !\n\n";
	std::this_thread::sleep_for (std::chrono::seconds(3));
	f2.vaulthunterDotExe("Badass ennemy");
	std::cout << "\nNO NO DON'T LEAVE ! This time its the right one !\n\n";
	std::this_thread::sleep_for (std::chrono::seconds(3));
	f2.vaulthunterDotExe("Badass ennemy");
	std::cout << "\nONE MORE TRY !\n\n";
	std::this_thread::sleep_for (std::chrono::seconds(3));
	f2.vaulthunterDotExe("Badass ennemy");
	std::this_thread::sleep_for (std::chrono::seconds(3));
	f2.vaulthunterDotExe("Badass ennemy");
	std::cout << "\nOh...Doesn't matters...go one\n\n";

	std::cout << "--------------ScavTrap_v1 turn----------------\n";
	f3.meleeAttack("Badass ennemy");
	f3.rangedAttack("Badass ennemy");
	f3.takeDamage(50);
	f3.takeDamage(10);
	f3.takeDamage(40);
	f3.beRepaired(150);
	std::cout << "challengeNewcomer !\n";
	f3.challengeNewComer();

	std::cout << "--------------NinjaTrap_v1 turn----------------\n";
	s1.ninjaShoebox(f1);
	s1.ninjaShoebox(f2);
	s1.ninjaShoebox(f3);
	s1.ninjaShoebox(s1);
}
