/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:07:22 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/03 15:48:27 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span() : _capacity(0), _size(0), _array(new int())
{
}

Span::Span(unsigned int n) : _capacity(n), _size(0), _array(new int[n])
{
}

Span::Span(Span const& copy) : _capacity(copy._capacity), _size(copy._size), _array(new int[_capacity])
{
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = copy._array[i];
}

Span::~Span()
{
	delete _array;
}

Span	&Span::operator=(Span const& copy)
{
	_capacity = copy._capacity;
	_size = copy._size;
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = copy._array[i];
	return (*this);
}

void	Span::addNumber(int const& number)
{
	if (_size >= _capacity)
		throw OutOfRangeException();
	_array[_size] = number;
	_size++;
}

int		Span::shortestSpan() const
{
	if (_size <= 1)
		throw MissingElementException();
	int		ret = INT_MAX;
	for (unsigned int i = 0; i < _size - 1; i++)
		for (unsigned int j = i + 1; j < _size; j++)
			if (ret > abs(_array[i] - _array[j]))
				ret = abs(_array[i] - _array[j]);
	return (ret);
}

int		Span::longestSpan() const
{
	if (_size <= 1)
		throw MissingElementException();
	int		shortestNumber = *(std::min_element(_array, _array + _size));
	int		longestNumber = *(std::max_element(_array, _array + _size));
	return (abs(longestNumber - shortestNumber));
}

void	Span::addRandomNumber(unsigned int n)
{
	std::random_device	rd;
	for (unsigned int i = _size; i < n; i++)
	{
		if (i >= _capacity)
			throw OutOfRangeException();
		_array[_size] = rd();
		_size++;
	}
}

unsigned int	Span::size() const
{
	return (_size);
}

int				*Span::getArray() const
{
	return (_array);
}

std::ostream	&operator<<(std::ostream &o, Span const& span)
{
	int		*tmp = span.getArray();
	o << "[";
	for (unsigned int i = 0; i < span.size(); i++)
	{
		o << std::to_string(tmp[i]);
		if (i + 1 < span.size())
			o << ", ";
	}
	o << "]" << std::endl;
	return (o);
}

Span::OutOfRangeException::OutOfRangeException() throw()
{}

Span::OutOfRangeException::OutOfRangeException(OutOfRangeException const& copy) throw()
{
	(void)copy;
}

Span::OutOfRangeException::~OutOfRangeException() throw()
{}

Span::OutOfRangeException	&Span::OutOfRangeException::operator=(OutOfRangeException const& copy) throw()
{
	(void)copy;
	return (*this);
}

const char					*Span::OutOfRangeException::what() const throw()
{
	return ("Out of capacity");
}

Span::MissingElementException::MissingElementException() throw()
{}

Span::MissingElementException::MissingElementException(MissingElementException const& copy) throw()
{
	(void)copy;
}

Span::MissingElementException::~MissingElementException() throw()
{}

Span::MissingElementException	&Span::MissingElementException::operator=(MissingElementException const& copy) throw()
{
	(void)copy;
	return (*this);
}

const char					*Span::MissingElementException::what() const throw()
{
	return ("Not enough element");
}
