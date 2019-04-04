/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 02:11:47 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/03 18:06:27 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IO.hpp"
#include "Pointer.hpp"
#include "Value.hpp"
#include "While.hpp"

void	 allocMap(std::map<char, IMindOpen *> &map)
{
	IMindOpen	*p1 = new PointerIncrement();
	IMindOpen	*p2 = new PointerDecrement();
	IMindOpen	*p3 = new ValueIncrement();
	IMindOpen	*p4 = new ValueDecrement();
	IMindOpen	*p5 = new PrintValue();
	IMindOpen	*p6 = new EnterValue();
	IMindOpen	*p7 = new WhileBegin();
	IMindOpen	*p8 = new WhileEnd();
	map['>'] = p1;
	map['<'] = p2;
	map['+'] = p3;
	map['-'] = p4;
	map['.'] = p5;
	map[','] = p6;
	map['['] = p7;
	map[']'] = p8;
}

void	parseur(std::ifstream &ifs)
{
	std::string								buff;
	int										i = 0;
	char									c = 0;
	char									*tab = new char[3000];
	std::map<char, IMindOpen *>				map;
	std::map<char, IMindOpen *>::iterator	it;
	std::list<int>							bracket;
	allocMap(map);
	while (ifs.get(c))
	{
		if (c != '>' && c != '<' && c != '+' && c != '-' &&
				c != '.' && c != ',' && c != '[' && c != ']' && !iswspace(c))
		{
			std::cout << "Bad character." << std::endl;
			exit(0);
		}
		if (c == '>' || c == '<' || c == '+' || c == '-' ||
				c == '.' || c == ',' || c == '[' || c == ']')
			buff.push_back(c);
	}
	ifs.close();
	while (buff[i])
	{
		bracket.push_back(map[buff[i]]->execut(tab, buff, i));
		if (bracket.back() == -1)
			bracket.pop_back();
		else if (bracket.back() == -2)
		{
			bracket.pop_back();
			i = bracket.back() - 1;
			bracket.pop_back();
		}
		i++;
	}
}

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage : Mindopen [filepath name]\n";
		return (0);
	}

	std::ifstream	ifs;
	ifs.open(av[1]);
	if (ifs.is_open())
		parseur(ifs);
	else
	{
		std::cout << "No such file or directory\n";
		return (0);
	}
	return (1);
}
