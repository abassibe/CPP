/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAMActivityModule.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:47:40 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/06 17:37:14 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAMACTIVITYMODULE_HPP
# define RAMACTIVITYMODULE_HPP

# include <list>
# include <sys/types.h>
# include <sys/sysctl.h>
# include "IMonitorModule.hpp"

class RAMActivityModule : public IMonitorModule
{
	public:
		RAMActivityModule(int x, int y, int sizeX = 80, int sizeY = 15);
		RAMActivityModule(RAMActivityModule const& copy);
		virtual ~RAMActivityModule();
		RAMActivityModule			&operator=(RAMActivityModule const& copy);
		virtual int			getX() const;
		virtual int			getY() const;
		virtual void		setX(int const& x);
		virtual void		setY(int const& y);
		virtual void		setPos(int const& x, int const& y);
		virtual int			getSizeX() const;
		virtual int			getSizeY() const;
		virtual void		setSizeX(int const& sizeX);
		virtual void		setSizeY(int const& sizeY);
		virtual void		setSize(int const& sizeX, int const& sizeY);
		virtual void		updateData();
		std::list<float>	getPreviousActivity() const;

	private:
		RAMActivityModule();
		int					_x;
		int					_y;
		int					_sizeX;
		int					_sizeY;
		std::list<float>	_previousActivity;
};

#endif
