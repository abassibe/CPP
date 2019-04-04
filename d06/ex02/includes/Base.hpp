/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 05:14:48 by abassibe          #+#    #+#             */
/*   Updated: 2018/04/13 06:12:28 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

class	Base
{
	public:
		virtual ~Base() {}
};

class	A : public Base
{};

class	B : public Base
{};

class	C : public Base
{};

Base	*generator();
void	identify_from_pointer(Base *p);
void	identify_from_reference(Base &p);

#endif
