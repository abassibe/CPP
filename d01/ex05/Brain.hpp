/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 17:09:05 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/26 17:28:45 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <sstream>

class Brain
{	
	public:
		Brain();
		~Brain();
		std::string		identify() const;

	private:
		int		synapse;
		int		neuron;
};

#endif
