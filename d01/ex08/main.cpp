/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 06:41:24 by abassibe          #+#    #+#             */
/*   Updated: 2018/03/30 06:55:21 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Human.hpp"

int		main()
{
	Human	human;

	human.action("meleeAttack", "Martin");
	human.action("rangedAttack", "Geeorge");
	human.action("intimidatingShout", "Gollum");
}
