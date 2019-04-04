/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 11:31:05 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/29 12:17:25 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

Victim::Victim()
{
}

Victim::Victim(std::string name) : _name(name)
{
	std::cout << "Some random victim called " << _name << " just popped !" <<std::endl;
}

Victim::Victim(Victim const& copy)
{
	_name = copy._name;
}

Victim::~Victim()
{
	std::cout << "Victim " << _name << " just died for no apparent reason !" << std::endl;
}

Victim		&Victim::operator=(Victim const& copy)
{
	if (this != &copy)
		_name = copy._name;
	return (*this);
}

std::string		Victim::getName() const
{
	return (_name);
}

void			Victim::getPolymorphed() const
{
	std::cout << _name << " has been turned into a cute little sheep !" << std::endl;
}

std::ostream	&operator<<(std::ostream &o, Victim const& victim)
{
	o << "I am " << victim.getName() << ", and I like otters !" << std::endl;
	return (o);
}
