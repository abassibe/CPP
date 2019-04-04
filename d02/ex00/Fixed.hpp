/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 11:22:04 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/27 11:51:31 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(Fixed const& copy);
		~Fixed();
		Fixed	&operator=(Fixed const& copy);
		int		getRawBits() const;
		void	setRawBits(int const raw);

	private:
		int					_integerValue;
		static const int	_fractionalValue;
};

#endif
