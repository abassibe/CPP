/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMindOpen.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 02:10:18 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/03 17:28:23 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMINDOPEN_HPP
# define IMINDOPEN_HPP

# include <deque>
# include <list>
# include <iostream>
# include <fstream>
# include <map>
# include <exception>

class	IMindOpen
{
	public:
		virtual ~IMindOpen() {}
		virtual int		execut(char *&tab, std::string buff, int &i) const = 0;
};

#endif
