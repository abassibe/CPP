/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:00:28 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/05 11:27:47 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DateModule.hpp"

DateModule::DateModule() : _x(0), _y(0), _sizeX(50), _sizeY(50), _date(), _time(),
	_rawTime(time(&_rawTime)), _timeInfo(localtime(&_rawTime))
{
}

DateModule::DateModule(int x, int y, int sizeX, int sizeY) : _x(x), _y(y), _sizeX(sizeX),
	_sizeY(sizeY), _rawTime(time(&_rawTime)), _timeInfo(localtime(&_rawTime))
{
	std::string		month;
	switch (_timeInfo->tm_mon)
	{
		case 0:
			month = "January";
			break;
		case 1:
			month = "February";
			break;
		case 2:
			month = "March";
			break;
		case 3:
			month = "April";
			break;
		case 4:
			month = "May";
			break;
		case 5:
			month = "June";
			break;
		case 6:
			month = "July";
			break;
		case 7:
			month = "August";
			break;
		case 8:
			month = "September";
			break;
		case 9:
			month = "October";
			break;
		case 10:
			month = "November";
			break;
		case 11:
			month = "December";
			break;
		default:
			month = "";
			break;
	}
	_date = std::string(std::to_string(_timeInfo->tm_mday).c_str()) + " " + month + " " + std::to_string(_timeInfo->tm_year + 1900);
	_time = std::string(std::to_string(_timeInfo->tm_hour).c_str()) + ":" +
		std::to_string(_timeInfo->tm_min) + ":" + std::to_string(_timeInfo->tm_sec);
}

DateModule::DateModule(DateModule const& copy) : _x(copy._x), _y(copy._y), _sizeX(copy._sizeX),
	_sizeY(copy._sizeY), _date(copy._date), _time(copy._time), _rawTime(copy._rawTime), _timeInfo(copy._timeInfo)
{
}

DateModule::~DateModule()
{
}

DateModule	&DateModule::operator=(DateModule const& copy)
{
	_x = copy._x;
	_y = copy._y;
	_sizeX = copy._sizeX;
	_sizeY = copy._sizeY;
	_date = copy._date;
	_time = copy._time;
	_rawTime = copy._rawTime;
	_timeInfo = copy._timeInfo;
	return (*this);
}

int			DateModule::getX() const
{
	return (_x);
}

int			DateModule::getY() const
{
	return (_y);
}

void		DateModule::setX(int const& x)
{
	_x = x;
}

void		DateModule::setY(int const& y)
{
	_y = y;
}

void		DateModule::setPos(int const& x, int const& y)
{
	_x = x;
	_y = y;
}

int			DateModule::getSizeX() const
{
	return (_sizeX);
}

int			DateModule::getSizeY() const
{
	return (_sizeY);
}

void		DateModule::setSizeX(int const& sizeX)
{
	_sizeX = sizeX;
}

void		DateModule::setSizeY(int const& sizeY)
{
	_sizeY = sizeY;
}

void		DateModule::setSize(int const& sizeX, int const& sizeY)
{
	_sizeX = sizeX;
	_sizeY = sizeY;
}

void		DateModule::updateData()
{
	std::string		month;
	switch (_timeInfo->tm_mon)
	{
		case 1:
			month = "January";
			break;
		case 2:
			month = "February";
			break;
		case 3:
			month = "March";
			break;
		case 4:
			month = "April";
			break;
		case 5:
			month = "May";
			break;
		case 6:
			month = "June";
			break;
		case 7:
			month = "July";
			break;
		case 8:
			month = "August";
			break;
		case 9:
			month = "September";
			break;
		case 10:
			month = "October";
			break;
		case 11:
			month = "November";
			break;
		case 12:
			month = "December";
			break;
		default:
			month = "";
			break;
	}
	_date = std::string(std::to_string(_timeInfo->tm_mday).c_str()) + " " + month + " " + std::to_string(_timeInfo->tm_year + 1900);
	_time = std::string(std::to_string(_timeInfo->tm_hour).c_str()) + ":" +
		std::to_string(_timeInfo->tm_min) + ":" + std::to_string(_timeInfo->tm_sec);

}

std::string		DateModule::getDate() const
{
	return (_date);
}

std::string		DateModule::getTime() const
{
	return (_time);
}
