/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StripMiner.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 01:02:50 by abassibe          #+#    #+#             */
/*   Updated: 2018/04/10 04:48:29 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "StripMiner.hpp"

StripMiner::StripMiner()
{
}

StripMiner::StripMiner(StripMiner const& copy)
{
	(void)copy;
}

StripMiner::~StripMiner()
{
}

StripMiner	&StripMiner::operator=(StripMiner const& copy)
{
	(void)copy;
	return (*this);
}

void			StripMiner::mine(IAsteroid *target)
{
	std::cout << "* strip mining ... got " << target->beMined(this) << " ! *\n";
}

IMiningLaser	*StripMiner::clone() const
{
	IMiningLaser *ret = new StripMiner;
	return (ret);
}
