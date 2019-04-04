/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   KoalaSteroid.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 01:14:09 by abassibe          #+#    #+#             */
/*   Updated: 2018/04/10 04:48:50 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KOALASTEROID_HPP
# define KOALASTEROID_HPP

#include <string>
#include "IAsteroid.hpp"

class	BocalSteroid : public IAsteroid
{
	public:
		BocalSteroid();
		BocalSteroid(BocalSteroid const& copy);
		virtual ~BocalSteroid();
		BocalSteroid		&operator=(BocalSteroid const& copy);
		std::string		beMined(DeepCoreMiner *laser) const;
		std::string		beMined(StripMiner *laser) const;
		std::string		getName() const;
};

#endif
