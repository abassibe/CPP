/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 16:55:18 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/29 18:59:54 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
# define SQUAD_HPP

#include <iostream>
#include "ISquad.hpp"

class Squad : public ISquad
{
	public:
		Squad();
		Squad(Squad const& copy);
		virtual ~Squad();
		Squad	&operator=(Squad const& copy);
		virtual int				getCount() const;
		virtual ISpaceMarine	*getUnit(int n) const;
		virtual int				push(ISpaceMarine *toAdd);

	private:
		ISpaceMarine	**_squad;
		int				_count;
};

#endif
