/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 19:26:19 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/29 19:27:17 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(Cure const& copy);
		virtual ~Cure();
		Cure				&operator=(Cure const& copy);
		std::string const	&getType() const;
		unsigned int		getXP() const;
		virtual Cure		*clone() const;
		virtual void		use(ICharacter &target);

	private:
		unsigned int	_xp;
		std::string		_type;
};

#endif
