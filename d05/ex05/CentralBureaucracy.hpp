/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CentralBureaucracy.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 18:32:15 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/01 18:35:07 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CENTRALBUREAUCRACY_HPP
# define CENTRALBUREAUCRACY_HPP

# include "OfficeBlock.hpp"

class	CentralBureaucracy
{
	public:
		CentralBureaucracy();
		CentralBureaucracy(CentralBureaucracy const& copy);
		~CentralBureaucracy();
		CentralBureaucracy	&operator=(CentralBureaucracy const& copy);
		void				addBureaucrat(Bureaucrat *hired);
		void				queueUp(std::string target);
		void				doBureaucracy();

	private:
		OfficeBlock		_blocks[20];
		int				_nbBureaucrats;
		std::string		_queue[20];
		int				_queueSize;
};

#endif
