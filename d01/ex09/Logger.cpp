/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 19:36:16 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/26 19:44:21 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include "Logger.hpp"

struct Log
{
	std::string		dest;
	void			(Logger::*f)(std::string);
};

	Log		Logger::logs[] = {{"logToFile", &Logger::logToFile}, {"logToConsole", &Logger::logToConsole}};

Logger::Logger(std::string name) : _name(name)
{
}

Logger::~Logger()
{
}

void	Logger::logToFile(std::string log)
{
	std::ofstream	ofs;
	ofs.open(_name, std::ios::out | std::ios::app);
	ofs << log << std::endl;
	ofs.close();
}

void	Logger::logToConsole(std::string log)
{
	std::cout << log << std::endl;
}

std::string		Logger::makeLogEntry(std::string message)
{
	time_t			rawtime;
	std::string		log;
	std::string		str;
	std::string		date;

	str = " : ";
	time(&rawtime);
	date = ctime(&rawtime);
	date.erase(date.size() - 1);
	log = date + str + message;
	return (log);
}

void	Logger::log(std::string const& dest, std::string const& message)
{
	for (int i = 0; i < 2; i++)
		if (dest == logs[i].dest)
			(this->*logs[i].f)(message);
}
