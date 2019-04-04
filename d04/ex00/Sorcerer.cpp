/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 11:00:38 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/29 12:17:14 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

Sorcerer::Sorcerer()
{
}

Sorcerer::Sorcerer(std::string name, std::string title) : _name(name), _title(title)
{
	std::cout << _name << ", " << _title << ", is born !" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const& copy)
{
	_name = copy._name;
	_title = copy._title;
}

Sorcerer::~Sorcerer()
{
	std::cout << _name << ", " << _title << ", is dead. Consequences will never be the same !" << std::endl;
}

Sorcerer	&Sorcerer::operator=(Sorcerer const& copy)
{
	if (this != &copy)
	{
		_name = copy._name;
		_title = copy._title;
	}
	return (*this);
}

std::string		Sorcerer::getName() const
{
	return (_name);
}

std::string		Sorcerer::getTitle() const
{
	return (_title);
}

void			Sorcerer::polymorph(Victim const& victim) const
{
	victim.getPolymorphed();
}

std::ostream	&operator<<(std::ostream &o, Sorcerer const& sorcerer)
{
	o << "I am " << sorcerer.getName() << ", " << sorcerer.getTitle() << ", and I like ponies !" << std::endl;
	return (o);
}
