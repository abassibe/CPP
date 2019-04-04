/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pointer.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:22:10 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/03 17:23:06 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINTER_HPP
# define POINTER_HPP

# include "IMindOpen.hpp"

class	PointerIncrement : public IMindOpen
{
	public:
		PointerIncrement();
		PointerIncrement(PointerIncrement const& copy);
		virtual ~PointerIncrement();
		PointerIncrement			&operator=(PointerIncrement const& copy);
		int							execut(char *&tab, std::string buff, int &i) const;
};

class	PointerDecrement : public IMindOpen
{
	public:
		PointerDecrement();
		PointerDecrement(PointerDecrement const& copy);
		virtual ~PointerDecrement();
		PointerDecrement			&operator=(PointerDecrement const& copy);
		int							execut(char *&tab, std::string buff, int &i) const;
};

#endif
