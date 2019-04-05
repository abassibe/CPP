/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:00:28 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/05 16:22:44 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/CPUModule.hpp"

CPUModule::CPUModule() : _x(0), _y(0), _sizeX(50), _sizeY(50), _model(),
	_clockSpeed(), _core(), _activity(), _previousActivity()
{
}

CPUModule::CPUModule(int x, int y, int sizeX, int sizeY) : _x(x), _y(y),
	_sizeX(sizeX), _sizeY(sizeY)
{
	//Fill _model and _clockSpeed
	size_t	bufferLen = 256;
	char	buffer[bufferLen];
	sysctlbyname("machdep.cpu.brand_string", &buffer, &bufferLen,NULL,0);
	std::string		bufferString(buffer);
	_model = bufferString.substr(0, bufferString.find("@"));
	_clockSpeed = bufferString.substr(bufferString.find("@") + 1);

	//Fill _core
	_core = sysconf(_SC_NPROCESSORS_ONLN);

	//Fill _activity
	host_cpu_load_info_data_t	cpuinfo;
	mach_msg_type_number_t count = HOST_CPU_LOAD_INFO_COUNT;
	if (host_statistics(mach_host_self(), HOST_CPU_LOAD_INFO, (host_info_t)&cpuinfo, &count) == KERN_SUCCESS)
	{
		unsigned long long totalTicks = 0;
		for(int i = 0; i < CPU_STATE_MAX; i++)
			totalTicks += cpuinfo.cpu_ticks[i];

		_activity = (1.0f - ((totalTicks > 0) ? (static_cast<float>(cpuinfo.cpu_ticks[CPU_STATE_IDLE])) / totalTicks : 0)) * 100;
		_previousActivity.push_back(_activity);
	}
	else
	{
		_activity =  -1.0f * 100;
		_previousActivity.push_back(_activity);
	}
}

CPUModule::CPUModule(CPUModule const& copy) : _x(copy._x), _y(copy._y), _sizeX(copy._sizeX),
	_sizeY(copy._sizeY), _model(copy._model), _clockSpeed(copy._clockSpeed), _core(copy._core),
	_activity(copy._activity), _previousActivity(copy._previousActivity)
{
}

CPUModule::~CPUModule()
{
}

CPUModule	&CPUModule::operator=(CPUModule const& copy)
{
	_x = copy._x;
	_y = copy._y;
	_sizeX = copy._sizeX;
	_sizeY = copy._sizeY;
	_model = copy._model;
	_clockSpeed = copy._clockSpeed;
	_core = copy._core;
	_activity = copy._activity;
	_previousActivity = copy._previousActivity;
	return (*this);
}

int			CPUModule::getX() const
{
	return (_x);
}

int			CPUModule::getY() const
{
	return (_y);
}

void		CPUModule::setX(int const& x)
{
	_x = x;
}

void		CPUModule::setY(int const& y)
{
	_y = y;
}

void		CPUModule::setPos(int const& x, int const& y)
{
	_x = x;
	_y = y;
}

int			CPUModule::getSizeX() const
{
	return (_sizeX);
}

int			CPUModule::getSizeY() const
{
	return (_sizeY);
}

void		CPUModule::setSizeX(int const& sizeX)
{
	_sizeX = sizeX;
}

void		CPUModule::setSizeY(int const& sizeY)
{
	_sizeY = sizeY;
}

void		CPUModule::setSize(int const& sizeX, int const& sizeY)
{
	_sizeX = sizeX;
	_sizeY = sizeY;
}

void		CPUModule::updateData()
{
	//Fill _model and _clockSpeed
	size_t	bufferLen = 256;
	char	buffer[bufferLen];
	sysctlbyname("machdep.cpu.brand_string", &buffer, &bufferLen,NULL,0);
	std::string		bufferString(buffer);
	_model = bufferString.substr(0, bufferString.find("@"));
	_clockSpeed = bufferString.substr(bufferString.find("@") + 1);

	//Fill _core
	_core = sysconf(_SC_NPROCESSORS_ONLN);

	//Fill _activity
	host_cpu_load_info_data_t	cpuinfo;
	mach_msg_type_number_t count = HOST_CPU_LOAD_INFO_COUNT;
	if (host_statistics(mach_host_self(), HOST_CPU_LOAD_INFO, (host_info_t)&cpuinfo, &count) == KERN_SUCCESS)
	{
		unsigned long long totalTicks = 0;
		for (int i = 0; i < CPU_STATE_MAX; i++)
			totalTicks += cpuinfo.cpu_ticks[i];

		_activity = (1.0f - ((totalTicks > 0) ? (static_cast<float>(cpuinfo.cpu_ticks[CPU_STATE_IDLE])) / totalTicks : 0)) * 100;
		_previousActivity.push_back(_activity);
	}
	else
	{
		_activity =  0.0f;
		_previousActivity.push_back(_activity);
	}
}

std::string			CPUModule::getModel() const
{
	return (_model);
}

std::string			CPUModule::getClockSpeed() const
{
	return (_clockSpeed);
}

int					CPUModule::getCore() const
{
	return (_core);
}

float				CPUModule::getActivity() const
{
	return (_activity);
}

std::list<float>	CPUModule::getPreviousActivity() const
{
	return (_previousActivity);
}
