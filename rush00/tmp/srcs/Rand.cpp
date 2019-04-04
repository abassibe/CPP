/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rand.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <pprikazs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:23:46 by pprikazs          #+#    #+#             */
/*   Updated: 2019/03/31 23:17:00 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ctime>
#include "Rand.hpp"
#include "Vector.hpp"
#include "Enemies.hpp"
#include "Win.hpp"

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
    return (val);
}

void            Rand::generateEnnemy(clock_t &t, Win &body)
{
    if (clock() - t > 1000000)
    {
        int nb_ennemie = Rand::getOneOf(1, 1);
        int i = 0;
        while (i < nb_ennemie)
        {
            Square	*enemie_start = new Square(COLS - 2, Rand::getOneOf(body.getSq()->getY(), body.getSq()->getH() - body.getSq()->getY()), 1, 1);
            Enemies::enemies.push(new Enemies(enemie_start, "Zorg", clock()));
            i++;
        }
        t = clock();
    }
}
