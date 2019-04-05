/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostModule.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:47:40 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/04 15:54:00 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOSTMODULE_HPP
# define HOSTMODULE_HPP

# include <unistd.h>
# include "IMonitorModule.hpp"

class HostModule : public IMonitorModule
{
	public:
		HostModule(int x, int y, int sizeX = 50, int sizeY = 50);
		HostModule(HostModule const& copy);
		virtual ~HostModule();
		HostModule		&operator=(HostModule const& copy);
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
		std::string		getHostName() const;
		std::string		getLoginName() const;
		std::string		getDomaineName() const;

	private:
		HostModule();
		int				_x;
		int				_y;
		int				_sizeX;
		int				_sizeY;
		std::string		_hostName;
		std::string		_loginName;
		std::string		_domaineName;
};

#endif
