/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkModule.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:47:40 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/05 17:26:22 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETWORKMODULE_HPP
# define NETWORKMODULE_HPP

# include <list>
# include <sstream>
# include <iomanip>
# include "IMonitorModule.hpp"

class NetworkModule : public IMonitorModule
{
	public:
		NetworkModule(int x, int y, int sizeX = 50, int sizeY = 50);
		NetworkModule(NetworkModule const& copy);
		virtual ~NetworkModule();
		NetworkModule			&operator=(NetworkModule const& copy);
		virtual int				getX() const;
		virtual int				getY() const;
		virtual void			setX(int const& x);
		virtual void			setY(int const& y);
		virtual void			setPos(int const& x, int const& y);
		virtual int				getSizeX() const;
		virtual int				getSizeY() const;
		virtual void			setSizeX(int const& sizeX);
		virtual void			setSizeY(int const& sizeY);
		virtual void			setSize(int const& sizeX, int const& sizeY);
		virtual void			updateData();
		std::string				getInputActivity() const;
		std::list<std::string>	getPreviousInputActivity() const;
		std::string				getOutputActivity() const;
		std::list<std::string>	getPreviousOutputActivity() const;

	private:
		NetworkModule();
		std::string				bytes_format(long int bytes);
		int						_x;
		int						_y;
		int						_sizeX;
		int						_sizeY;
		std::string				_inputActivity;
		std::list<std::string>	_previousInputActivity;
		std::string				_outputActivity;
		std::list<std::string>	_previousOutputActivity;
};

#endif
