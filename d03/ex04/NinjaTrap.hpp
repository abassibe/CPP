/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 12:09:41 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/28 13:10:04 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap : virtual public ClapTrap
{
	public:
		NinjaTrap(std::string name);
		NinjaTrap(NinjaTrap const& copy);
		~NinjaTrap();
		NinjaTrap	&operator=(NinjaTrap const&copy);
		void		rangedAttack(std::string const& target) const;
		void		meleeAttack(std::string const& target) const;
		void		ninjaShoebox(ClapTrap const& target);
		void		ninjaShoebox(FragTrap const& target);
		void		ninjaShoebox(ScavTrap const& target);
		void		ninjaShoebox(NinjaTrap const& target);

	protected:
		NinjaTrap();
};

#endif
