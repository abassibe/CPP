/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMiningLaser.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 00:56:07 by abassibe          #+#    #+#             */
/*   Updated: 2018/04/10 05:00:15 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMININGLASER_HPP
# define IMININGLASER_HPP

#include "IAsteroid.hpp"

class	IAsteroid;

class	IMiningLaser
{
	public:
		virtual ~IMiningLaser() {}
		virtual void			mine(IAsteroid *asteroid) = 0;
		virtual IMiningLaser	*clone() const = 0;
};

# endif
