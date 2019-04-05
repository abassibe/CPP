/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:00:28 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/05 11:13:16 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HostModule.hpp"

HostModule::HostModule() : _x(0), _y(0), _sizeX(50), _sizeY(50), _hostName(),
	_loginName(), _domaineName()
{
}

HostModule::HostModule(int x, int y, int sizeX, int sizeY) : _x(x), _y(y),
	_sizeX(sizeX), _sizeY(sizeY)
{
	char	tmp[64];
	gethostname(tmp, 64);
	if (errno == EINVAL || tmp[0] == 0)
		_hostName = std::string("No host name");
	else
		_hostName = std::string(tmp);
	getlogin_r(tmp, 64);
	if (errno == ENXIO || tmp[0] == 0)
		_loginName = std::string("No login name");
	else
		_loginName = std::string(tmp);
	getdomainname(tmp, 64);
	if (errno == EINVAL || tmp[0] == 0)
		_domaineName = std::string("No domaine name");
	else
		_domaineName = std::string(tmp);
}

HostModule::HostModule(HostModule const& copy) : _x(copy._x), _y(copy._y), _sizeX(copy._sizeX),
	_sizeY(copy._sizeY), _hostName(copy._hostName), _loginName(copy._loginName), _domaineName(copy._domaineName)
{
}

HostModule::~HostModule()
{
}

HostModule	&HostModule::operator=(HostModule const& copy)
{
	_x = copy._x;
	_y = copy._y;
	_sizeX = copy._sizeX;
	_sizeY = copy._sizeY;
	_hostName = copy._hostName;
	_loginName = copy._loginName;
	_domaineName = copy._domaineName;
	return (*this);
}

int			HostModule::getX() const
{
	return (_x);
}

int			HostModule::getY() const
{
	return (_y);
}

void		HostModule::setX(int const& x)
{
	_x = x;
}

void		HostModule::setY(int const& y)
{
	_y = y;
}

void		HostModule::setPos(int const& x, int const& y)
{
	_x = x;
	_y = y;
}

int			HostModule::getSizeX() const
{
	return (_sizeX);
}

int			HostModule::getSizeY() const
{
	return (_sizeY);
}

void		HostModule::setSizeX(int const& sizeX)
{
	_sizeX = sizeX;
}

void		HostModule::setSizeY(int const& sizeY)
{
	_sizeY = sizeY;
}

void		HostModule::setSize(int const& sizeX, int const& sizeY)
{
	_sizeX = sizeX;
	_sizeY = sizeY;
}

void		HostModule::updateData()
{
	char	tmp[64];
	gethostname(tmp, 64);
	if (errno == EINVAL || tmp[0] == 0)
		_hostName = std::string("No host name");
	else
		_hostName = std::string(tmp);
	getlogin_r(tmp, 64);
	if (errno == ENXIO || tmp[0] == 0)
		_loginName = std::string("No login name");
	else
		_loginName = std::string(tmp);
	getdomainname(tmp, 64);
	if (errno == EINVAL || tmp[0] == 0)
		_domaineName = std::string("No domaine name");
	else
		_domaineName = std::string(tmp);
}

std::string		HostModule::getHostName() const
{
	return (_hostName);
}

std::string		HostModule::getLoginName() const
{
	return (_loginName);
}

std::string		HostModule::getDomaineName() const
{
	return (_domaineName);
}
