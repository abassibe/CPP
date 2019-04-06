/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:47:40 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/06 15:28:38 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPUMODULE_HPP
# define CPUMODULE_HPP

# include <list>
# include <sys/sysctl.h>
# include <mach/mach_init.h>
# include <mach/mach_error.h>
# include <mach/mach_host.h>
# include <mach/vm_map.h>
# include <unistd.h>
# include "IMonitorModule.hpp"

class CPUModule : public IMonitorModule
{
	public:
		CPUModule(int x, int y, int sizeX = 80, int sizeY = 15);
		CPUModule(CPUModule const& copy);
		virtual ~CPUModule();
		CPUModule			&operator=(CPUModule const& copy);
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
		std::string			getModel() const;
		std::string			getClockSpeed() const;
		int					getCore() const;
		float				getActivity() const;
		std::list<float>	getPreviousActivity() const;

	private:
		CPUModule();
		int					_x;
		int					_y;
		int					_sizeX;
		int					_sizeY;
		std::string			_model;
		std::string			_clockSpeed;
		int					_core;
		float				_activity;
		std::list<float>	_previousActivity;
};

#endif
