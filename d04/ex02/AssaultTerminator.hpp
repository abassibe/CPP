/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 18:48:24 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/29 19:01:33 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP

# include <iostream>
# include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine
{
	public:
		AssaultTerminator();
		AssaultTerminator(AssaultTerminator const& copy);
		virtual ~AssaultTerminator();
		AssaultTerminator			&operator=(AssaultTerminator const& copy);
		virtual AssaultTerminator	*clone() const;
		virtual void				battleCry() const;
		virtual void				rangedAttack() const;
		virtual void				meleeAttack() const;
};

#endif
