/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 19:46:17 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/29 20:29:17 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
}

Character::Character(Character const& copy) : _name(copy._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (copy._materia[i] == nullptr)
			break ;
		_materia[i] = copy._materia[i]->clone();
	}
}

Character::Character(std::string name) : _name(name)
{
	_materia[0] = nullptr;
	_materia[1] = nullptr;
	_materia[2] = nullptr;
	_materia[3] = nullptr;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_materia[i] == nullptr)
			break ;
		delete _materia[i];
	}
}

Character			&Character::operator=(Character const& copy)
{
	_name = copy._name;
	for (int i = 0; i < 4; i++)
	{
		if (_materia[i] != nullptr)
			delete _materia[i];
		_materia[i] = copy._materia[i]->clone();
	}
	return (*this);
}

std::string const	&Character::getName() const
{
	return (_name);
}

void				Character::equip(AMateria *m)
{
	if (m == nullptr)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (_materia[i] == nullptr)
		{
			_materia[i] = m;
			break;
		}
		if (&m == &_materia[i])
			return ;
	}
}

void				Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return ;
	while (idx < 4)
	{
		if (idx == 3)
		{
			_materia[idx] = nullptr;
			break;
		}
		_materia[idx] = _materia[idx + 1];
		idx++;
	}
}

void				Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3)
		return ;
	if (_materia[idx] != nullptr)
		_materia[idx]->use(target);
}
