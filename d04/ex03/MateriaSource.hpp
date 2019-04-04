/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 20:07:23 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/29 20:13:32 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(MateriaSource const& copy);
		virtual ~MateriaSource();
		MateriaSource		&operator=(MateriaSource const& copy);
		virtual void		learnMateria(AMateria *m);
		virtual AMateria	*createMateria(std::string const & type);

	private:
		AMateria	*_materia[4];
};

#endif
