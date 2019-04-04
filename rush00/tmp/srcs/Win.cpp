/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Win.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <pprikazs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 19:39:32 by pprikazs          #+#    #+#             */
/*   Updated: 2019/03/31 21:43:34 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <iostream>
#include "Win.hpp"

Win::Win(void)
{
	return ;
}

Win::Win(int lines, int cols, int x, int y, std::string name) :
	_name(name)
{
	_sq = new Square(y, x, cols, lines);

	_win = subwin(stdscr, lines, cols, x, y);
	box(_win, ACS_VLINE, ACS_HLINE);
}

Win::Win(Win const& copy) :
    _name(copy._name),
	_win(copy._win)
{
	_sq = copy._sq;
}

Win::~Win()
{
	delwin(_win);
}

Win               &Win::operator=(Win const& copy)
{
	_win = copy._win;
	_sq = copy._sq;
	_name = copy._name;
	return (*this);
}

std::string		 Win::getName() const
{
	return (_name);
}

WINDOW	         *Win::getWindow() const
{
	return (_win);
}

Square          *Win::getSq() const
{
    return (_sq);
}

void	        Win::update() const
{
	box(_win, ACS_VLINE, ACS_HLINE);
	wrefresh(_win);
}

void		    Win::clear()
{
	std::string		blank(COLS - 2, ' ');
	for (int i = (LINES / 10) + 1; i < (LINES / 10) * 9; i++)
		mvaddstr(i, 1, blank.c_str());

	//std::string		blank(COLS - 2, ' ');
	//for (int i = this->getSq()->getH() + 1; i < this->getSq()->getW(); i++)
	//	mvaddstr(i, 1, blank.c_str());
}

void           Win::drawRelativeTo(Square *sq, const char *str)
{
    mvwprintw(_win, sq->getY(), sq->getX(), str);
}

void          Win::drawAbsolute(Square *sq, const char *str)
{

    mvaddstr(sq->getY(), sq->getX(), str);
}

void          Win::drawAbsolute(int y, int x, const char *str)
{
    mvwprintw(_win, y, x, str);
}
