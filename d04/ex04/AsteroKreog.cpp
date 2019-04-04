/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AsteroKreog.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 01:23:00 by abassibe          #+#    #+#             */
/*   Updated: 2018/04/10 04:46:21 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "AsteroKreog.hpp"

AsteroBocal::AsteroBocal()
{
}

AsteroBocal::AsteroBocal(AsteroBocal const& copy)
{
	(void) copy;
	*this = copy;
}

AsteroBocal::~AsteroBocal()
{
}

AsteroBocal		&AsteroBocal::operator=(AsteroBocal const& copy)
{
	(void)copy;
	return (*this);
}

std::string		AsteroBocal::beMined(DeepCoreMiner *laser) const
{
	(void)laser;
	return ("Thorite");
}

std::string		AsteroBocal::beMined(StripMiner *laser) const
{
	(void)laser;
	return ("Flavium");
}

std::string		AsteroBocal::getName() const
{
	return ("AsteroBocal");
}
