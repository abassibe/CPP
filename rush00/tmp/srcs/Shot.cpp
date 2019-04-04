/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shot.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 16:55:07 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/31 17:33:23 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Shot.hpp"

Shot::Shot() : _y(0), _x(0), _damage(0)
{
}

Shot::Shot(int y, int x, int damage) : _y(y), _x(x), _damage(damage)
{
}

Shot::Shot(Shot const& copy) : _y(copy._y), _x(copy._x), _damage(copy._damage)
{
}

Shot::~Shot()
{
}

Shot	&Shot::operator=(Shot const& copy)
{
	_y = copy._y;
	_x = copy._x;
	_damage = copy._damage;
	return (*this);
}

int		Shot::getY() const
{
	return (_y);
}

int		Shot::getX() const
{
	return (_x);
}

int		Shot::getDamage() const
{
	return (_damage);
}

void	Shot::setY(int const& y)
{
	_y = y;
}

void	Shot::setX(int const& x)
{
	_x = x;
}
