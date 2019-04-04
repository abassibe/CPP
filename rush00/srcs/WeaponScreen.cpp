/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WeaponScreen.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 10:27:48 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/31 17:06:13 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WeaponScreen.hpp"

WeaponScreen::WeaponScreen() : BodyScreen()
{
}

WeaponScreen::WeaponScreen(int lines, int cols, int y, int x, std::string name) : BodyScreen(lines, cols, y, x, name)
{
	mvwprintw(_win, _lines / 2 - 1, 3, "Weapon:");
}

WeaponScreen::WeaponScreen(WINDOW *win, int lines, int cols, int y, int x, std::string name) : BodyScreen(win, lines, cols, y, x, name)
{
}

WeaponScreen::WeaponScreen(WeaponScreen const& copy) : BodyScreen(copy)
{
}

WeaponScreen::~WeaponScreen()
{
//	delwin(_win); Detruire ici ou detruit dans parent ?
}

WeaponScreen		&WeaponScreen::operator=(WeaponScreen const& copy)
{
	_win = copy._win;
	_lines = copy._lines;
	_cols = copy._cols;
	_y = copy._y;
	_x = copy._x;
	_name = copy._name;
	return (*this);
}

void	WeaponScreen::update() const
{
	box(_win, ACS_VLINE, ACS_HLINE);
	mvwprintw(_win, _lines / 2 - 1, 3, "Weapon:");
	wrefresh(_win);
}

void			WeaponScreen::clear()
{
	std::string		blank(COLS / 5 - 11, ' ');
	mvaddstr(((LINES / 10) * 9) + _lines / 2 - 1, 10, blank.c_str());
}
