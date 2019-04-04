/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IO.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:26:33 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/03 17:27:10 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_HPP
# define IO_HPP

#include "IMindOpen.hpp"

class	PrintValue : public IMindOpen
{
	public:
		PrintValue();
		PrintValue(PrintValue const& copy);
		virtual ~PrintValue();
		PrintValue					&operator=(PrintValue const& copy);
		int							execut(char *&tab, std::string buff, int &i) const;
};

class	EnterValue : public IMindOpen
{
	public:
		EnterValue();
		EnterValue(EnterValue const& copy);
		virtual ~EnterValue();
		EnterValue					&operator=(EnterValue const& copy);
		int							execut(char *&tab, std::string buff, int &i) const;
};

#endif
