/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <pprikazs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 19:48:29 by pprikazs          #+#    #+#             */
/*   Updated: 2019/03/31 23:30:06 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <time.h>
#include <unistd.h>
#include "Player.hpp"
#include "Square.hpp"
#include "Win.hpp"
#include "Enemies.hpp"
#include "Vector.hpp"
#include "Shot.hpp"
#include "Rand.hpp"

#define BODY_H (LINES / 10) * 9
#define BODY_W COLS
#define BODY_Y (LINES / 10)
#define INFO_H LINES / 10
#define INFO_W COLS / 1
#define WEAPON_H LINES / 10
#define WEAPON_W COLS / 5
#define WEAPON_Y (LINES / 10) * 9
#define WEAPON_X 0
#define WAVE_H LINES / 10
#define WAVE_W COLS / 5
#define WAVE_Y (LINES / 10) * 9
#define WAVE_X COLS - (COLS / 5)

#define UP 65
#define DOWN 66
#define LEFT 68
#define RIGHT 67
#define SHOT 32

void		drawShots(Win &body, Vector<Shot> &shotVec)
{
	for (size_t i = 0; i < shotVec.getSize(); i++)
	{
		mvwprintw(body.getWindow(), shotVec[i]->getY(), shotVec[i]->getX(), " ");
		if (shotVec[i]->getX() + 1 >= COLS - 2)
			continue;
		shotVec[i]->setX(shotVec[i]->getX() + 1);
		body.drawAbsolute(shotVec[i]->getY(), shotVec[i]->getX(), "-");
	}
	for (size_t i = 0; i < shotVec.getSize(); i++)
	{
		if (shotVec[i] != nullptr && shotVec[i]->getX() + 1 >= COLS - 1)
		{
			shotVec.pop(i);
			i--;
		}
	}
}

void		didCollapse(Win &body, Player &player, Vector<Shot> &shotVector)
{
	(void)shotVector;
	(void)body;
	for (size_t i = 0; i < Enemies::enemies.getSize(); i++)
	{
		if (Enemies::enemies[i]->getSq()->getY() != player.getSq()->getY())
			continue;
		if (Enemies::enemies[i]->getSq()->getX() >= player.getSq()->getX() && Enemies::enemies[i]->getSq()->getX() <= player.getSq()->getX() + 4)
		{
			player.takeDamage(1);
			Enemies::enemies.pop(i);
			i--;
		}
	}
}

int main(void)
{
	initscr();
	noecho();

	srand(time(NULL));

	Win		        body(BODY_H, BODY_W, BODY_Y, 0, "body");
	Win             info(INFO_H, INFO_W, 0, 0, "infos");
	Win             weapon(WEAPON_H,  WEAPON_W, WEAPON_Y, WEAPON_X, "weapon");
	Win             wave(WAVE_H, WAVE_W, WAVE_Y, WAVE_X, "wave");

	//Player
	Square 				player_start(10, body.getSq()->getH() / 2, 1, 1);
	Player				player(&player_start);


	//info
	Square				player_hp(3, info.getSq()->getH() / 3, 1, 1);
	Square				player_life(3, info.getSq()->getH() / 3 * 2 + 1, 1, 1);

	info.drawRelativeTo(&player_hp, player.printHp());
	info.drawRelativeTo(&player_life, player.printLife());

	//weapon
	Square				player_weapon(3, weapon.getSq()->getH() / 2 - 1, 1, 1);

	weapon.drawRelativeTo(&player_weapon, player.printWeapon());



	body.update();
	info.update();
	weapon.update();
	wave.update();
	curs_set(0);

	mvwprintw(body.getWindow(), LINES / 2, COLS / 2, "Press enter to start:");
	while (getch() != 10)
		;
	//clock_t		timeFromBegening = clock();
	cbreak();
	timeout(0);
	body.clear();


	Vector<Shot>	shotVec;
	clock_t		t = clock();
	clock_t				t_enemie;

	t_enemie = clock();
	while (!Player::isGameOver)
	{
		body.update();
		info.update();
		weapon.update();
		wave.update();

		int c = getch();
		switch (c)
		{
			case UP:
				if (player.getSq()->getY() - 1 <= body.getSq()->getY())
					break ;
				body.drawAbsolute(player.getSq(), "     ");
				player.moveUp();
				break ;
			case DOWN:
				if (player.getSq()->getY() + 1 >= body.getSq()->getH())
					break ;
				body.drawAbsolute(player.getSq(), "     ");
				player.moveDown();
				break ;
			case LEFT:
				if (player.getSq()->getX() - 2 <= body.getSq()->getX())
					break ;
				body.drawAbsolute(player.getSq(), "     ");
				player.moveLeft();
				break ;
			case RIGHT:
				if (player.getSq()->getX() + 2 >= body.getSq()->getW() - COLS / 5)
					break ;
				body.drawAbsolute(player.getSq(), "     ");
				player.moveRight();
				break ;
			case SHOT:
				shotVec.push(player.attack());
				break;
		}
		if (clock() - t > 2000)
		{
			drawShots(body, shotVec);
			t = clock();
		}

		Rand::generateEnnemy(t_enemie, body);
		Enemies::drawEnemies(body);
		body.drawAbsolute(player.getSq(), player.getShape());
		didCollapse(body, player, shotVec);
		info.drawRelativeTo(&player_hp, player.printHp());
		info.drawRelativeTo(&player_life, player.printLife());
	}
	mvwprintw(body.getWindow(), LINES / 2, COLS / 2, "Game Over");
	body.clear();
	sleep(10);
	return 0;
}
