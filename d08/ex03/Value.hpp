/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Value.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:24:55 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/03 17:25:35 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALUE_HPP
# define VALUE_HPP

# include "IMindOpen.hpp"

class	ValueIncrement : public IMindOpen
{
	public:
		ValueIncrement();
		ValueIncrement(ValueIncrement const& copy);
		virtual ~ValueIncrement();
		ValueIncrement				&operator=(ValueIncrement const& copy);
		int							execut(char *&tab, std::string buff, int &i) const;
};

class	ValueDecrement : public IMindOpen
{
	public:
		ValueDecrement();
		ValueDecrement(ValueDecrement const& copy);
		virtual ~ValueDecrement();
		ValueDecrement				&operator=(ValueDecrement const& copy);
		int							execut(char *&tab, std::string buff, int &i) const;
};

#endif
