/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   While.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:28:55 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/03 17:29:27 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "While.hpp"

int		g_while = 0;

WhileBegin::WhileBegin()
{}

WhileBegin::WhileBegin(WhileBegin const& copy)
{
	(void)copy;
}

WhileBegin::~WhileBegin()
{}

WhileBegin	&WhileBegin::operator=(WhileBegin const& copy)
{
	(void)copy;
	return (*this);
}

int			WhileBegin::execut(char *&tab, std::string buff, int &i) const
{
	int		count = 1;
	if (*tab)
	{
		g_while++;
		return (i);
	}
	while (buff[i] && (buff[i] != ']' || count != 0))
	{
		i++;
		if (buff[i] == '[')
			count++;
		else if (buff[i] == ']')
		{
			count--;
			if (buff[i] == ']' && count == 0)
				return (-1) ;
		}
	}
	return (-1);
}

WhileEnd::WhileEnd()
{}

WhileEnd::WhileEnd(WhileEnd const& copy)
{
	(void)copy;
}

WhileEnd::~WhileEnd()
{}

WhileEnd	&WhileEnd::operator=(WhileEnd const& copy)
{
	(void)copy;
	return (*this);
}

int			WhileEnd::execut(char *&tab, std::string buff, int &i) const
{
	(void)buff;
	(void)i;
	(void)tab;
	if (g_while)
	{
		g_while--;
		return (-2);
	}
	else
	{
		std::cout << "\nsyntax error\n";
		exit (0);
	}
}
