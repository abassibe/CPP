/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WeaponScreen.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 11:06:57 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/31 17:05:39 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPONSCREEN_HPP
# define WEAPONSCREEN_HPP

# include "BodyScreen.hpp"

class WeaponScreen : public BodyScreen
{
	public:
		WeaponScreen(int lines, int cols, int y, int x, std::string name);
		WeaponScreen(WINDOW *win, int lines, int cols, int y, int x, std::string name);
		WeaponScreen(WeaponScreen const& copy);
		virtual ~WeaponScreen();
		WeaponScreen	&operator=(WeaponScreen const& copy);
		virtual void	update() const;
		virtual void	clear();

	private:
		WeaponScreen();
};

#endif
