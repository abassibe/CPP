/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WaveScreen.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 11:08:34 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/31 17:04:32 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WAVESCREEN_HPP
# define WAVESCREEN_HPP

# include "BodyScreen.hpp"

class WaveScreen : public BodyScreen
{
	public:
		WaveScreen(int lines, int cols, int y, int x, std::string name);
		WaveScreen(WINDOW *win, int lines, int cols, int y, int x, std::string name);
		WaveScreen(WaveScreen const& copy);
		virtual ~WaveScreen();
		WaveScreen		&operator=(WaveScreen const& copy);
		virtual void	update() const;
		virtual void	clear();

	private:
		WaveScreen();
};

#endif
