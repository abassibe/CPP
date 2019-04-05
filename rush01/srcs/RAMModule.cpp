/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAMModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:00:28 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/05 16:24:32 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RAMModule.hpp"

static double ParseMemValue(const char * b)
{
	while((*b) && (isdigit(*b) == false))
		b++;
	return (isdigit(*b) ? atof(b) : -1.0);
}

RAMModule::RAMModule() : _x(0), _y(0), _sizeX(50), _sizeY(50), _RAMCapacity(0),
	_RAMActivity(), _previousActivity()
{
}

RAMModule::RAMModule(int x, int y, int sizeX, int sizeY) : _x(x), _y(y),
	_sizeX(sizeX), _sizeY(sizeY)
{
	//Fill _RAMCapacity
	int			mib[2];
	size_t		length = sizeof(int64_t);
	mib[0] = CTL_HW;
	mib[1] = HW_MEMSIZE;
	sysctl(mib, 2, &_RAMCapacity, &length, NULL, 0);

	//Fill _RAMActivity
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
			_RAMActivity = static_cast<float>(pagesUsed/totalPages) * 100;
			_previousActivity.push_back(_RAMActivity);
		}
	}
	else
		_RAMActivity =  0.0f;
}

RAMModule::RAMModule(RAMModule const& copy) : _x(copy._x), _y(copy._y), _sizeX(copy._sizeX),
	_sizeY(copy._sizeY), _RAMCapacity(copy._RAMCapacity), _previousActivity(copy._previousActivity)
{
}

RAMModule::~RAMModule()
{
}

RAMModule	&RAMModule::operator=(RAMModule const& copy)
{
	_x = copy._x;
	_y = copy._y;
	_sizeX = copy._sizeX;
	_sizeY = copy._sizeY;
	_RAMCapacity = copy._RAMCapacity;
	_RAMActivity = copy._RAMActivity;
	_previousActivity = copy._previousActivity;
	return (*this);
}

int			RAMModule::getX() const
{
	return (_x);
}

int			RAMModule::getY() const
{
	return (_y);
}

void		RAMModule::setX(int const& x)
{
	_x = x;
}

void		RAMModule::setY(int const& y)
{
	_y = y;
}

void		RAMModule::setPos(int const& x, int const& y)
{
	_x = x;
	_y = y;
}

int			RAMModule::getSizeX() const
{
	return (_sizeX);
}

int			RAMModule::getSizeY() const
{
	return (_sizeY);
}

void		RAMModule::setSizeX(int const& sizeX)
{
	_sizeX = sizeX;
}

void		RAMModule::setSizeY(int const& sizeY)
{
	_sizeY = sizeY;
}

void		RAMModule::setSize(int const& sizeX, int const& sizeY)
{
	_sizeX = sizeX;
	_sizeY = sizeY;
}

void		RAMModule::updateData()
{
	//Fill _RAMCapacity
	int			mib[2];
	size_t		length = sizeof(int64_t);
	mib[0] = CTL_HW;
	mib[1] = HW_MEMSIZE;
	sysctl(mib, 2, &_RAMCapacity, &length, NULL, 0);

	//Fill _RAMActivity
	FILE	*fpIn = popen("/usr/bin/vm_stat", "r");
	if (fpIn)
	{
		double	pagesUsed = 0.0;
		double	totalPages = 0.0;
		char	buf[512];
		while(fgets(buf, sizeof(buf), fpIn) != NULL)
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
			_RAMActivity = static_cast<float>(pagesUsed/totalPages) * 100;
			_previousActivity.push_back(_RAMActivity);
		}
	}
	else
		_RAMActivity =  0.0f;

}

long int		RAMModule::getRAMCapacity() const
{
	return (static_cast<long int>(_RAMCapacity));
}

float			RAMModule::getRAMActivity() const
{
	return (_RAMActivity);
}

std::list<float>	RAMModule::getPreviousActivity() const
{
	return (_previousActivity);
}
