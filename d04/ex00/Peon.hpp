/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 12:06:35 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/29 12:19:51 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP

#include "Victim.hpp"
#include <iostream>

class Peon : public Victim
{
	public:
		Peon(std::string name);
		Peon(Peon const& copy);
		virtual ~Peon();
		Peon			&operator=(Peon const& copy);
		void			getPolymorphed() const;

	private:
		Peon();
};

std::ostream	&operator<<(std::ostream &o, Peon const& victim);

#endif
