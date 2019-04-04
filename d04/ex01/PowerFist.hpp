/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 14:10:37 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/29 14:11:33 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWERFIST_HPP
# define POWERFIST_HPP

# include "AWeapon.hpp"

class PowerFist : public AWeapon
{
	public:
		PowerFist();
		PowerFist(PowerFist const& copy);
		virtual ~PowerFist();
		PowerFist			&operator=(PowerFist const& copy);
		virtual void	attack() const;

	protected:
		std::string		_name;
		int				_apCost;
		int				_damage;
};

#endif
