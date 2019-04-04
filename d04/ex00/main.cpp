/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 11:10:20 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/29 17:21:05 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include "Goblin.hpp"

int		main()
{
	Sorcerer	robert("Robert","the Magnificent");
	Victim		jim("Jimmy");
	Peon		joe("Joe");
	Goblin		bernard("Bernard");
	std::cout << robert << jim << joe << bernard;
	robert.polymorph(jim);
	robert.polymorph(joe);
	robert.polymorph(bernard);
	return 0;
}
