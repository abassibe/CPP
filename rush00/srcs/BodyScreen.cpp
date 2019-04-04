/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BodyScreen.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 10:27:48 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/31 17:47:30 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BodyScreen.hpp"

BodyScreen::BodyScreen()
{
}

BodyScreen::BodyScreen(int lines, int cols, int y, int x, std::string name) : _lines(lines),
	_cols(cols), _y(y), _x(x), _name(name)
{
	_win = subwin(stdscr, lines, cols, y, x);
	box(_win, ACS_VLINE, ACS_HLINE);
}

BodyScreen::BodyScreen(WINDOW *win, int lines, int cols, int y, int x, std::string name) : _win(win),
	_lines(lines), _cols(cols), _y(y), _x(x), _name(name)
{
}

BodyScreen::BodyScreen(BodyScreen const& copy) : _win(copy._win), _lines(copy._lines), _cols(copy._cols),
	_y(copy._y), _x(copy._x), _name(copy._name)
{
}

BodyScreen::~BodyScreen()
{
	delwin(_win);
}

BodyScreen	&BodyScreen::operator=(BodyScreen const& copy)
{
	_win = copy._win;
	_lines = copy._lines;
	_cols = copy._cols;
	_y = copy._y;
	_x = copy._x;
	_name = copy._name;
	return (*this);
}

void	BodyScreen::update() const
{
	box(_win, ACS_VLINE, ACS_HLINE);
	wrefresh(_win);
}

void	BodyScreen::setWindow(WINDOW *win, int const lines, int const cols, int const y, int const x)
{
	_win = win;
	_lines = lines;
	_cols = cols;
	_y = y;
	_x = x;
}

WINDOW	*BodyScreen::getWindow() const
{
	return (_win);
}

int		BodyScreen::getLines() const
{
	return (_lines);
}

int		BodyScreen::getCols() const
{
	return (_cols);
}

int		BodyScreen::getY() const
{
	return (_y);
}

int		BodyScreen::getX() const
{
	return (_x);
}

std::string		BodyScreen::getName() const
{
	return (_name);
}

void			BodyScreen::clear()
{
	std::string		blank(COLS - 2, ' ');
	for (int i = (LINES / 10) + 1; i < (LINES / 10) * 9; i++)
		mvaddstr(i, 1, blank.c_str());
}

void			BodyScreen::drawPlayer(Player const& player)
{
	mvwprintw(_win, player.getY(), player.getX(), player.getShape().c_str());
}

void			BodyScreen::erasePlayer(Player const& player)
{
	mvaddstr(player.getY() + (LINES / 10), player.getX(), "     ");
}

void			BodyScreen::drawEnemies(Enemies &enemie)
{
	enemie.x -= 1;
	mvwprintw(_win, enemie.y, enemie.x, "X");
}

void			BodyScreen::eraseEnemies(Enemies const& enemie)
{
	mvwprintw(_win, enemie.y, enemie.x, " ");
}

void			BodyScreen::drawPlayerShot(Shot *shot)
{
	shot->setX(shot->getX() + 1);
	mvwprintw(_win, shot->getY(), shot->getX(), "-");
}
