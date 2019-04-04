/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CentralBureaucracy.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 18:32:27 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/01 19:04:58 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CentralBureaucracy.hpp"
#include <ctime>

CentralBureaucracy::CentralBureaucracy()
{
	_nbBureaucrats = 0;
	_queueSize = 0;
}

CentralBureaucracy::CentralBureaucracy(CentralBureaucracy const& copy)
{
	_nbBureaucrats = copy._nbBureaucrats;
	_queueSize = copy._queueSize;
}

CentralBureaucracy::~CentralBureaucracy()
{}

CentralBureaucracy	&CentralBureaucracy::operator=(CentralBureaucracy const& copy)
{
	_nbBureaucrats = copy._nbBureaucrats;
	_queueSize = copy._queueSize;
	return (*this);
}

void				CentralBureaucracy::addBureaucrat(Bureaucrat *hired)
{
	if (_nbBureaucrats < 40)
	{
		if (!(_nbBureaucrats % 2))
			_blocks[_nbBureaucrats / 2].setSignatory(hired);
		else
		{
			_blocks[_nbBureaucrats / 2].setExecutor(hired);
			_blocks[_nbBureaucrats / 2].setIntern(new Intern());
		}
		_nbBureaucrats++;
	}
	else
		std::cout << "There is no post available\n";
}

void				CentralBureaucracy::queueUp(std::string target)
{
	if (_queueSize < 20)
	{
		_queue[_queueSize] = target;
		_queueSize++;
	}
}

void				CentralBureaucracy::doBureaucracy()
{
	int		i = 0;
	srand(time(nullptr));
	std::string		form[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	while (i < _nbBureaucrats / 2)
	{
		std::cout << "\n****New stuff in progress****\n";
		try
		{
			_blocks[i].doBureaucracy(form[rand() % 3], _queue[rand() % _queueSize]);
		}
		catch (Form::NotSignedException &e)
		{
			e.what();
		}
		catch (Form::GradeTooHighException &e)
		{
			e.what();
		}
		catch (Form::GradeTooLowException &e)
		{
			e.what();
		}
		i++;
	}
}
