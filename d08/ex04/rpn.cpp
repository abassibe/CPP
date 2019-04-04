/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 02:34:48 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/03 18:30:27 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpn.hpp"

rpn::rpn()
{}

rpn::rpn(std::string const& exp)
{
	int		i = -1;
	int		save = 0;

	while (exp[++i])
	{
		if (exp[i] != ' ' && exp[i] != '(' && exp[i] != ')' && exp[i] != '+'
				&& exp[i] != '-' && exp[i] != '*' && exp[i] != '/' &&
				(exp[i] < '0' || exp[i] > '9'))
			throw rpn::NoValidCharacter();
		if (exp[i] == '(' || exp[i] == ')' || exp[i] == '+' || exp[i] == '-' ||
				exp[i] == '*' || exp[i] == '/' || (exp[i] >= '0' && exp[i] <= '9'))
		{
			_token.push_back(exp.substr(save, ((i + 1) - save)));
			save = (i + 1);
			while (exp[save] == ' ')
				save++;
		}
	}
/*	std::list<std::string>::iterator it = _token.begin();
	while (it != _token.end())
	{
		std::cout << *it << std::endl;
		it++;
	}*/
}

rpn::rpn(rpn const& copy) : _token(copy._token), _fixed(copy._fixed)
{
}

rpn::~rpn()
{}

rpn		&rpn::operator=(rpn const& copy)
{
	_token = copy._token;
	_fixed = copy._fixed;
	return (*this);
}

void	rpn::print_token()
{
	std::list<std::string>::iterator	it = _token.begin();
	std::string							tmp;

	std::cout << "Token:";
	while (it != _token.end())
	{
		tmp = *it;
		if (tmp[0] == '(')
			std::cout << " ParOpen";
		else if (tmp[0] == ')')
			std::cout << " ParClose";
		else if (tmp[0] == '+' || tmp[0] == '-' || tmp[0] == '*' || tmp[0] == '/' )
			std::cout << " Op(" << tmp[0] << ")";
		else
			std::cout << " Num(" << tmp << ")";
		it++;
	}
	std::cout << std::endl;
}

void	rpn::fix()
{
	_fixed = _token;
	std::list<std::string>::iterator	it = _fixed.begin();
	std::string							tmp;

	while (it != _fixed.end())
	{
		tmp = *it;
		if (tmp[0] == ')')
		{
			
			it = _fixed.begin();
		}
		else
			it++;
	}
}

void	rpn::replace_operator(std::list<std::string>::iterator it)
{
	std::string							tmp;
	std::list<std::string>::iterator	save;

	tmp = *it;
	while (tmp[0] != '(')
	{
		it--;
		tmp = *it;
		if (it == _fixed.begin() && tmp[0] != '(')
			throw WrongImplementation();
	}
	it++;
	tmp = *it;
	while (tmp[0] != ')')
	{

	}
}

rpn::NoValidCharacter::NoValidCharacter() throw()
{}

rpn::NoValidCharacter::NoValidCharacter(NoValidCharacter const& copy) throw()
{
	(void)copy;
}

rpn::NoValidCharacter::~NoValidCharacter() throw()
{}

rpn::NoValidCharacter	&rpn::NoValidCharacter::operator=(NoValidCharacter const& copy) throw()
{
	(void)copy;
	return (*this);
}

const char	*rpn::NoValidCharacter::what() const throw()
{
	return ("Invalid character in the tring");
}

rpn::WrongImplementation::WrongImplementation() throw()
{}

rpn::WrongImplementation::WrongImplementation(WrongImplementation const& copy) throw()
{
	(void)copy;
}

rpn::WrongImplementation::~WrongImplementation() throw()
{}

rpn::WrongImplementation	&rpn::WrongImplementation::operator=(WrongImplementation const& copy) throw()
{
	(void)copy;
	return (*this);
}

const char	*rpn::WrongImplementation::what() const throw()
{
	return ("Wrong Implementation");
}
