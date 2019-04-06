/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUActivityModule.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:47:40 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/06 17:36:56 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPUACTIVITYMODULE_HPP
# define CPUACTIVITYMODULE_HPP

# include <list>
# include <sys/sysctl.h>
# include <mach/mach_init.h>
# include <mach/mach_error.h>
# include <mach/mach_host.h>
# include <mach/vm_map.h>
# include <unistd.h>
# include "IMonitorModule.hpp"

class CPUActivityModule : public IMonitorModule
{
	public:
		CPUActivityModule(int x, int y, int sizeX = 80, int sizeY = 15);
		CPUActivityModule(CPUActivityModule const& copy);
		virtual ~CPUActivityModule();
		CPUActivityModule			&operator=(CPUActivityModule const& copy);
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
		CPUActivityModule();
		int					_x;
		int					_y;
		int					_sizeX;
		int					_sizeY;
		std::list<float>	_previousActivity;
};

#endif
