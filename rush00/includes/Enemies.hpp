/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemies.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 11:33:38 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/31 17:01:40 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMIES_HPP
# define ENEMIES_HPP

# include <iostream>
# include "Weapon.hpp"

class Enemies
{
	public:
		Enemies();
		Enemies(std::string type, Weapon *weapon);
		Enemies(Enemies const& copy);
		virtual ~Enemies();
		Enemies			&operator=(Enemies const& copy);
		//virtual bool	takeShot(Weapon *weapon);
		//virtual void	attack() const;
		int				y;
		int				x;

	protected:
		std::string		_type;
		int				_hp;
		Weapon			*_weapon;
};

#endif
