/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:17:43 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/29 16:20:58 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
}

Character::Character(Character const& copy)
{
	_name = copy._name;
	_weapon = copy._weapon;
	_ap = copy._ap;
}

Character::Character(std::string const& name) : _name(name)
{
	_weapon = nullptr;
	_ap = 40;
}

Character::~Character()
{
}

Character	&Character::operator=(Character const& copy)
{
	if (this != &copy)
	{
		_name = copy._name;
	}
	return (*this);
}

void		Character::recoverAP()
{
	_ap += 10;
	if (_ap > 40)
		_ap = 40;
}

void		Character::equip(AWeapon *weapon)
{
	_weapon = weapon;
}

void		Character::attack(Enemy *enemy)
{
	if (_weapon == nullptr || enemy == nullptr ||  _ap - _weapon->getAPCost() < 0)
		return ;
	std::cout << _name <<  " attacks " << enemy->getType() << " with a " << _weapon->getName() << "." << std::endl;
	_weapon->attack();
	enemy->takeDamage(_weapon->getDamage());
	_ap -= _weapon->getAPCost();
	if (enemy->getHP() <= 0)
		delete (enemy);
}

std::string		Character::getName() const
{
	return (_name);
}
std::string		Character::getWeaponName() const
{
	if (_weapon != nullptr)
		return (_weapon->getName());
	return ("null");
}

int				Character::getAP() const
{
	return (_ap);
}

std::ostream	&operator<<(std::ostream &o, Character const& character)
{
	if (character.getWeaponName() != "null")
		o << character.getName() << " has " << character.getAP() << " AP and wields a " << character.getWeaponName() << "." << std::endl;
	else
		o << character.getName() << " has " << character.getAP() << " AP and is unarmed." << std::endl;
	return (o);
}
