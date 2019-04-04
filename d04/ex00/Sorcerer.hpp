/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 10:59:22 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/29 12:04:28 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP

#include <iostream>
#include "Victim.hpp"

class Sorcerer
{
	public:
		Sorcerer(std::string name, std::string title);
		Sorcerer(Sorcerer const& copy);
		~Sorcerer();
		Sorcerer	&operator=(Sorcerer const& copy);
		std::string		getName() const;
		std::string		getTitle() const;
		void			polymorph(Victim const& victim) const;

	private:
		Sorcerer();
		std::string		_name;
		std::string		_title;
};

std::ostream	&operator<<(std::ostream &o, Sorcerer const& sorcerer);

#endif
