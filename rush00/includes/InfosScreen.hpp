/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    InfosScreen.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 10:23:58 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/31 17:02:19 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFOSSCREEN_HPP
# define INFOSSCREEN_HPP

# include "BodyScreen.hpp"

class InfosScreen : public BodyScreen
{
	public:
		InfosScreen(int lines, int cols, int y, int x, std::string name);
		InfosScreen(WINDOW *win, int lines, int cols, int y, int x, std::string name);
		InfosScreen(InfosScreen const& copy);
		virtual ~InfosScreen();
		InfosScreen		&operator=(InfosScreen const& copy);

	private:
		InfosScreen();
};

#endif
