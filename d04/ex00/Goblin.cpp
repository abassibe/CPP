/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Goblin.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 12:07:53 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/29 12:25:15 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Goblin.hpp"

Goblin::Goblin() : Victim()
{
}

Goblin::Goblin(std::string name) : Victim(name)
{
	std::cout << "Niark niark." <<std::endl;
}

Goblin::Goblin(Goblin const& copy)
{
	_name = copy._name;
}

Goblin::~Goblin()
{
	std::cout << "Aaaargh.." << std::endl;
}

Goblin		&Goblin::operator=(Goblin const& copy)
{
	if (this != &copy)
		_name = copy._name;
	return (*this);
}

void			Goblin::getPolymorphed() const
{
	std::cout << _name << " has been turned into a gnome !" << std::endl;
}

std::ostream	&operator<<(std::ostream &o, Goblin const& victim)
{
	o << "I am " << victim.getName() << ", and I like gold !" <<std::endl;
	return (o);
}
