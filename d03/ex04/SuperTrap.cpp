/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 09:56:15 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/28 13:25:37 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

SuperTrap::SuperTrap() : FragTrap(), NinjaTrap()
{
}

SuperTrap::SuperTrap(std::string name) : ClapTrap(name), FragTrap(name), NinjaTrap(name)
{
	_hitPoints = 100;
	_maxHitPoints = 100;
	_energyPoints = 120;
	_maxEnergyPoints = 120;
	_level = 1;
	_meleeAttackDamage = 60;
	_rangedAttackDamage = 20;
	_armorDamageReduction = 5;
	std::cout << "-SuperTrap building done :\n";
	std::cout << "\033[0;3m\t\"Directive one: Protect humanity! Directive two: Obey Jack at all costs. Directive three: Dance!\"\n\n\033[0;0m";
}

SuperTrap::SuperTrap(SuperTrap const& copy) : FragTrap(copy), NinjaTrap(copy)
{
	_hitPoints = copy._hitPoints;
	_maxHitPoints = copy._maxHitPoints;
	_energyPoints = copy._energyPoints;
	_maxEnergyPoints = copy._maxEnergyPoints;
	_level = copy._level;
	_meleeAttackDamage = copy._meleeAttackDamage;
	_rangedAttackDamage = copy._rangedAttackDamage;
	_armorDamageReduction = copy._armorDamageReduction;
	std::cout << "-SuperTrap copy done :\n";
	std::cout << "\033[0;3m\t\"Directive one: Protect humanity! Directive two: Obey Jack at all costs. Directive three: Dance!\"\n\n\033[0;0m";
}

SuperTrap::~SuperTrap()
{
	std::cout << "\n-SuperTrap destruction done :\n";
	std::cout << "\033[0;3m\t\"I'M DEAD I'M DEAD OHMYGOD I'M DEAD!\"\n\033[0;0m";
}

SuperTrap	&SuperTrap::operator=(SuperTrap const& copy)
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
