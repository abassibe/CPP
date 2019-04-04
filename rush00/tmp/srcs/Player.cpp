#include <sstream>
#include <ncurses.h>
#include "Player.hpp"
#include "Rand.hpp"

bool Player::isGameOver = false;

Player::Player(void) :
    _sq(nullptr),
    _hp(5),
    _life(3),
    _shape(">--->")
{
    return;
}


// temps one wating having weapon
Player::Player(Square *sq) :
    _sq(sq),
    _hp(5),
    _life(3),
    _shape(">--->")
{
    return;
}

Player::Player(Weapon *weapon, Square *sq) :
    _weapon(weapon),
    _sq(sq),
    _hp(5),
    _life(3),
    _shape(">--->")
{
    return;
}

Player::Player(Player const& copy) :
	_weapon(copy._weapon),
    _hp(copy._hp),
    _life(copy._life)
{
    return;
}

Player::~Player(void)
{
	delete (_weapon);
}

Player		              &Player::operator=(Player const& copy)
{
	_weapon = copy._weapon;
	_hp = copy._hp;
	_life = copy._life;
	return (*this);
}

Square                    *Player::getSq(void) const
{
    return (_sq);
}

int	    		          Player::getHp() const
{
	return (_hp);
}

int			              Player::getLife() const
{
	return (_life);
}

const char	              *Player::getShape() const
{
	return (_shape);
}

void                      Player::setSq(Square *sq)
{
    _sq = sq;
}

void		              Player::setWeapon(Weapon *weapon)
{
    if (weapon != 0)
	   delete (_weapon);
	_weapon = weapon;
}

Shot		*Player::attack() const
{
	return (new Shot(_sq->getY() - (LINES / 10), _sq->getX() + 4, 1));
}

void		              Player::takeDamage(int const damage)
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

void                      Player::moveLeft(void)
{
    _sq->setPos(_sq->getX() - 2, _sq->getY());
}

void 			          Player::moveRight(void)
{
    _sq->setPos(_sq->getX() + 2, _sq->getY());
}

void 			          Player::moveDown(void)
{
    _sq->setPos(_sq->getX(), _sq->getY() + 1);
}

void 			          Player::moveUp(void)
{
    _sq->setPos(_sq->getX(), _sq->getY() - 1);
}

const char                 *Player::printHp(void)
{
    std::string		str = "HP: " + std::to_string(this->getHp());

    return (str.c_str());
}

const char                 *Player::printLife(void)
{
    std::string		str = "Life: " + std::to_string(this->getLife());

    return (str.c_str());
}

const char                  *Player::printWeapon(void)
{
    std::string		str = "Weapon: " + std::to_string(this->getLife());

    return (str.c_str());
}
