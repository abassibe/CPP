/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 12:07:53 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/29 12:17:04 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"

Peon::Peon() : Victim()
{
}

Peon::Peon(std::string name) : Victim(name)
{
	std::cout << "Zog zog." <<std::endl;
}

Peon::Peon(Peon const& copy)
{
	_name = copy._name;
}

Peon::~Peon()
{
	std::cout << "Bleuark.." << std::endl;
}

Peon		&Peon::operator=(Peon const& copy)
{
	if (this != &copy)
		_name = copy._name;
	return (*this);
}

void			Peon::getPolymorphed() const
{
	std::cout << _name << " has been turned into a pink pony !" << std::endl;
}

std::ostream	&operator<<(std::ostream &o, Peon const& victim)
{
	o << "I am " << victim.getName() << ", and I like otters !" <<std::endl;
	return (o);
}
