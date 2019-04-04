/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiningBarge.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 01:44:18 by abassibe          #+#    #+#             */
/*   Updated: 2018/04/10 04:48:55 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MININGBARGE_HPP
# define MININGBARGE_HPP

# include "IMiningLaser.hpp"
# include "IAsteroid.hpp"

class	MiningBarge
{
	public:
		MiningBarge();
		MiningBarge(MiningBarge const& copy);
		~MiningBarge();
		MiningBarge		&operator=(MiningBarge const& copy);
		void			equip(IMiningLaser *laser);
		void			mine(IAsteroid *asteroid) const;

	private:
		IMiningLaser	*_laser[4];
};

#endif
