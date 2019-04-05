/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkModule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:00:28 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/05 17:46:20 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/NetworkModule.hpp"

NetworkModule::NetworkModule() : _x(0), _y(0), _sizeX(50), _sizeY(50), _inputActivity(),
	_previousInputActivity(), _outputActivity(), _previousOutputActivity()
{
}

NetworkModule::NetworkModule(int x, int y, int sizeX, int sizeY) : _x(x), _y(y),
	_sizeX(sizeX), _sizeY(sizeY)
{
	FILE *f = popen("netstat -w1", "r");
	if (!f)
		return ;
	char		buf[4096];
	long int	input = 0;
	long		output = 0;
	while (fgets(buf, 4096, f) != NULL)
	{
		std::string line(buf);
		if (line.find("input") != std::string::npos || line.find("packets") != std::string::npos)
			continue;
		long int	a;
		std::stringstream	ss(line);
		std::stringstream	ssInput;
		std::stringstream	ssOutput;
		ss >> a;
		ss >> a;
		ss >> input;
		ss >> a;
		ss >> a;
		ss >> output;

		ssInput << bytes_format(input);
		ssInput << "/s input";
		ssOutput << bytes_format(output);
		ssOutput << "/s output";
		_inputActivity = ssInput.str();
		_previousInputActivity.push_back(_inputActivity);
		_outputActivity = ssOutput.str();
		_previousOutputActivity.push_back(_outputActivity);
		break;
	}
}

NetworkModule::NetworkModule(NetworkModule const& copy) : _x(copy._x), _y(copy._y),
	_sizeX(copy._sizeX), _sizeY(copy._sizeY), _inputActivity(copy._inputActivity),
	_previousInputActivity(copy._previousInputActivity), _outputActivity(copy._outputActivity),
	_previousOutputActivity(copy._previousOutputActivity)
{
}

NetworkModule::~NetworkModule()
{
}

NetworkModule	&NetworkModule::operator=(NetworkModule const& copy)
{
	_x = copy._x;
	_y = copy._y;
	_sizeX = copy._sizeX;
	_sizeY = copy._sizeY;
	_inputActivity = copy._inputActivity;
	_previousInputActivity = copy._previousInputActivity;
	_outputActivity = copy._outputActivity;
	_previousOutputActivity = copy._previousOutputActivity;
	return (*this);
}

std::string		NetworkModule::bytes_format(long bytes)
{
	static const std::string	s[] = {"bytes", "Kb", "Mb", "Gb", "Tb", "Eb"};
	long double		b = bytes;
	int				i = 0;

	for (i = 0; b >= 1024 && i < 6; i++)
		b /= 1024;

	std::stringstream ss;
	ss << std::setprecision((i == 0 ? 0 : 2)) << std::fixed << b << " " << s[i];
	return ss.str();
}

int			NetworkModule::getX() const
{
	return (_x);
}

int			NetworkModule::getY() const
{
	return (_y);
}

void		NetworkModule::setX(int const& x)
{
	_x = x;
}

void		NetworkModule::setY(int const& y)
{
	_y = y;
}

void		NetworkModule::setPos(int const& x, int const& y)
{
	_x = x;
	_y = y;
}

int			NetworkModule::getSizeX() const
{
	return (_sizeX);
}

int			NetworkModule::getSizeY() const
{
	return (_sizeY);
}

void		NetworkModule::setSizeX(int const& sizeX)
{
	_sizeX = sizeX;
}

void		NetworkModule::setSizeY(int const& sizeY)
{
	_sizeY = sizeY;
}

void		NetworkModule::setSize(int const& sizeX, int const& sizeY)
{
	_sizeX = sizeX;
	_sizeY = sizeY;
}

void		NetworkModule::updateData()
{
	FILE *f = popen("netstat -w1", "r");
	if (!f)
		return ;
	char		buf[4096];
	long int	input = 0;
	long		output = 0;
	while (fgets(buf, 4096, f) != NULL)
	{
		std::string line(buf);
		if (line.find("input") != std::string::npos || line.find("packets") != std::string::npos)
			continue;
		long int	a;
		std::stringstream	ss(line);
		std::stringstream	ssInput;
		std::stringstream	ssOutput;
		ss >> a;
		ss >> a;
		ss >> input;
		ss >> a;
		ss >> a;
		ss >> output;

		ssInput << bytes_format(input);
		ssInput << "/s input";
		ssOutput << bytes_format(output);
		ssOutput << "/s output";
		_inputActivity = ssInput.str();
		_previousInputActivity.push_back(_inputActivity);
		_outputActivity = ssOutput.str();
		_previousOutputActivity.push_back(_outputActivity);
		break;
	}
}

std::string				NetworkModule::getInputActivity() const
{
	return (_inputActivity);
}

std::list<std::string>	NetworkModule::getPreviousInputActivity() const
{
	return (_previousInputActivity);
}

std::string				NetworkModule::getOutputActivity() const
{
	return (_outputActivity);
}

std::list<std::string>	NetworkModule::getPreviousOutputActivity() const
{
	return (_previousOutputActivity);
}
