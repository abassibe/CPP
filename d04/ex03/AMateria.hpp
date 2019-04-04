/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 19:06:05 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/29 20:28:47 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	public:
		AMateria(AMateria const& copy);
		AMateria(std::string const& type);
		virtual ~AMateria();
		AMateria			&operator=(AMateria const& copy);
		std::string const	&getType() const;
		unsigned int		getXP() const;
		virtual AMateria	*clone() const = 0;
		virtual void		use(ICharacter &target);

	protected:
		AMateria();
		unsigned int	_xp;
		std::string		_type;
};

#endif
