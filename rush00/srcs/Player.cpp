/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 12:07:42 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/31 23:14:18 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Player.hpp"

Player::Player() : isGameOver(false), _weapon(nullptr), _hp(5), _life(3)
{
}

Player::Player(Weapon *weapon) : isGameOver(false), _weapon(weapon), _hp(5), _life(3)
{
	_shape = ">--->";
}

Player::Player(Player const& copy) : isGameOver(copy.isGameOver),
	_weapon(copy._weapon), _hp(copy._hp), _life(copy._life)
{
}

Player::~Player()
{
	delete (_weapon);
}

Player		&Player::operator=(Player const& copy)
{
	isGameOver = copy.isGameOver;
	_weapon = copy._weapon;
	_hp = copy._hp;
	_life = copy._life;
	return (*this);
}

void		Player::equipNewWeapon(Weapon *weapon)
{
	delete (_weapon);
	_weapon = weapon;
}

Shot			*Player::attack() const
{
	return (new Shot(getY(), getX() + 4, 1));
}

void		Player::takeDamage(int const damage)
{
	_hp -= damage;
	if (_hp <= 0)
	{
		_hp = 0;
		_life--;
		if (_life < 0)
			isGameOver = true;
		else
			_hp = 5;
		return ;
	}
}

int			Player::hpLeft() const
{
	return (_hp);
}

int			Player::lifeLeft() const
{
	return (_life);
}

std::string		Player::getShape() const
{
	return (_shape);
}

void			Player::setPos(int y, int x)
{
	_yPos = y;
	_xPos = x;
}

int				Player::getY() const
{
	return (_yPos);
}

int				Player::getX() const
{
	return (_xPos);
}
