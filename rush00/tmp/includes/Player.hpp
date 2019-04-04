/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <pprikazs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 20:54:56 by pprikazs          #+#    #+#             */
/*   Updated: 2019/03/31 18:57:46 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "Weapon.hpp"
# include "Square.hpp"
# include "Shot.hpp"

class Player
{
	public:
        static bool		isGameOver;

        Player(Square *);
		Player(Weapon *, Square *);
		Player(Player const& copy);
		~Player(void);

		Player			&operator=(Player const&);

        Square          *getSq(void) const;
		int				getHp(void) const;
		int				getLife(void) const;
		const char      *getShape(void) const;

        void            setSq(Square *);
		void		    setWeapon(Weapon *);

		void			takeDamage(int const);
		Shot			*attack(void) const;

		void            moveLeft(void);
		void 			moveRight(void);
		void 			moveDown(void);
		void 			moveUp(void);

		const char      *printHp(void);
		const char      *printLife(void);
		const char      *printWeapon(void);

	private:
		Weapon			*_weapon;
        Square          *_sq;
		int				_hp;
		int				_life;
        const char *    _shape;

        Player(void);
};

#endif
