/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 02:06:39 by abassibe          #+#    #+#             */
/*   Updated: 2018/04/10 05:07:39 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "DeepCoreMiner.hpp"
#include "StripMiner.hpp"
#include "KoalaSteroid.hpp"
#include "AsteroKreog.hpp"
#include "MiningBarge.hpp"

int		main()
{
	MiningBarge		barge;
	IMiningLaser	*l1 = new DeepCoreMiner();
	IMiningLaser	*l2 = new StripMiner();
	IMiningLaser	*l3 = new DeepCoreMiner();
	IMiningLaser	*l4 = new StripMiner();
	IAsteroid		*astro1 = new AsteroBocal();
	IAsteroid		*astro2 = new BocalSteroid();

	barge.equip(l1);
	barge.equip(l2);
	barge.equip(l3);
	barge.equip(l4);
	barge.mine(astro1);
	barge.mine(astro2);
}
