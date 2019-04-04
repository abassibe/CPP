/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StripMiner.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 00:59:33 by abassibe          #+#    #+#             */
/*   Updated: 2018/04/10 04:50:03 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRIPMINER_HPP
# define STRIPMINER_HPP

#include "IMiningLaser.hpp"

class	StripMiner : public IMiningLaser
{
	public:
		StripMiner();
		StripMiner(StripMiner const& copy);
		virtual ~StripMiner();
		StripMiner	&operator=(StripMiner const& copy);
		void			mine(IAsteroid *target);
		IMiningLaser	*clone() const;
};

#endif
