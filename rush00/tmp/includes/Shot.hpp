/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shot.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 16:51:33 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/31 17:32:18 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHOT_HPP
# define SHOT_HPP

class Shot
{
	public:
		Shot();
		Shot(int y, int x, int damage);
		Shot(Shot const& copy);
		~Shot();
		Shot	&operator=(Shot const& copy);
		int		getY() const;
		int		getX() const;
		void	setY(int const& y);
		void	setX(int const& x);
		int		getDamage() const;

	private:
		int		_y;
		int		_x;
		int		_damage;
};

#endif
