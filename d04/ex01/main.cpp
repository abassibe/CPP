/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 14:14:34 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/29 16:23:17 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "Character.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"

int main()
{
	Character* zaz = new Character("zaz");
	std::cout << *zaz;
	Enemy* b = new RadScorpion();
	Enemy* c = new SuperMutant();
	Enemy* d = new SuperMutant();
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->equip(pf);
	zaz->attack(b);
	std::cout << *zaz;
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	zaz->equip(pf);
	zaz->attack(c);
	std::cout << *zaz;
	zaz->attack(c);
	std::cout << *zaz;
	zaz->recoverAP();
	std::cout << *zaz;
	zaz->attack(d);
	std::cout << *zaz;
	zaz->attack(d);
	std::cout << *zaz;
	zaz->attack(d);
	std::cout << *zaz;
	return 0;
}
