/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 11:33:41 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/27 14:42:30 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalValue = 8;

Fixed::Fixed() : _integerValue(0)
{
}

Fixed::Fixed(int const value) : _integerValue(value)
{
	_integerValue = value << _fractionalValue;
}

Fixed::Fixed(float const value)
{
	_integerValue = roundf(value * (1 << _fractionalValue));
}

Fixed::Fixed(Fixed const& copy)
{
	_integerValue = copy.getRawBits();
}

Fixed::~Fixed()
{
}

Fixed	&Fixed::operator=(Fixed const& copy)
{
	if (this != &copy)
		_integerValue = copy.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(Fixed const& a) const
{
	return (Fixed(toFloat() + a.toFloat()));
}

Fixed	Fixed::operator-(Fixed const& a) const
{
	return (Fixed(toFloat() - a.toFloat()));
}

Fixed	Fixed::operator*(Fixed const& a) const
{
	return (Fixed(toFloat() * a.toFloat()));
}

Fixed	Fixed::operator/(Fixed const& a) const
{
	return (Fixed(toFloat() / a.toFloat()));
}

bool	Fixed::operator<(Fixed const& comp) const
{
	return (toFloat() < comp.toFloat());
}

bool	Fixed::operator>(Fixed const& comp) const
{
	return (toFloat() > comp.toFloat());
}

bool	Fixed::operator<=(Fixed const& comp) const
{
	return (toFloat() <= comp.toFloat());
}

bool	Fixed::operator>=(Fixed const& comp) const
{
	return (toFloat() >= comp.toFloat());
}

bool	Fixed::operator==(Fixed const& comp) const
{
	return (toFloat() == comp.toFloat());
}

bool	Fixed::operator!=(Fixed const& comp) const
{
	return (toFloat() != comp.toFloat());
}

Fixed	&Fixed::operator++()
{
	_integerValue++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	result(*this);
	operator++();
	return (result);
}

Fixed	&Fixed::operator--()
{
	_integerValue--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	result(*this);
	--(*this);
	return (result);
}

int		Fixed::getRawBits() const
{
	return (_integerValue);
}

void	Fixed::setRawBits(int const raw)
{
	_integerValue = raw;
}

float	Fixed::toFloat() const
{
	return ((float)(_integerValue) / (1 << _fractionalValue));
}

int		Fixed::toInt() const
{
	return ((int)(_integerValue >> _fractionalValue));
}

std::ostream	&operator<<(std::ostream &o, Fixed const& fixed)
{
	o << fixed.toFloat();
	return (o);
}

Fixed	&min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed		&min(Fixed const& a, Fixed const& b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed	&max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed		&max(Fixed const& a, Fixed const& b)
{
	if (a > b)
		return (a);
	return (b);
}
