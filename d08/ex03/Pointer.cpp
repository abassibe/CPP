/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pointer.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:23:40 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/03 17:24:17 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pointer.hpp"

PointerIncrement::PointerIncrement()
{}

PointerIncrement::PointerIncrement(PointerIncrement const& copy)
{
	(void)copy;
}

PointerIncrement::~PointerIncrement()
{}

PointerIncrement	&PointerIncrement::operator=(PointerIncrement const& copy)
{
	(void)copy;
	return (*this);
}

int					PointerIncrement::execut(char *&tab, std::string buff, int &i) const
{
	(void)buff;
	(void)i;
	tab++;
	return (-1);
}

PointerDecrement::PointerDecrement()
{}

PointerDecrement::PointerDecrement(PointerDecrement const& copy)
{
	(void)copy;
}

PointerDecrement::~PointerDecrement()
{}

PointerDecrement	&PointerDecrement::operator=(PointerDecrement const& copy)
{
	(void)copy;
	return (*this);
}

int					PointerDecrement::execut(char *&tab, std::string buff, int &i) const
{
	(void)buff;
	(void)i;
	tab--;
	return (-1);
}
