/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 19:00:25 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/26 19:26:11 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

struct	Action
{
	std::string		actionName;
	void			(Human::*f)(std::string const &);
};

	Action		Human::actions[] = {{"meleeAttack", &Human::meleeAttack},
		{"rangedAttack", &Human::rangedAttack},
		{"intimidatingShout", &Human::intimidatingShout}};

void	Human::meleeAttack(std::string const& target)
{
	std::cout << "You punched " << target << "'s face" << std::endl;
}

void	Human::rangedAttack(std::string const& target)
{
	std::cout << "You shooted " << target << std::endl;
}

void	Human::intimidatingShout(std::string const& target)
{
	std::cout << "You start to screaming on " << target << std::endl;
}

void	Human::action(std::string const& action_name, std::string const& target)
{
	for (int i = 0; i < 3; i++)
		if (action_name == actions[i].actionName)
			(this->*actions[i].f)(target);
}
