/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 18:57:56 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/26 19:22:37 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

#include <iostream>

struct Action;

class Human
{
	private:
		void	meleeAttack(std::string const& target);
		void	rangedAttack(std::string const& target);
		void	intimidatingShout(std::string const& target);
		static Action	actions[];

	public:
		void	action(std::string const& action_name, std::string const& target);
};

#endif
