/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemies.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <abassibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 11:33:38 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/31 22:31:26 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMIES_HPP
# define ENEMIES_HPP

# include <iostream>
# include "Weapon.hpp"
# include "Square.hpp"
# include "Vector.hpp"
# include "Win.hpp"

class Enemies
{
	public:
		static Vector<Enemies> 	enemies;

		Enemies(Square *sq, std::string type, Weapon *weapon);
		Enemies(Square *sq, std::string type, clock_t t);
		Enemies(Enemies const& copy);
		virtual ~Enemies();

		Enemies			&operator=(Enemies const& copy);

	//	virtual bool	takeShot(Weapon *weapon);
	//	virtual void	attack() const;

		const char	    *getShape() const;
		Square			*getSq(void) const;
		static void 	setWinSq(Square *sq);
		static void 	drawEnemies(Win &body);


		void             move(Win body);
	private:
		Square					*_sq;
		std::string				_type;
		int						_hp;
		Weapon					*_weapon;
		const char 				*_shape;
		clock_t					_t;

		Enemies(void);
};

#endif
