/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateModule.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:47:40 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/06 15:28:43 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATEMODULE_HPP
# define DATEMODULE_HPP

# include <ctime>
# include "IMonitorModule.hpp"

class DateModule : public IMonitorModule
{
	public:
		DateModule(int x, int y, int sizeX = 80, int sizeY = 15);
		DateModule(DateModule const& copy);
		virtual ~DateModule();
		DateModule		&operator=(DateModule const& copy);
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
		std::string		getDate() const;
		std::string		getTime() const;

	private:
		DateModule();
		int				_x;
		int				_y;
		int				_sizeX;
		int				_sizeY;
		std::string		_date;
		std::string		_time;
		time_t			_rawTime;
		struct tm		*_timeInfo;
};

#endif
