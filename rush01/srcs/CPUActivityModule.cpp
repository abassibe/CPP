/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUActivityModule.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:00:28 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/06 17:39:37 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/CPUActivityModule.hpp"

CPUActivityModule::CPUActivityModule() : _x(0), _y(0), _sizeX(20), _sizeY(20), _previousActivity()
{
}

CPUActivityModule::CPUActivityModule(int x, int y, int sizeX, int sizeY) : _x(x), _y(y),
	_sizeX(sizeX), _sizeY(sizeY)
{
	float	activity;
	host_cpu_load_info_data_t	cpuinfo;
	mach_msg_type_number_t count = HOST_CPU_LOAD_INFO_COUNT;
	if (host_statistics(mach_host_self(), HOST_CPU_LOAD_INFO, (host_info_t)&cpuinfo, &count) == KERN_SUCCESS)
	{
		unsigned long long totalTicks = 0;
		for (int i = 0; i < CPU_STATE_MAX; i++)
			totalTicks += cpuinfo.cpu_ticks[i];

		activity = (1.0f - ((totalTicks > 0) ? (static_cast<float>(cpuinfo.cpu_ticks[CPU_STATE_IDLE])) / totalTicks : 0)) * 100;
		_previousActivity.push_back(activity);
	}
	else
	{
		activity =  -1.0f * 100;
		_previousActivity.push_back(activity);
	}
}

CPUActivityModule::CPUActivityModule(CPUActivityModule const& copy) : _x(copy._x), _y(copy._y), _sizeX(copy._sizeX),
	_sizeY(copy._sizeY), _previousActivity(copy._previousActivity)
{
}

CPUActivityModule::~CPUActivityModule()
{
}

CPUActivityModule	&CPUActivityModule::operator=(CPUActivityModule const& copy)
{
	_x = copy._x;
	_y = copy._y;
	_sizeX = copy._sizeX;
	_sizeY = copy._sizeY;
	_previousActivity = copy._previousActivity;
	return (*this);
}

int			CPUActivityModule::getX() const
{
	return (_x);
}

int			CPUActivityModule::getY() const
{
	return (_y);
}

void		CPUActivityModule::setX(int const& x)
{
	_x = x;
}

void		CPUActivityModule::setY(int const& y)
{
	_y = y;
}

void		CPUActivityModule::setPos(int const& x, int const& y)
{
	_x = x;
	_y = y;
}

int			CPUActivityModule::getSizeX() const
{
	return (_sizeX);
}

int			CPUActivityModule::getSizeY() const
{
	return (_sizeY);
}

void		CPUActivityModule::setSizeX(int const& sizeX)
{
	_sizeX = sizeX;
}

void		CPUActivityModule::setSizeY(int const& sizeY)
{
	_sizeY = sizeY;
}

void		CPUActivityModule::setSize(int const& sizeX, int const& sizeY)
{
	_sizeX = sizeX;
	_sizeY = sizeY;
}

void		CPUActivityModule::updateData()
{
	float	activity;
	host_cpu_load_info_data_t	cpuinfo;
	mach_msg_type_number_t count = HOST_CPU_LOAD_INFO_COUNT;
	if (host_statistics(mach_host_self(), HOST_CPU_LOAD_INFO, (host_info_t)&cpuinfo, &count) == KERN_SUCCESS)
	{
		unsigned long long totalTicks = 0;
		for (int i = 0; i < CPU_STATE_MAX; i++)
			totalTicks += cpuinfo.cpu_ticks[i];

		activity = (1.0f - ((totalTicks > 0) ? (static_cast<float>(cpuinfo.cpu_ticks[CPU_STATE_IDLE])) / totalTicks : 0)) * 100;
		_previousActivity.push_back(activity);
	}
	else
	{
		activity =  -1.0f * 100;
		_previousActivity.push_back(activity);
	}
}

std::list<float>	CPUActivityModule::getPreviousActivity() const
{
	return (_previousActivity);
}
