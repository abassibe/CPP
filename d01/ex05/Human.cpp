/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 17:29:07 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/26 17:46:42 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human() : _brain(Brain())
{
}

Human::~Human()
{
}

std::string		Human::identify() const
{
	return (_brain.identify());
}

const Brain		&Human::getBrain() const
{
	return (_brain);
}
