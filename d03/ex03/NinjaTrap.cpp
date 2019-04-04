/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 12:10:14 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/28 12:26:02 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap() : ClapTrap()
{
}

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 60;
	_maxHitPoints = 60;
	_energyPoints = 120;
	_maxEnergyPoints = 120;
	_level = 1;
	_meleeAttackDamage = 60;
	_rangedAttackDamage = 5;
	_armorDamageReduction = 0;
	std::cout << "-NinjaTrap building done :\n";
	std::cout << "\033[0;3m\t\"Hey everybody! Check out my package!\"\n\n\033[0;0m";
}

NinjaTrap::NinjaTrap(NinjaTrap const& copy) : ClapTrap(copy)
{
	_hitPoints = copy._hitPoints;
	_maxHitPoints = copy._maxHitPoints;
	_energyPoints = copy._energyPoints;
	_maxEnergyPoints = copy._maxEnergyPoints;
	_level = copy._level;
	_meleeAttackDamage = copy._meleeAttackDamage;
	_rangedAttackDamage = copy._rangedAttackDamage;
	_armorDamageReduction = copy._armorDamageReduction;
	std::cout << "-NinjaTrap copy done :\n";
	std::cout << "\033[0;3m\t\"Hey everybody! Check out my package!\"\n\n\033[0;0m";
}

NinjaTrap::~NinjaTrap()
{
	std::cout << "\n-NinjaTrap destruction done :\n";
	std::cout << "\033[0;3m\t\"I can't feel my fingers! Gah! I don't have any fingers!\"\n\033[0;0m";
}

NinjaTrap	&NinjaTrap::operator=(NinjaTrap const& copy)
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

void	NinjaTrap::rangedAttack(std::string const& target) const
{
	if (_hitPoints == 0)
	{
		std::cout << "\033[0;3m\t\"Robot down!\"\n\033[0;0m";
		return ;
	}
	std::cout << "-NINJ4-TP \033[0;36m" << _name << "\033[0;0m attacks \033[0;35m"
		<< target << "\033[0;0m at range, causing \033[0;31m"
		<< _rangedAttackDamage << "\033[0;0m points of damage !\n";
	std::cout << "\033[0;3m\t\"Step right up, to the Bulletnator 9000!\"\n\033[0;0m";
}

void	NinjaTrap::meleeAttack(std::string const& target) const
{
	if (_hitPoints == 0)
	{
		std::cout << "\033[0;3m\t\"Robot down!\"\n\033[0;0m";
		return ;
	}
	std::cout << "-NINJ4-TP \033[0;36m" << _name << "\033[0;0m attacks \033[0;35m"
		<< target << "\033[0;0m at melee, causing \033[0;31m" << _meleeAttackDamage
		<< "\033[0;0m points of damage !\n";
	std::cout << "\033[0;3m\t\"Ha ha ha! Fall before your robot overlord!\"\n\033[0;0m";
}

void	NinjaTrap::ninjaShoebox(ClapTrap const& target)
{
	std::cout << "-NINJ4-TP Activating ninjaShoebox... \n";
	meleeAttack(target.getName());
	std::cout << "Now I will dominate!\n";
}

void	NinjaTrap::ninjaShoebox(FragTrap const& target)
{
	std::cout << "-NINJ4-TP Activating ninjaShoebox... \n";
	meleeAttack(target.getName());
	std::cout << "I am NOT sorry!\n";
}

void	NinjaTrap::ninjaShoebox(ScavTrap const& target)
{
	std::cout << "-NINJ4-TP Activating ninjaShoebox... \n";
	meleeAttack(target.getName());
	std::cout << "Uh... wasn't me!\n";
}

void	NinjaTrap::ninjaShoebox(NinjaTrap const& target)
{
	std::cout << "-NINJ4-TP Activating ninjaShoebox... \n";
	meleeAttack(target.getName());
	std::cout << "I'm so sexy!\n";
}
