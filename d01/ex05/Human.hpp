/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 17:25:54 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/26 17:46:38 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

#include <string>
#include "Brain.hpp"

class Human
{
	public:
		Human();
		~Human();
		std::string		identify() const;
		const Brain		&getBrain() const;

	private:
		Brain	const _brain;
};

#endif
