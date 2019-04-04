/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DeepCoreMiner.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 01:02:50 by abassibe          #+#    #+#             */
/*   Updated: 2018/04/10 04:57:47 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "DeepCoreMiner.hpp"

DeepCoreMiner::DeepCoreMiner()
{
}

DeepCoreMiner::DeepCoreMiner(DeepCoreMiner const& copy)
{
	*this = copy;
}

DeepCoreMiner::~DeepCoreMiner()
{
}

DeepCoreMiner		&DeepCoreMiner::operator=(DeepCoreMiner const& copy)
{
	(void)copy;
	return (*this);
}

void				DeepCoreMiner::mine(IAsteroid *target)
{
	std::cout << "* deep deep ... got " << target->beMined(this) << " ! *\n";
}

IMiningLaser		*DeepCoreMiner::clone() const
{
	IMiningLaser *ret = new DeepCoreMiner;
	return (ret);
}
