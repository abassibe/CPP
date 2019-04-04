/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 09:54:28 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/28 13:09:55 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap
{
	public:
		SuperTrap(std::string name);
		SuperTrap(SuperTrap const& copy);
		~SuperTrap();
		SuperTrap	&operator=(SuperTrap const&copy);
		using		FragTrap::rangedAttack;
		using		NinjaTrap::meleeAttack;

	private:
		SuperTrap();
};

#endif
