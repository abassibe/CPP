/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 10:26:37 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/03 11:13:51 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "test.hpp"

template<typename T> void	swap(T &a, T &b)
{
	T	tmp = a;

	a = b;
	b = tmp;
}

template<typename T> T		&min(T &a, T &b)
{
	return (a < b ? a : b);
}

template<typename T> T		&max(T &a, T &b)
{
	return (a > b ? a : b);
}


int		main()
{
	{
		int		a = 10;
		int		b = 20;
		std::cout << "a = " << a << std::endl << "b = " << b << std::endl;
		swap(a, b);
		std::cout << "a after swap = " << a << std::endl << "b after swap = " << b << std::endl;
	}
	{
		int		a = 10;
		int		b = 20;
		std::cout << std::endl;
		std::cout << "a = " << a << std::endl << "b = " << b << std::endl;
		std::cout << "Min between a & b is: " << min<int>(a, b) << std::endl;
		std::cout << "Max between a & b is: " << max<int>(a, b) << std::endl;
	}
	{
		std::string		a = "42";
		std::string		b = "21";
		std::cout << std::endl;
		std::cout << "a = " << a << std::endl << "b = " << b << std::endl;
		std::cout << "Min between a & b is: " << ::min<std::string>(a, b) << std::endl;
		std::cout << "Max between a & b is: " << ::max<std::string>(a, b) << std::endl;
	}
	{
		std::cout << std::endl << "SUBJECT TEST" << std::endl;
		int		a = 2;
		int		b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
}
