/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 19:18:23 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/29 19:27:22 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(Ice const& copy);
		virtual ~Ice();
		Ice					&operator=(Ice const& copy);
		std::string const	&getType() const;
		unsigned int		getXP() const;
		virtual Ice			*clone() const;
		virtual void		use(ICharacter &target);

	private:
		unsigned int	_xp;
		std::string		_type;
};

#endif
