/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 13:19:37 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/26 16:35:07 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::Zombie(std::string type, std::string name) : type(type), name(name)
{
}

Zombie::~Zombie()
{
	std::cout << "<\033[0;31m" << name << "\033[0;0m (\033[0;33m" << type << "\033[0;300m)> \033[0;31mDie\033[0;0m: Gggrrgrg..." << std::endl;
}

void	Zombie::announce()
{
	std::cout << "<\033[0;31m" << name << "\033[0;0m (\033[0;33m" << type << "\033[0;300m)> Braiiiiiiinnnssss..." << std::endl;
}
