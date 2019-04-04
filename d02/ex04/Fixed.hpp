/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 11:22:04 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/27 14:37:02 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(int const value);
		Fixed(float const value);
		Fixed(Fixed const& copy);
		~Fixed();
		Fixed	&operator=(Fixed const& copy);
		Fixed	operator+(Fixed const& a) const;
		Fixed	operator-(Fixed const& a) const;
		Fixed	operator*(Fixed const& a) const;
		Fixed	operator/(Fixed const& a) const;
		bool	operator<(Fixed const& comp) const;
		bool	operator>(Fixed const& comp) const;
		bool	operator<=(Fixed const& comp) const;
		bool	operator>=(Fixed const& comp) const;
		bool	operator==(Fixed const& comp) const;
		bool	operator!=(Fixed const& comp) const;
		Fixed	&operator++();
		Fixed	operator++(int);
		Fixed	&operator--();
		Fixed	operator--(int);
		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int		toInt() const;

	private:
		int					_integerValue;
		static const int	_fractionalValue;
};

std::ostream	&operator<<(std::ostream &o, Fixed const& fixed);
Fixed			&min(Fixed &a, Fixed &b);
const Fixed		&min(Fixed const& a, Fixed const& b);
Fixed			&max(Fixed &a, Fixed &b);
const Fixed		&max(Fixed const& a, Fixed const& b);

#endif
