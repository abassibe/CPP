/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 17:12:57 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/26 17:42:54 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() : synapse(1), neuron(2)
{
}

Brain::~Brain()
{
}

std::string		Brain::identify() const
{
/*	std::stringstream		address;
	address << &(*this);
	return (address.str());*/
	std::string		ret;
	std::stringstream	ss;
	const void* a = this;

	ss<< a;
	ret.append(ss.str());
	return (ret);
}
