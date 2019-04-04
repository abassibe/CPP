/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 09:56:15 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/28 12:01:41 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_maxHitPoints = 100;
	_energyPoints = 50;
	_maxEnergyPoints = 50;
	_level = 1;
	_meleeAttackDamage = 20;
	_rangedAttackDamage = 15;
	_armorDamageReduction = 3;
	std::cout << "-ScavTrap building done :\n";
	std::cout << "\033[0;3m\t\"Hey everybody! Check out my package!\"\n\n\033[0;0m";
}

ScavTrap::ScavTrap(ScavTrap const& copy) : ClapTrap(copy)
{
	_hitPoints = copy._hitPoints;
	_maxHitPoints = copy._maxHitPoints;
	_energyPoints = copy._energyPoints;
	_maxEnergyPoints = copy._maxEnergyPoints;
	_level = copy._level;
	_meleeAttackDamage = copy._meleeAttackDamage;
	_rangedAttackDamage = copy._rangedAttackDamage;
	_armorDamageReduction = copy._armorDamageReduction;
	std::cout << "-ScavTrap copy done :\n";
	std::cout << "\033[0;3m\t\"Hey everybody! Check out my package!\"\n\n\033[0;0m";
}

ScavTrap::~ScavTrap()
{
	std::cout << "\n-ScavTrap destruction done :\n";
	std::cout << "\033[0;3m\t\"Why do I even feel pain?!\"\n\033[0;0m";
}

ScavTrap	&ScavTrap::operator=(ScavTrap const& copy)
{
	_hitPoints = copy._hitPoints;
	_maxHitPoints = copy._maxHitPoints;
	_energyPoints = copy._energyPoints;
	_maxEnergyPoints = copy._maxEnergyPoints;
	_level = copy._level;
	_name = copy._name;
	_meleeAttackDamage = copy._meleeAttackDamage;
	_rangedAttackDamage = copy._rangedAttackDamage;
	_armorDamageReduction = copy._armorDamageReduction;
	return (*this);
}

void	ScavTrap::rangedAttack(std::string const& target) const
{
	if (_hitPoints == 0)
	{
		std::cout << "\033[0;3m\t\"Robot down!\"\n\033[0;0m";
		return ;
	}
	std::cout << "-SC4V-TP \033[0;36m" << _name << "\033[0;0m attacks \033[0;35m"
		<< target << "\033[0;0m at range, causing \033[0;31m"
		<< _rangedAttackDamage << "\033[0;0m points of damage !\n";
	std::cout << "\033[0;3m\t\"I am a tornado of death and bullets!\"\n\033[0;0m";
}

void	ScavTrap::meleeAttack(std::string const& target) const
{
	if (_hitPoints == 0)
	{
		std::cout << "\033[0;3m\t\"Robot down!\"\n\033[0;0m";
		return ;
	}
	std::cout << "-SC4V-TP \033[0;36m" << _name << "\033[0;0m attacks \033[0;35m"
		<< target << "\033[0;0m at melee, causing \033[0;31m" << _meleeAttackDamage
		<< "\033[0;0m points of damage !\n";
	std::cout << "\033[0;3m\t\"Don't tell me that wasn't awesome!\"\n\033[0;0m";
}

void	ScavTrap::challengeNewComer()
{
	if (_energyPoints < 25)
	{
		std::cout << "\033[0;3m\t\"Is it warm in here, or is it just me?\"\n\033[0;0m";
		return ;
	}
	_energyPoints -= 25;
	std::string		tab[5] = {"You versus me! Me versus you! Either way!", "I will prove to you my robotic superiority!",
		"Dance battle! Or, you know... regular battle.", "Man versus machine! Very tiny streamlined machine!",
		"Care to have a friendly duel?"};
	std::string		challenger[5] = {"Trash feeder", "Crab worm lavae",
		"Mulciber Mk2", "Crimson lance", "Sera guardian"};
	srand(time(nullptr));
	std::cout << "-SC4V-TP Activating challengeNewcomer... (EP " << _energyPoints << "/" << _maxEnergyPoints << ")\n";
	std::cout << "\033[0;3m\t\""<< tab[rand() % 5] <<"\"\n\033[0;0m";
	meleeAttack(challenger[rand() % 5]);
}
