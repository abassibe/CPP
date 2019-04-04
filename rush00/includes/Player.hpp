/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 12:01:01 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/31 17:44:16 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "Weapon.hpp"
# include "Shot.hpp"

class Player
{
	public:
		Player(Weapon *weapon);
		Player(Player const& copy);
		~Player();
		Player			&operator=(Player const& copy);
		void			equipNewWeapon(Weapon *weapon);
		Shot			*attack() const;
		void			takeDamage(int const damage);
		int				hpLeft() const;
		int				lifeLeft() const;
		std::string		getShape() const;
		void			setPos(int y, int x);
		int				getY() const;
		int				getX() const;
		bool			isGameOver;

	private:
		Player();
		Weapon			*_weapon;
		std::string		_shape;
		int				_hp;
		int				_life;
		int				_yPos;
		int				_xPos;
};

#endif
