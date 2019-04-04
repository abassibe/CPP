/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 14:01:21 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/29 14:11:11 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

# include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
	public:
		PlasmaRifle();
		PlasmaRifle(PlasmaRifle const& copy);
		virtual ~PlasmaRifle();
		PlasmaRifle			&operator=(PlasmaRifle const& copy);
		virtual void	attack() const;

	protected:
		std::string		_name;
		int				_apCost;
		int				_damage;
};

#endif
