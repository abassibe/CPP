/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 20:10:31 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/29 20:23:59 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	_materia[0] = nullptr;
	_materia[1] = nullptr;
	_materia[2] = nullptr;
	_materia[3] = nullptr;
}

MateriaSource::MateriaSource(MateriaSource const& copy)
{
	for (int i = 0; i < 4; i++)
	{
		if (copy._materia[i] == nullptr)
			break ;
		_materia[i] = copy._materia[i]->clone();
	}
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (_materia[i] == nullptr)
			break ;
		delete _materia[i];
	}
}

MateriaSource	&MateriaSource::operator=(MateriaSource const& copy)
{
	for (int i = 0; i < 4; i++)
	{
		if (copy._materia[i] == nullptr)
			break ;
		_materia[i] = copy._materia[i]->clone();
	}
	return (*this);
}

void			MateriaSource::learnMateria(AMateria *m)
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

AMateria		*MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_materia[i] == nullptr)
			break ;
		if (type == _materia[i]->getType())
			return (_materia[i]->clone());
	}
	return (0);
}
