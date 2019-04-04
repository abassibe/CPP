/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maim.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:48:14 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/26 17:02:38 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ZombieHorde.hpp"

int		main()
{
	ZombieHorde		horde(10);

	std::cout << "Oh crap ! A wild horde appears !!" << std::endl;
	horde.announce();
	std::cout << "And they die..." << std::endl;
}
