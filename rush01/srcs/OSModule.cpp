/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSModule.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:00:28 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/05 13:12:00 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/utsname.h>
#include "../includes/OSModule.hpp"

OSModule::OSModule() : _x(0), _y(0), _sizeX(50), _sizeY(50), _productName(),
	_productVersion(), _buildVersion(), _sysName(), _releaseVersion(),
	_machineArchitecture()
{
}

OSModule::OSModule(int x, int y, int sizeX, int sizeY) : _x(x), _y(y),
	_sizeX(sizeX), _sizeY(sizeY)
{
	char	line[3][256];
	FILE	*sw_vers = popen("sw_vers", "r");
	for (int i = 0; fgets(line[i], sizeof(line[i]), sw_vers) != NULL; i++)
		;
	_productName = std::string(line[0]);
	_productVersion = std::string(line[1]);
	_buildVersion = std::string(line[2]);

	utsname os;
	uname(&os);
	_sysName = os.sysname;
	_releaseVersion = os.version;
	_machineArchitecture = os.machine;
}

OSModule::OSModule(OSModule const& copy) : _x(copy._x), _y(copy._y), _sizeX(copy._sizeX),
	_sizeY(copy._sizeY), _productName(copy._productName), _productVersion(copy._productVersion),
	_buildVersion(copy._buildVersion), _sysName(copy._sysName),
	_releaseVersion(copy._releaseVersion), _machineArchitecture(copy._machineArchitecture)
{
}

OSModule::~OSModule()
{
}

OSModule	&OSModule::operator=(OSModule const& copy)
{
	_x = copy._x;
	_y = copy._y;
	_sizeX = copy._sizeX;
	_sizeY = copy._sizeY;
	_productName = copy._productName;
	_productVersion = copy._productVersion;
	_buildVersion = copy._buildVersion;
	_sysName = copy._sysName;
	_releaseVersion = copy._releaseVersion;
	_machineArchitecture = copy._machineArchitecture;
	return (*this);
}

int			OSModule::getX() const
{
	return (_x);
}

int			OSModule::getY() const
{
	return (_y);
}

void		OSModule::setX(int const& x)
{
	_x = x;
}

void		OSModule::setY(int const& y)
{
	_y = y;
}

void		OSModule::setPos(int const& x, int const& y)
{
	_x = x;
	_y = y;
}

int			OSModule::getSizeX() const
{
	return (_sizeX);
}

int			OSModule::getSizeY() const
{
	return (_sizeY);
}

void		OSModule::setSizeX(int const& sizeX)
{
	_sizeX = sizeX;
}

void		OSModule::setSizeY(int const& sizeY)
{
	_sizeY = sizeY;
}

void		OSModule::setSize(int const& sizeX, int const& sizeY)
{
	_sizeX = sizeX;
	_sizeY = sizeY;
}

void		OSModule::updateData()
{
	char	line[3][256];
	FILE	*sw_vers = popen("sw_vers", "r");
	for (int i = 0; fgets(line[i], sizeof(line[i]), sw_vers) != NULL; i++)
		;
	_productName = std::string(line[0]);
	_productVersion = std::string(line[1]);
	_buildVersion = std::string(line[2]);

	utsname os;
	uname(&os);
	_sysName = os.sysname;
	_releaseVersion = os.version;
	_machineArchitecture = os.machine;
}

std::string		OSModule::getProductName() const
{
	return (_productName);
}

std::string		OSModule::getProductVersion() const
{
	return (_productVersion);
}

std::string		OSModule::getBuildVersion() const
{
	return (_buildVersion);
}

std::string		OSModule::getSysName() const
{
	return (_sysName);
}

std::string		OSModule::getReleaseVersion() const
{
	return (_releaseVersion);
}

std::string		OSModule::getMachineArchitecture() const
{
	return (_machineArchitecture);
}
