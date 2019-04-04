/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   While.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:27:55 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/03 17:28:38 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHILE_HPP
# define WHILE_HPP

# include "IMindOpen.hpp"

class	WhileBegin : public IMindOpen
{
	public:
		WhileBegin();
		WhileBegin(WhileBegin const& copy);
		virtual ~WhileBegin();
		WhileBegin					&operator=(WhileBegin const& copy);
		int							execut(char *&tab, std::string buff, int &i) const;
};

class	WhileEnd : public IMindOpen
{
	public:
		WhileEnd();
		WhileEnd(WhileEnd const& copy);
		virtual ~WhileEnd();
		WhileEnd					&operator=(WhileEnd const& copy);
		int							execut(char *&tab, std::string buff, int &i) const;
};

#endif
