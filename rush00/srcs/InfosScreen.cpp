/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InfosScreen.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 10:27:48 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/31 17:02:52 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/InfosScreen.hpp"

InfosScreen::InfosScreen() : BodyScreen()
{
}

InfosScreen::InfosScreen(int lines, int cols, int y, int x, std::string name) : BodyScreen(lines, cols, y, x, name)
{
	mvwprintw(_win, _lines / 2 - 2, 3, "Life: 3" );
	mvwprintw(_win, _lines / 2  + 1, 3, "HP: 5");
}

InfosScreen::InfosScreen(WINDOW *win, int lines, int cols, int y, int x, std::string name) : BodyScreen(win, lines, cols, y, x, name)
{
}

InfosScreen::InfosScreen(InfosScreen const& copy) : BodyScreen(copy)
{
}

InfosScreen::~InfosScreen()
{
//	delwin(_win); Detruire ici ou detruit dans parent ?
}

InfosScreen		&InfosScreen::operator=(InfosScreen const& copy)
{
	_win = copy._win;
	_lines = copy._lines;
	_cols = copy._cols;
	_y = copy._y;
	_x = copy._x;
	_name = copy._name;
	return (*this);
}
