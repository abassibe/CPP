/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 19:10:37 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/29 19:42:10 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
}

AMateria::AMateria(std::string const& type) : _xp(0), _type(type)
{
}

AMateria::AMateria(AMateria const& copy) : _xp(copy._xp), _type(copy._type)
{
}

AMateria::~AMateria()
{
}

AMateria	&AMateria::operator=(AMateria const& copy)
{
	_xp = copy._xp;
	_type = copy._type;
	return (*this);
}

std::string const	&AMateria::getType() const
{
	return (_type);
}

unsigned int		AMateria::getXP() const
{
	return (_xp);
}

void				AMateria::use(ICharacter &target)
{
	std::cout << "* Use " << _type << " on " << target.getName() << " *" << std::endl;
	_xp += 10;
}
