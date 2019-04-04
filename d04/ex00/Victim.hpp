/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 11:30:00 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/29 12:19:40 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

#include <iostream>

class Victim
{
	public:
		Victim(std::string name);
		Victim(Victim const& copy);
		virtual ~Victim();
		Victim			&operator=(Victim const& copy);
		std::string		getName() const;
		virtual void	getPolymorphed() const;

	protected:
		Victim();
		std::string		_name;
};

std::ostream	&operator<<(std::ostream &o, Victim const& victim);

#endif
