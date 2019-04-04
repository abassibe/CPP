/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 04:26:01 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/28 10:41:23 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <thread>
#include <chrono>
#include "FragTrap.hpp"

int		main()
{
	FragTrap f1("ClapTrap_v1");

	f1.meleeAttack("Badass ennemy");
	f1.rangedAttack("Badass ennemy");
	f1.takeDamage(50);
	f1.takeDamage(10);
	f1.takeDamage(40);
	f1.beRepaired(150);
	std::cout << "VaultHunter.EXE !\n";
	std::this_thread::sleep_for(std::chrono::seconds(3));
	f1.vaulthunterDotExe("Badass ennemy");
	std::cout << "\nWAIT ! I'm sure I can do better !\n\n";
	std::this_thread::sleep_for(std::chrono::seconds(3));
	f1.vaulthunterDotExe("Badass ennemy");
	std::cout << "\nNO NO DON'T LEAVE ! This time its the right one !\n\n";
	std::this_thread::sleep_for(std::chrono::seconds(3));
	f1.vaulthunterDotExe("Badass ennemy");
	std::cout << "\nONE MORE TRY !\n\n";
	std::this_thread::sleep_for(std::chrono::seconds(3));
	f1.vaulthunterDotExe("Badass ennemy");
	std::cout << "\nTHE LAST ONE !!\n\n";
	std::this_thread::sleep_for(std::chrono::seconds(3));
	f1.vaulthunterDotExe("Badass ennemy");
	std::cout << "\nOh...Doesn't matters...go one\n\n";
}
