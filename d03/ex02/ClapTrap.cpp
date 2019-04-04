/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 11:13:01 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/28 12:02:31 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
}

ClapTrap::ClapTrap(std::string name) : _hitPoints(100), _maxHitPoints(100),
	_energyPoints(100), _maxEnergyPoints(100), _level(1), _name(name),
	_meleeAttackDamage(30), _rangedAttackDamage(20), _armorDamageReduction(5)
{
	std::cout << "-ClapTrap building done :\n";
	std::cout << "\033[0;3m\t\"Commencing directive three! Uhntssuhntssuhntss--\"\n\n\033[0;0m";
}

ClapTrap::ClapTrap(ClapTrap const& copy) : _hitPoints(copy._hitPoints),
	_maxHitPoints(copy._maxHitPoints), _energyPoints(copy._energyPoints),
	_maxEnergyPoints(copy._maxEnergyPoints), _level(copy._level), _name(copy._name),
	_meleeAttackDamage(copy._meleeAttackDamage), _rangedAttackDamage(copy._rangedAttackDamage),
	_armorDamageReduction(copy._armorDamageReduction)
{
	std::cout << "-ClapTrap copy done :\n";
	std::cout << "\033[0;3m\t\"Commencing directive three! Uhntssuhntssuhntss--\"\n\n\033[0;0m";
}

ClapTrap::~ClapTrap()
{
	std::cout << "\n-ClapTrap destruction done :\n";
	std::cout << "\033[0;3m\t\"Are you god? Am I dead?\"\n\033[0;0m";
}

ClapTrap	&ClapTrap::operator=(ClapTrap const& copy)
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

void	ClapTrap::rangedAttack(std::string const& target) const
{
	if (_hitPoints == 0)
	{
		std::cout << "\033[0;3m\t\"Robot down!\"\n\033[0;0m";
		return ;
	}
	std::cout << "-CL4P-TP \033[0;36m" << _name << "\033[0;0m attacks \033[0;35m"
		<< target << "\033[0;0m at range, causing \033[0;31m"
		<< _rangedAttackDamage << "\033[0;0m points of damage !\n";
	std::cout << "\033[0;3m\t\"Hot potato!\"\n\033[0;0m";
}

void	ClapTrap::meleeAttack(std::string const& target) const
{
	if (_hitPoints == 0)
	{
		std::cout << "\033[0;3m\t\"Robot down!\"\n\033[0;0m";
		return ;
	}
	std::cout << "-CL4P-TP \033[0;36m" << _name << "\033[0;0m attacks \033[0;35m"
		<< target << "\033[0;0m at melee, causing \033[0;31m" << _meleeAttackDamage
		<< "\033[0;0m points of damage !\n";
	std::cout << "\033[0;3m\t\"Take that!\"\n\033[0;0m";
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_armorDamageReduction >= amount)
		return ;
	if (amount - _armorDamageReduction > _hitPoints)
		_hitPoints = 0;
	else
		_hitPoints -= amount - _armorDamageReduction;
	std::cout << _name << " \033[0;36m" << _name << "\033[0;0m received \033[0;31m"
		<< amount - _armorDamageReduction
		<< "\033[0;0m points of damage ! (reduction of " << _armorDamageReduction << " by the armor)\n";
	printStatus();
	std::cout << "\033[0;3m\t\"If only my chassis... weren't made of recycled human body parts! Wahahaha!\"\n\033[0;0m";
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	unsigned int	saveHP;
	saveHP = _hitPoints;
	_hitPoints += amount;
	if (_hitPoints > 100)
		_hitPoints = 100;
	std::cout << _name << " \033[0;36m" << _name << "\033[0;0m has been repaired from \033[0;32m"
		<< _hitPoints - saveHP << "\033[0;0m points !\n";
	printStatus();
	std::cout << "\033[0;3m\t\"Holy crap, that worked?!\"\n\033[0;0m";
}

void	ClapTrap::printStatus() const
{
	if (_hitPoints > _maxHitPoints / 2)
		std::cout << "HP " << _hitPoints << "/" << _maxHitPoints << "  EP " << _energyPoints << "/" << _maxHitPoints << std::endl;
	else if (_hitPoints > _maxHitPoints / 4)
		std::cout << "HP \033[0;33m" << _hitPoints << "\033[0;0m/" << _maxHitPoints
			<< "  EP " << _energyPoints << "/" << _maxHitPoints << std::endl;
	else
		std::cout << "HP \033[0;31m" << _hitPoints << "\033[0;0m/" << _maxHitPoints
			<< "  EP " << _energyPoints << "/" << _maxHitPoints << std::endl;
}
