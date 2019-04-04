/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 19:27:40 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/29 19:42:17 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(Cure const& copy) : AMateria(copy)
{
}

Cure::~Cure()
{
}

Cure	&Cure::operator=(Cure const& copy)
{
	_xp = copy._xp;
	return (*this);
}

std::string const	&Cure::getType() const
{
	return (_type);
}

unsigned int		Cure::getXP() const
{
	return (_xp);
}

Cure					*Cure::clone() const
{
	return (new Cure(*this));
}

void				Cure::use(ICharacter &target)
{
	std::cout <<"* heals " << target.getName() << "’s wounds *" << std::endl;
	_xp += 10;
}
