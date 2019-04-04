/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IAsteroid.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 01:11:08 by abassibe          #+#    #+#             */
/*   Updated: 2018/04/10 04:48:44 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IASTEROID_HPP
# define IASTEROID_HPP

# include <string>

class	DeepCoreMiner;
class	StripMiner;

class	IAsteroid
{
	public:
		virtual ~IAsteroid() {}
		virtual std::string		beMined(DeepCoreMiner *laser) const = 0;
		virtual std::string		beMined(StripMiner *laser) const = 0;
		virtual std::string		getName() const = 0;
};

#endif
