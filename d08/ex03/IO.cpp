/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IO.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:27:28 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/03 17:27:38 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IO.hpp"

PrintValue::PrintValue()
{}

PrintValue::PrintValue(PrintValue const& copy)
{
	(void)copy;
}

PrintValue::~PrintValue()
{}

PrintValue	&PrintValue::operator=(PrintValue const& copy)
{
	(void)copy;
	return (*this);
}

int			PrintValue::execut(char *&tab, std::string buff, int &i) const
{
	(void)buff;
	(void)i;
	std::cout << *tab;
	return (-1);
}

EnterValue::EnterValue()
{}

EnterValue::EnterValue(EnterValue const& copy)
{
	(void)copy;
}

EnterValue::~EnterValue()
{}

EnterValue	&EnterValue::operator=(EnterValue const& copy)
{
	(void)copy;
	return (*this);
}

int			EnterValue::execut(char *&tab, std::string buff, int &i) const
{
	(void)buff;
	(void)i;
	std::cin >> *&tab;
	return (-1);
}

