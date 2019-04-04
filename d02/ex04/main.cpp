/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:31:39 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/27 18:02:07 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "Fixed.hpp"

void	checkBrackets(std::string const& expr)
{
	int		openBrackets = 0;
	int		closeBrackets = 0;

	for (size_t i = 0; i < expr.length(); i++)
	{
		switch (expr[i])
		{
			case '(':
				openBrackets++;
				break;
			case')':
				closeBrackets++;
				break;
			default:
				continue;
		}
	}
	if (openBrackets != closeBrackets)
	{
		std::cout << "At least one paranthesis is missing" << std::endl;
		exit(0);
	}
}

void	pushDown(Fixed _operande[], int i, int operandeCount)
{
	while (i < operandeCount)
	{
		_operande[i] = _operande[i + 1];
		i++;
	}
}

std::string		calculate(std::string expr)
{
	Fixed	_operande[100];
	int		operandeCount = 0;
	char	_operator[50];
	int		operatorCount = 0;
	int		i = 0;

	if (expr[0] == '(')
	{
		expr.erase(0, 1);
		expr.erase(expr.length() - 1, 1);
	}

	while (!expr.empty())
	{
		try
		{
			_operande[i] = std::stof(expr);
			operandeCount++;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
			exit(0);
		}
		while (expr[0] == '.' || (expr[0] >= '0' && expr[0] <= '9'))
			expr.erase(0, 1);
		if (expr[0] == '+' || expr[0] == '-' || expr[0] == '*' || expr[0] == '/')
		{
			_operator[i] = expr[0];
			operatorCount++;
			expr.erase(0, 1);
		}
		i++;
	}
	if (!(operandeCount - 1 == operatorCount))
	{
		std::cout << "Syntax error." << std::endl;
		exit(0);
	}

	int op = 0;
	for (int i = 0; i < operatorCount; i++)
	{
		if (_operator[i] == '*')
		{
			_operande[op] = _operande[op] * _operande[op + 1];
			pushDown(_operande, op + 1, operandeCount);
			operandeCount--;
			_operator[i] = 0;
		}
		else if (_operator[i] == '/')
		{
			_operande[op] = _operande[op] / _operande[op + 1];
			pushDown(_operande, op + 1, operandeCount);
			operandeCount--;
			_operator[i] = 0;
		}
		else
			op++;
	}

	for (int i = 0; i < operatorCount; i++)
	{
		if (_operator[i] == '+')
		{
			_operande[0] = _operande[0] + _operande[1];
			pushDown(_operande, 1, operandeCount);
			operandeCount--;
			_operator[i] = 0;
		}
		else if (_operator[i] == '-')
		{
			_operande[0] = _operande[0] - _operande[1];
			pushDown(_operande, 1, operandeCount);
			operandeCount--;
			_operator[i] = 0;
		}
		else
			op++;
	}
	std::ostringstream ss;
	ss << _operande[0].toFloat();
	expr = ss.str();
	return (expr);
}

void	replaceBrackets(std::string &expr)
{
	checkBrackets(expr);
	while (expr.find_first_of('(') != std::string::npos)
	{
		int		index = expr.find_first_of(')');
		for (int i = index; i > 0; i--)
		{
			if (expr[i] == '(')
				expr.replace(i, index - i + 1, calculate(expr.substr(i, index - i + 1)));
			if (expr.find("+-") != std::string::npos)
				expr.erase(expr.find("+-"), 1);
		}
	}
}

void	searchBadCharacter(std::string const& expr)
{
	for (size_t i = 0; i < expr.length(); i++)
	{
		if (expr[i] != '+' && expr[i] != '-' && expr[i] != '*' && expr[i] != '/'
				&& expr[i] != '.' && expr[i] != '(' && expr[i] != ')' && (expr[i] < '0' || expr[i] > '9'))
		{
			char	error[14 + expr.length()];
			memset(error, ' ', 14 + expr.length());
			error[14 + expr.length() - 1] = 0;
			std::cout << "Syntax error: " << expr << std::endl;
			error[i + 14] = '^';
			std::cout << error << std::endl;
			exit(0);
		}
	}
}

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "One arithmetic expression is need." << std::endl;
		return (0);
	}
	std::string		expr = av[1];
	expr.erase(remove_if(expr.begin(), expr.end(), isspace), expr.end());
	searchBadCharacter(expr);
	if (expr.find_first_of('(') != std::string::npos && expr.find_first_of(')') != std::string::npos)
		replaceBrackets(expr);
	std::cout << calculate(expr) << std::endl;
}
