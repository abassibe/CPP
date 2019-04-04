/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 11:41:22 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/03 12:11:51 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template<typename T> class Array
{
	public:
		Array<T>() : _array(new T()), _size(0) {}
		Array<T>(unsigned int n) : _array(new T(n)), _size(n) {}
		Array<T>(Array const& copy) : _array(new T(copy._size)), _size(copy._size) {}
		~Array() { delete _array; }
		Array<T>	&operator=(Array const& copy)
		{
			_size = copy._size;
			_array = new T(copy._array);
			return (*this);
		}
		T			&operator[](int index)
		{
			if (index < 0 || index > _size)
				throw OutOfRangeException();
			return (_array[index]);
		}
		int		size() const { return (_size); }

		class	OutOfRangeException : public std::exception
		{
			public:
				OutOfRangeException() throw() {}
				OutOfRangeException(OutOfRangeException const& copy) throw() { (void)copy; }
				~OutOfRangeException() throw() {}
				OutOfRangeException	&operator=(OutOfRangeException const& copy) throw() { (void)copy; }
				const char				*what() const throw() { return ("Index out of range."); }
		};


	private:
		T		*_array;
		int		_size;
};

#endif
