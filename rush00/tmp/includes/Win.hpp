/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Win.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <pprikazs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 19:32:54 by pprikazs          #+#    #+#             */
/*   Updated: 2019/03/31 20:22:16 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BODYSCREEN_HPP
# define BODYSCREEN_HPP

# include <ncurses.h>
# include <string>
# include "Square.hpp"

class Win
{
	public:
		Win(int x, int y, int lines, int cols, std::string name);
		Win(Win const& copy);
		~Win(void);

		Win				        &operator=(Win const& copy);

        std::string		        getName() const;
        WINDOW			        *getWindow() const;
        Square                  *getSq() const;

		void			        update() const;
		void					clear();

		void          			drawAbsolute(Square *, const char *str);
		void          			drawAbsolute(int y, int x, const char *str);
		void          			drawRelativeTo(Square *, const char *str);


	private :
		std::string		_name;
		WINDOW			*_win;
		Square			*_sq;

		Win(void);
};

#endif
