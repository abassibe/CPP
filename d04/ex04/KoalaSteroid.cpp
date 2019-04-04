/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   KoalaSteroid.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 01:23:00 by abassibe          #+#    #+#             */
/*   Updated: 2018/04/10 05:03:11 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "KoalaSteroid.hpp"

BocalSteroid::BocalSteroid()
{
}

BocalSteroid::BocalSteroid(BocalSteroid const& copy)
{
	(void)copy;
}

BocalSteroid::~BocalSteroid()
{
}

BocalSteroid		&BocalSteroid::operator=(BocalSteroid const& copy)
{
	(void)copy;
	return (*this);
}

std::string		BocalSteroid::beMined(DeepCoreMiner *laser) const
{
	(void)laser;
	return ("Zazium");
}

std::string		BocalSteroid::beMined(StripMiner *laser) const
{
	(void)laser;
	return ("Krpite");
}

std::string		BocalSteroid::getName() const
{
	return ("BocalSteroid");
}
