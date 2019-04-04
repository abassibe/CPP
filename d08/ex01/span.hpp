/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:50:47 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/03 15:15:17 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <exception>
# include <iostream>
# include <algorithm>
# include <random>

class	Span
{
	public:
		Span(unsigned int n);
		Span(Span const& copy);
		~Span();
		Span	&operator=(Span const& copy);
		void	addNumber(int const& number);
		int		shortestSpan() const;
		int		longestSpan() const;
		void	addRandomNumber(unsigned int n);
		unsigned int	size() const;
		int				*getArray() const;

		class	OutOfRangeException : public std::exception
		{
			public:
				OutOfRangeException() throw();
				OutOfRangeException(OutOfRangeException const& copy) throw();
				~OutOfRangeException() throw();
				OutOfRangeException		&operator=(OutOfRangeException const& copy) throw();
				const char				*what() const throw();
		};

		class	MissingElementException : public std::exception
		{
			public:
				MissingElementException() throw();
				MissingElementException(MissingElementException const& copy) throw();
				~MissingElementException() throw();
				MissingElementException		&operator=(MissingElementException const& copy) throw();
				const char				*what() const throw();
		};

	private:
		Span();
		unsigned int	_capacity;
		unsigned int	_size;
		int				*_array;
};

std::ostream	&operator<<(std::ostream &o, Span const& span);

#endif
