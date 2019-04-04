/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiningBarge.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 01:45:58 by abassibe          #+#    #+#             */
/*   Updated: 2018/04/10 05:05:29 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MiningBarge.hpp"

MiningBarge::MiningBarge()
{
	_laser[0] = nullptr;
	_laser[1] = nullptr;
	_laser[2] = nullptr;
	_laser[3] = nullptr;
}

MiningBarge::MiningBarge(MiningBarge const& copy)
{
	int		i = 0;

	while (i < 4)
	{
		if (copy._laser[i])
			_laser[i] = copy._laser[i]->clone();
		else
			_laser[i] = nullptr;
		i++;
	}
}

MiningBarge::~MiningBarge()
{
	int		i = 0;

	while (i < 4 && _laser[i])
	{
		delete _laser[i];
		i++;
	}
}

MiningBarge		&MiningBarge::operator=(MiningBarge const& copy)
{
	int		i = 0;

	if (this != &copy)
	{
		while (i < 4)
		{
			if (copy._laser[i])
				_laser[i] = copy._laser[i]->clone();
			else
				_laser[i] = nullptr;
			i++;
		}
	}
	return (*this);
}

void			MiningBarge::equip(IMiningLaser *laser)
{
	int		i = 0;

	while (_laser[i])
		i++;
	if (i < 4)
		_laser[i] = laser;
}

void			MiningBarge::mine(IAsteroid *target) const
{
	int		i = 0;
	while (i < 4 && _laser[i])
	{
		_laser[i]->mine(target);
		i++;
	}
}
