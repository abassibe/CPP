/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:20:27 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/04 15:51:13 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP

# include <iostream>

class IMonitorModule
{
	public:
		virtual ~IMonitorModule() {}
		virtual int		getX() const = 0;
		virtual int		getY() const = 0;
		virtual void	setX(int const& x) = 0;
		virtual void	setY(int const& y) = 0;
		virtual void	setPos(int const& x, int const& y) = 0;
		virtual int		getSizeX() const = 0;
		virtual int		getSizeY() const = 0;
		virtual void	setSizeX(int const& sizeX)= 0;
		virtual void	setSizeY(int const& sizeY) = 0;
		virtual void	setSize(int const& sizeX, int const& sizeY) = 0;
		virtual void	updateData() = 0;
};

#endif
