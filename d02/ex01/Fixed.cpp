/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 11:33:41 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/27 12:57:32 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalValue = 8;

Fixed::Fixed() : _integerValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const value) : _integerValue(value)
{
	std::cout << "Integer constructor called" << std::endl;
	_integerValue = value << _fractionalValue;
}

Fixed::Fixed(float const value)
{
	std::cout << "Float constructor called" << std::endl;
	_integerValue = roundf(value * (1 << _fractionalValue));
}

Fixed::Fixed(Fixed const& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	_integerValue = copy.getRawBits();
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(Fixed const& copy)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &copy)
		_integerValue = copy.getRawBits();
	return (*this);
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
