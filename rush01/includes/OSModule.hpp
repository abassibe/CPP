/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSModule.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:47:40 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/06 15:21:35 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSMODULE_HPP
# define OSMODULE_HPP

# include <unistd.h>
# include "IMonitorModule.hpp"

class OSModule : public IMonitorModule
{
	public:
		OSModule(int x, int y, int sizeX = 80, int sizeY = 15);
		OSModule(OSModule const& copy);
		virtual ~OSModule();
		OSModule		&operator=(OSModule const& copy);
		virtual int		getX() const;
		virtual int		getY() const;
		virtual void	setX(int const& x);
		virtual void	setY(int const& y);
		virtual void	setPos(int const& x, int const& y);
		virtual int		getSizeX() const;
		virtual int		getSizeY() const;
		virtual void	setSizeX(int const& sizeX);
		virtual void	setSizeY(int const& sizeY);
		virtual void	setSize(int const& sizeX, int const& sizeY);
		virtual void	updateData();
		std::string		getProductName() const;
		std::string		getProductVersion() const;
		std::string		getBuildVersion() const;
		std::string		getSysName() const;
		std::string		getReleaseVersion() const;
		std::string		getMachineArchitecture() const;

	private:
		OSModule();
		int				_x;
		int				_y;
		int				_sizeX;
		int				_sizeY;
		std::string		_productName;
		std::string		_productVersion;
		std::string		_buildVersion;
		std::string		_sysName;
		std::string		_releaseVersion;
		std::string		_machineArchitecture;
};

#endif
