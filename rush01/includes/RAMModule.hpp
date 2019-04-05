/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAMModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:47:40 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/05 15:28:54 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAMMODULE_HPP
# define RAMMODULE_HPP

# include <list>
# include <sys/types.h>
# include <sys/sysctl.h>
# include "IMonitorModule.hpp"

class RAMModule : public IMonitorModule
{
	public:
		RAMModule(int x, int y, int sizeX = 50, int sizeY = 50);
		RAMModule(RAMModule const& copy);
		virtual ~RAMModule();
		RAMModule			&operator=(RAMModule const& copy);
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
		long int			getRAMCapacity() const;
		float				getRAMActivity() const;
		std::list<float>	getPreviousActivity() const;

	private:
		RAMModule();
		int					_x;
		int					_y;
		int					_sizeX;
		int					_sizeY;
		int64_t				_RAMCapacity;
		float				_RAMActivity;
		std::list<float>	_previousActivity;
};

#endif
