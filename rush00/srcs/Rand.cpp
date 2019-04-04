/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rand.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <pprikazs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:23:46 by pprikazs          #+#    #+#             */
/*   Updated: 2019/03/30 17:24:44 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Rand.hpp"
#include <stdlib.h>
#include <ctime>

Rand::Rand(void)
{
    srand(time(NULL));
    return;
}

Rand::Rand(Rand const &)
{
    return;
}

Rand::~Rand(void)
{
    return;
}

bool            Rand::getOneTo(int _fr)
{
    int         val;

    val = rand() % _fr;
    if (val == 0)
        return (1);
    return (0);
}

int            Rand::getOneOf(int base, int to)
{
    int        val;

    val = rand() % to + base;
    return (base);
}
