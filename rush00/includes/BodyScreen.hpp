/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    BodyScreen.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 10:23:58 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/31 17:27:21 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BODYSCREEN_HPP
# define BODYSCREEN_HPP

# include <ncurses.h>
# include "IScreen.hpp"
# include "Player.hpp"
# include "Enemies.hpp"

class BodyScreen : public IScreen
{
	public:
		BodyScreen(int lines, int cols, int y, int x, std::string name);
		BodyScreen(WINDOW *win, int lines, int cols, int y, int x, std::string name);
		BodyScreen(BodyScreen const& copy);
		virtual ~BodyScreen();
		BodyScreen				&operator=(BodyScreen const& copy);
		virtual void			update() const;
		virtual void			setWindow(WINDOW *win, int const lines, int const cols, int const y, int const x);
		virtual WINDOW			*getWindow() const;
		virtual int				getLines() const;
		virtual int				getCols() const;
		virtual int				getY() const;
		virtual int				getX() const;
		virtual std::string		getName() const;
		virtual void			clear();
		void					drawPlayer(Player const& player);
		void					erasePlayer(Player const& player);
		void					drawEnemies(Enemies &enemie);
		void					eraseEnemies(Enemies const& enemie);
		void					drawPlayerShot(Shot *shot);

	protected:
		BodyScreen();
		WINDOW			*_win;
		int				_lines;
		int				_cols;
		int				_y;
		int				_x;
		std::string		_name;
};

#endif
