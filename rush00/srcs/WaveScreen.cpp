/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WaveScreen.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 11:09:24 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/31 17:05:03 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WaveScreen.hpp"

WaveScreen::WaveScreen() : BodyScreen()
{
}

WaveScreen::WaveScreen(int lines, int cols, int y, int x, std::string name) : BodyScreen(lines, cols, y, x, name)
{
	mvwprintw(_win, _lines / 2 - 1, 3, "Wave:");
}

WaveScreen::WaveScreen(WINDOW *win, int lines, int cols, int y, int x, std::string name) : BodyScreen(win, lines, cols, y, x, name)
{
}

WaveScreen::WaveScreen(WaveScreen const& copy) : BodyScreen(copy)
{
}

WaveScreen::~WaveScreen()
{
//	delwin(_win); Detruire ici ou detruit dans parent ?
}

WaveScreen		&WaveScreen::operator=(WaveScreen const& copy)
{
	_win = copy._win;
	_lines = copy._lines;
	_cols = copy._cols;
	_y = copy._y;
	_x = copy._x;
	_name = copy._name;
	return (*this);
}

void	WaveScreen::update() const
{
	box(_win, ACS_VLINE, ACS_HLINE);
	mvwprintw(_win, _lines / 2 - 1, 3, "Wave:");
	wrefresh(_win);
}

void			WaveScreen::clear()
{
	std::string		blank(COLS / 5 - 9, ' ');
	mvaddstr(((LINES / 10) * 9) + _lines / 2 - 1, COLS - (COLS / 5) + 8, blank.c_str());
}
