/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAMActivityModule.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:00:28 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/06 17:39:29 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RAMActivityModule.hpp"

static double ParseMemValue(const char * b)
{
	while((*b) && (isdigit(*b) == false))
		b++;
	return (isdigit(*b) ? atof(b) : -1.0);
}

RAMActivityModule::RAMActivityModule() : _x(0), _y(0), _sizeX(20), _sizeY(20), _previousActivity()
{
}

RAMActivityModule::RAMActivityModule(int x, int y, int sizeX, int sizeY) : _x(x), _y(y),
	_sizeX(sizeX), _sizeY(sizeY)
{
	//Fill _RAMActivityActivity
	FILE	*fpIn = popen("/usr/bin/vm_stat", "r");
	if (fpIn)
	{
		double	pagesUsed = 0.0;
		double	totalPages = 0.0;
		char	buf[512];
		while (fgets(buf, sizeof(buf), fpIn) != NULL)
		{
			if (strncmp(buf, "Pages", 5) == 0)
			{
				double	val = ParseMemValue(buf);
				if (val >= 0.0)
				{
					if ((strncmp(buf, "Pages wired", 11) == 0) || (strncmp(buf, "Pages active", 12) == 0))
						pagesUsed += val;
					totalPages += val;
				}
			}
			else if (strncmp(buf, "Mach Virtual Memory Statistics", 30) != 0)
				break;
		}
		pclose(fpIn);
		if (totalPages > 0.0)
		{
			_previousActivity.push_back(static_cast<float>(pagesUsed/totalPages) * 100);
		}
	}
}

RAMActivityModule::RAMActivityModule(RAMActivityModule const& copy) : _x(copy._x), _y(copy._y), _sizeX(copy._sizeX),
	_sizeY(copy._sizeY), _previousActivity(copy._previousActivity)
{
}

RAMActivityModule::~RAMActivityModule()
{
}

RAMActivityModule	&RAMActivityModule::operator=(RAMActivityModule const& copy)
{
	_x = copy._x;
	_y = copy._y;
	_sizeX = copy._sizeX;
	_sizeY = copy._sizeY;
	_previousActivity = copy._previousActivity;
	return (*this);
}

int			RAMActivityModule::getX() const
{
	return (_x);
}

int			RAMActivityModule::getY() const
{
	return (_y);
}

void		RAMActivityModule::setX(int const& x)
{
	_x = x;
}

void		RAMActivityModule::setY(int const& y)
{
	_y = y;
}

void		RAMActivityModule::setPos(int const& x, int const& y)
{
	_x = x;
	_y = y;
}

int			RAMActivityModule::getSizeX() const
{
	return (_sizeX);
}

int			RAMActivityModule::getSizeY() const
{
	return (_sizeY);
}

void		RAMActivityModule::setSizeX(int const& sizeX)
{
	_sizeX = sizeX;
}

void		RAMActivityModule::setSizeY(int const& sizeY)
{
	_sizeY = sizeY;
}

void		RAMActivityModule::setSize(int const& sizeX, int const& sizeY)
{
	_sizeX = sizeX;
	_sizeY = sizeY;
}

void		RAMActivityModule::updateData()
{
	//Fill _RAMActivityActivity
	FILE	*fpIn = popen("/usr/bin/vm_stat", "r");
	if (fpIn)
	{
		double	pagesUsed = 0.0;
		double	totalPages = 0.0;
		char	buf[512];
		while (fgets(buf, sizeof(buf), fpIn) != NULL)
		{
			if (strncmp(buf, "Pages", 5) == 0)
			{
				double	val = ParseMemValue(buf);
				if (val >= 0.0)
				{
					if ((strncmp(buf, "Pages wired", 11) == 0) || (strncmp(buf, "Pages active", 12) == 0))
						pagesUsed += val;
					totalPages += val;
				}
			}
			else if (strncmp(buf, "Mach Virtual Memory Statistics", 30) != 0)
				break;
		}
		pclose(fpIn);
		if (totalPages > 0.0)
		{
			_previousActivity.push_back(static_cast<float>(pagesUsed/totalPages) * 100);
		}
	}
}

std::list<float>	RAMActivityModule::getPreviousActivity() const
{
	return (_previousActivity);
}
