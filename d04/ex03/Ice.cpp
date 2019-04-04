/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 19:20:24 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/29 19:42:20 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(Ice const& copy) : AMateria(copy)
{
}

Ice::~Ice()
{
}

Ice	&Ice::operator=(Ice const& copy)
{
	_xp = copy._xp;
	return (*this);
}

std::string const	&Ice::getType() const
{
	return (_type);
}

unsigned int		Ice::getXP() const
{
	return (_xp);
}

Ice					*Ice::clone() const
{
	return (new Ice(*this));
}

void				Ice::use(ICharacter &target)
{
	std::cout <<"* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	_xp += 10;
}
