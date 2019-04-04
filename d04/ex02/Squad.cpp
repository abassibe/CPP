/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 16:58:41 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/29 18:59:57 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"

Squad::Squad() : _squad(nullptr), _count(0)
{
}

Squad::Squad(Squad const& copy)
{
	for (int i = 0; i < _count; i++)
		delete _squad[i];
	_count = copy._count;
	_squad = new ISpaceMarine*[_count];
	for (int i = 0; i < _count; i++)
		_squad[i] = copy._squad[i];
}

Squad::~Squad()
{
	for (int i = 0; i < _count; i++)
		delete _squad[i];
	delete _squad;
}

Squad	&Squad::operator=(Squad const& copy)
{
	if (this != &copy)
	{
		for (int i = 0; i < _count; i++)
			delete _squad[i];
		delete _squad;
		_count = copy._count;
		_squad = new ISpaceMarine*[_count];
		for (int i = 0; i < _count; i++)
			_squad[i] = copy._squad[i];
	}
	return (*this);
}

int		Squad::getCount() const
{
	return (_count);
}

ISpaceMarine	*Squad::getUnit(int n) const
{
	if (n < 0 || n >= _count)
		return (nullptr);
	return (_squad[n]);
}

int				Squad::push(ISpaceMarine *toAdd)
{
	if (!toAdd)
		return (_count);
	if (!_squad)
	{
		_squad = new ISpaceMarine*[1];
		_squad[0] = toAdd;
		_count = 1;
		return (_count);
	}
	for (int i = 0; i < _count; i++)
		if (&toAdd == &_squad[i])
			return (_count);

	ISpaceMarine	**tmp = new ISpaceMarine*[_count + 1];
	int i = 0;
	while (i < _count)
	{
		tmp[i] = _squad[i];
		i++;
	}
	tmp[i] = toAdd;
	delete _squad;
	_squad = tmp;
	_count++;
	return (_count);
}
