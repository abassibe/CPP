/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AsteroKreog.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 01:14:09 by abassibe          #+#    #+#             */
/*   Updated: 2018/04/10 04:48:33 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTEROKREOG_HPP
# define ASTEROKREOG_HPP

#include <string>
#include "IAsteroid.hpp"

class	AsteroBocal : public IAsteroid
{
	public:
		AsteroBocal();
		AsteroBocal(AsteroBocal const& copy);
		virtual ~AsteroBocal();
		AsteroBocal		&operator=(AsteroBocal const& copy);
		std::string		beMined(DeepCoreMiner *laser) const;
		std::string		beMined(StripMiner *laser) const;
		std::string		getName() const;
};

#endif
