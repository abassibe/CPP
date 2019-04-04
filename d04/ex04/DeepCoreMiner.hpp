/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DeepCoreMiner.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 00:59:33 by abassibe          #+#    #+#             */
/*   Updated: 2018/04/10 04:53:58 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEEPCOREMINER_HPP
# define DEEPCOREMINER_HPP

#include "IMiningLaser.hpp"

class	DeepCoreMiner : public IMiningLaser
{
	public:
		DeepCoreMiner();
		DeepCoreMiner(DeepCoreMiner const& copy);
		virtual ~DeepCoreMiner();
		DeepCoreMiner	&operator=(DeepCoreMiner const& copy);
		void			mine(IAsteroid *target);
		IMiningLaser	*clone() const;
};

#endif
