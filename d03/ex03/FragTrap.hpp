/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 09:54:28 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/28 11:45:41 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(std::string name);
		FragTrap(FragTrap const& copy);
		~FragTrap();
		FragTrap	&operator=(FragTrap const&copy);
		void		rangedAttack(std::string const& target) const;
		void		meleeAttack(std::string const& target) const;
		void		vaulthunterDotExe(std::string const & target);

	private:
		FragTrap();
};

#endif
