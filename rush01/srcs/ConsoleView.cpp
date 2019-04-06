/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConsoleView.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 13:05:41 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/06 17:41:45 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ConsoleView.hpp"
#include "../includes/HostModule.hpp"
#include "../includes/OSModule.hpp"
#include "../includes/DateModule.hpp"
#include "../includes/CPUModule.hpp"
#include "../includes/RAMModule.hpp"
#include "../includes/NetworkModule.hpp"
#include "../includes/ConsoleView.hpp"
#include "../includes/CPUActivityModule.hpp"
#include "../includes/RAMActivityModule.hpp"

ConsoleView::ConsoleView() : _module()
{
}

ConsoleView::ConsoleView(ConsoleView const& copy)
{
	(void)copy;
}

ConsoleView::~ConsoleView()
{
}

ConsoleView		&ConsoleView::operator=(ConsoleView const& copy)
{
	(void)copy;
	return (*this);
}

void	ConsoleView::updateModule()
{
	for (std::vector<IMonitorModule*>::iterator it = _module.begin(); it != _module.end(); it++)
		(*it)->updateData();
}

void	ConsoleView::render()
{
	std::vector<WINDOW*>::iterator	itWin = _winModule.begin();
	for (std::vector<IMonitorModule*>::iterator it = _module.begin(); it != _module.end(); it++)
	{
		if (HostModule	*host = dynamic_cast<HostModule*>(*it))
		{
			std::string		value("Host name: ");
			value += host->getHostName();
			mvwprintw(*itWin, 2, 2, value.c_str());
			value = "Login name: ";
			value += host->getLoginName();
			mvwprintw(*itWin, 7, 2, value.c_str());
			value = "Domaine name: ";
			value += host->getDomaineName();
			mvwprintw(*itWin, 12, 2, value.c_str());
		}
		else if (OSModule	*os = dynamic_cast<OSModule*>(*it))
		{
			std::string		value;
			value += os->getProductName();
			mvwprintw(*itWin, 2, 2, value.c_str());
			value = "";
			value += os->getProductVersion();
			mvwprintw(*itWin, 4, 2, value.c_str());
			value = "";
			value += os->getBuildVersion();
			mvwprintw(*itWin, 6, 2, value.c_str());
			value = "System name: ";
			value += os->getSysName();
			mvwprintw(*itWin, 8, 2, value.c_str());
			value = "Release version: ";
			value += os->getReleaseVersion();
			mvwprintw(*itWin, 10, 2, value.c_str());
			value = "Machine architecture: ";
			value += os->getMachineArchitecture();
			mvwprintw(*itWin, 13, 2, value.c_str());
		}
		else if (DateModule	*date = dynamic_cast<DateModule*>(*it))
		{
			werase(*itWin);
			std::string		value("Date: ");
			value += date->getDate();
			mvwprintw(*itWin, 5, 2, value.c_str());
			value = "Time: ";
			value += date->getTime();
			mvwprintw(*itWin, 10, 2, value.c_str());
		}
		else if (CPUModule	*cpu = dynamic_cast<CPUModule*>(*it))
		{
			werase(*itWin);
			std::string		value("Model: ");
			value += cpu->getModel();
			mvwprintw(*itWin, 3, 2, value.c_str());
			value = "Clock speed: ";
			value += cpu->getClockSpeed();
			mvwprintw(*itWin, 6, 2, value.c_str());
			value = "Core: ";
			value += std::to_string(cpu->getCore());
			mvwprintw(*itWin, 9, 2, value.c_str());
			value = "CPU Activity: ";
			value += std::to_string(cpu->getActivity());
			value += "%%";
			mvwprintw(*itWin, 12, 2, value.c_str());
		}
		else if (RAMModule	*ram = dynamic_cast<RAMModule*>(*it))
		{
			werase(*itWin);
			std::string		value("RAM Capacity: ");
			value += std::to_string(ram->getRAMCapacity());
			value += "Go";
			mvwprintw(*itWin, 5, 2, value.c_str());
			value = "RAM Activity: ";
			value += std::to_string(ram->getRAMActivity());
			value += "%%";
			mvwprintw(*itWin, 10, 2, value.c_str());
		}
		else if (NetworkModule	*net = dynamic_cast<NetworkModule*>(*it))
		{
			werase(*itWin);
			std::string		value("Input: ");
			value += net->getInputActivity();
			mvwprintw(*itWin, 5, 2, value.c_str());
			value = "Output: ";
			value += net->getOutputActivity();
			mvwprintw(*itWin, 10, 2, value.c_str());
		}
		else if (CPUActivityModule	*cpu = dynamic_cast<CPUActivityModule*>(*it))
		{
			werase(*itWin);
			std::list<float>	list = cpu->getPreviousActivity();
			int		size = 78;
			for (std::list<float>::reverse_iterator it2 = list.rbegin(); it2 != list.rend() && size > 0; it2++)
			{
				int		percentRepresentation;
				percentRepresentation = (*it2 / (100 / cpu->getSizeY())) + 1;
				for (int j = 0; j < percentRepresentation; j++)
					mvwprintw(*itWin, cpu->getSizeY() - j - 2, size, "#");
				size--;
			}
		}
		else if (RAMActivityModule	*ram = dynamic_cast<RAMActivityModule*>(*it))
		{
			werase(*itWin);
			std::list<float>	list = ram->getPreviousActivity();
			int		size = 78;
			for (std::list<float>::reverse_iterator it2 = list.rbegin(); it2 != list.rend() && size > 0; it2++)
			{
				int		percentRepresentation;
				percentRepresentation = (*it2 / (100 / ram->getSizeY())) + 1;
				for (int j = 0; j < percentRepresentation; j++)
					mvwprintw(*itWin, ram->getSizeY() - j - 2, size, "#");
				size--;
			}
		}
		box(*itWin, ACS_VLINE, ACS_HLINE);
		wrefresh((*itWin));
		itWin++;
	}
}

void	ConsoleView::addModule(IMonitorModule *toAdd)
{
	_module.push_back(toAdd);
	WINDOW		*tmp = subwin(stdscr, toAdd->getSizeY(), toAdd->getSizeX(), toAdd->getY(), toAdd->getX());
	box(tmp, ACS_VLINE, ACS_HLINE);
	_winModule.push_back(tmp);
	wrefresh(tmp);
}

void	ConsoleView::removeModule(IMonitorModule const *target)
{
	std::vector<WINDOW*>::iterator	itWin = _winModule.begin();
	for (std::vector<IMonitorModule*>::iterator it = _module.begin(); it != _module.end(); it++)
	{
		if ((*it) == target)
		{
			delwin(*itWin);
			delete (*it);
			_module.erase(it);
			_winModule.erase(itWin);
		}
		itWin++;
	}
}
