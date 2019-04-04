/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 09:56:15 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/28 10:35:47 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
}

FragTrap::FragTrap(std::string name) : _hitPoints(100), _maxHitPoints(100),
	_energyPoints(100), _maxEnergyPoints(100), _level(1), _name(name),
	_meleeAttackDamage(30), _rangedAttackDamage(20), _armorDamageReduction(5)
{
	std::cout << "-FragTrap building done :\n";
	std::cout << "\033[0;3m\t\"Directive one: Protect humanity! Directive two: Obey Jack at all costs. Directive three: Dance!\"\n\n\033[0;0m";
}

FragTrap::FragTrap(FragTrap const& copy) : _hitPoints(copy._hitPoints),
	_maxHitPoints(copy._maxHitPoints), _energyPoints(copy._energyPoints),
	_maxEnergyPoints(copy._maxEnergyPoints), _level(copy._level), _name(copy._name),
	_meleeAttackDamage(copy._meleeAttackDamage), _rangedAttackDamage(copy._rangedAttackDamage),
	_armorDamageReduction(copy._armorDamageReduction)
{
	std::cout << "-FragTrap copy done :\n";
	std::cout << "\033[0;3m\t\"Directive one: Protect humanity! Directive two: Obey Jack at all costs. Directive three: Dance!\"\n\n\033[0;0m";
}

FragTrap::~FragTrap()
{
	std::cout << "\n-FragTrap destruction done :\n";
	std::cout << "\033[0;3m\t\"I'M DEAD I'M DEAD OHMYGOD I'M DEAD!\"\n\033[0;0m";
}

FragTrap	&FragTrap::operator=(FragTrap const& copy)
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

void	FragTrap::rangedAttack(std::string const& target) const
{
	if (_hitPoints == 0)
	{
		std::cout << "\033[0;3m\t\"Robot down!\"\n\033[0;0m";
		return ;
	}
	std::cout << "-FR4G-TP \033[0;36m" << _name << "\033[0;0m attacks \033[0;35m"
		<< target << "\033[0;0m at range, causing \033[0;31m"
		<< _rangedAttackDamage << "\033[0;0m points of damage !\n";
	std::cout << "\033[0;3m\t\"Step right up, to the Bulletnator 9000!\"\n\033[0;0m";
}

void	FragTrap::meleeAttack(std::string const& target) const
{
	if (_hitPoints == 0)
	{
		std::cout << "\033[0;3m\t\"Robot down!\"\n\033[0;0m";
		return ;
	}
	std::cout << "-FR4G-TP \033[0;36m" << _name << "\033[0;0m attacks \033[0;35m"
		<< target << "\033[0;0m at melee, causing \033[0;31m" << _meleeAttackDamage
		<< "\033[0;0m points of damage !\n";
	std::cout << "\033[0;3m\t\"Ha ha ha! Fall before your robot overlord!\"\n\033[0;0m";
}

void	FragTrap::takeDamage(unsigned int amount)
{
	if (_armorDamageReduction >= amount)
		return ;
	if (amount - _armorDamageReduction > _hitPoints)
		_hitPoints = 0;
	else
		_hitPoints -= amount - _armorDamageReduction;
	std::cout << "-FR4G-TP \033[0;36m" << _name << "\033[0;0m received \033[0;31m"
		<< amount - _armorDamageReduction
		<< "\033[0;0m points of damage ! (reduction of " << _armorDamageReduction << " by the armor)\n";
	printStatus();
	std::cout << "\033[0;3m\t\"If only my chassis... weren't made of recycled human body parts! Wahahaha!\"\n\033[0;0m";
}

void	FragTrap::beRepaired(unsigned int amount)
{
	unsigned int	saveHP;
	saveHP = _hitPoints;
	_hitPoints += amount;
	if (_hitPoints > 100)
		_hitPoints = 100;
	std::cout << "-FR4G-TP \033[0;36m" << _name << "\033[0;0m has been repaired from \033[0;32m"
		<< _hitPoints - saveHP << "\033[0;0m points !\n";
	printStatus();
	std::cout << "\033[0;3m\t\"Holy crap, that worked?!\"\n\033[0;0m";
}

void	FragTrap::printStatus() const
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

void	FragTrap::vaulthunterDotExe(std::string const& target)
{
	if (_energyPoints < 25)
	{
		std::cout << "\033[0;3m\t\"Is it warm in here, or is it just me?\"\n\033[0;0m";
		return ;
	}
	_energyPoints -= 25;
	std::string		tab[10] = {"This time it'll be awesome, I promise!", "Recompiling my combat code!",
		"It's happening... it's happening!", "You can't just program this level of excitement!",
		"Let's get this party started!", "Glitchy weirdness is term of endearment, right?",
		"Push this button, flip this dongle, voila! Help me!", "F to the R to the 4 to the G to the WHAAT!",
		"It's like a box of chocolates...", "Look out everybody, things are about to get awesome!"};
	srand(time(nullptr));
	std::cout << "-FR4G-TP Activating VaultHunter.EXE... (EP " << _energyPoints << "/" << _maxHitPoints << ")\n";
	std::cout << "-FR4G-TP \033[0;36m" << _name << "\033[0;0m attacks \033[0;35m" << target << "\033[0;0m with random attacks, causing \033[0;31m" << rand() % 100 << "\033[0;0m points of damage !\n";
	std::cout << "\033[0;3m\t\""<< tab[rand() % 10] <<"\"\n\033[0;0m";
}
