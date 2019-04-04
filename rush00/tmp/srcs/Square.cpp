/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Square.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <pprikazs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 18:12:59 by pprikazs          #+#    #+#             */
/*   Updated: 2019/03/31 22:47:14 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Square.hpp"

Square::Square(void) :
    _x(0),
    _y(0),
    _w(0),
    _h(0)
{
    return;
}

Square::Square(int x, int y, int w, int h) :
    _x(x),
    _y(y),
    _w(w),
    _h(h)
{
    return;
}

Square::Square(Square const & sq) :
    _x(sq.getX()),
    _y(sq.getY()),
    _w(sq.getW()),
    _h(sq.getH())
{
    return;
}

Square::~Square(void)
{
    return;
}

int             Square::getX(void) const
{
    return (this->_x);
}

int             Square::getY(void) const
{
    return (this->_y);
}

int             Square::getH(void) const
{
    return (this->_h);
}

int             Square::getW(void) const
{
    return (this->_w);
}

void            Square::setX(int x)
{
    this->_x = x;
}

void            Square::setY(int y)
{
    this->_y = y;
}

void            Square::setW(int w)
{
    this->_w = w;
}

void            Square::setH(int h)
{
    this->_h = h;
}

void           Square::setPos(int x, int y)
{
    this->setX(x);
    this->setY(y);
}

void          Square::setDim(int w, int h)
{
    this->setW(w);
    this->setH(h);
}
