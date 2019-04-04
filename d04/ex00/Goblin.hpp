/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Goblin.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 12:06:35 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/29 12:21:46 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GOBLIN_HPP
# define GOBLIN_HPP

#include "Victim.hpp"
#include <iostream>

class Goblin : public Victim
{
	public:
		Goblin(std::string name);
		Goblin(Goblin const& copy);
		virtual ~Goblin();
		Goblin			&operator=(Goblin const& copy);
		void			getPolymorphed() const;

	private:
		Goblin();
};

std::ostream	&operator<<(std::ostream &o, Goblin const& victim);

#endif
