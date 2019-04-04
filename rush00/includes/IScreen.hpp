/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IScreen.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 10:17:29 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/31 17:03:08 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISCREEN_HPP
# define ISCREEN_HPP

# include <ncurses.h>
# include <iostream>

class IScreen
{
	public:
		virtual ~IScreen() {}
		virtual void			update() const = 0;
		virtual void			setWindow(WINDOW *win, int const lines, int const cols, int const y, int const x) = 0;
		virtual WINDOW			*getWindow() const = 0;
		virtual int				getLines() const = 0;
		virtual int				getCols() const = 0;
		virtual int				getY() const = 0;
		virtual int				getX() const = 0;
		virtual std::string		getName() const = 0;
};

#endif
