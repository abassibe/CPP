/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 14:38:27 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/29 15:06:48 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

#include <iostream>

class Enemy
{
	public:
		Enemy(Enemy const& copy);
		Enemy(int hp, std::string const& type);
		virtual ~Enemy();
		Enemy			&operator=(Enemy const& copy);
		std::string		getType() const;
		int				getHP() const;
		virtual void	takeDamage(int amount);

	protected:
		Enemy();
		std::string		_type;
		int				_hp;
};

#endif
