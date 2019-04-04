/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Value.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:25:51 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/03 17:26:02 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Value.hpp"

ValueIncrement::ValueIncrement()
{}

ValueIncrement::ValueIncrement(ValueIncrement const& copy)
{
	(void)copy;
}

ValueIncrement::~ValueIncrement()
{}

ValueIncrement	&ValueIncrement::operator=(ValueIncrement const& copy)
{
	(void)copy;
	return (*this);
}

int				ValueIncrement::execut(char *&tab, std::string buff, int &i) const
{
	(void)buff;
	(void)i;
	(*tab)++;
	return (-1);
}

ValueDecrement::ValueDecrement()
{}

ValueDecrement::ValueDecrement(ValueDecrement const& copy)
{
	(void)copy;
}

ValueDecrement::~ValueDecrement()
{}

ValueDecrement	&ValueDecrement::operator=(ValueDecrement const& copy)
{
	(void)copy;
	return (*this);
}

int				ValueDecrement::execut(char *&tab, std::string buff, int &i) const
{
	(void)buff;
	(void)i;
	(*tab)--;
	return (-1);
}

