/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 09:34:32 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/31 17:58:42 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <time.h>
#include <unistd.h>
#include "../includes/BodyScreen.hpp"
#include "../includes/InfosScreen.hpp"
#include "../includes/WeaponScreen.hpp"
#include "../includes/WaveScreen.hpp"
#include "../includes/Player.hpp"
#include "../includes/Vector.hpp"

#define UP 65
#define DOWN 66
#define LEFT 68
#define RIGHT 67
#define SHOT 32

void		drawShots(BodyScreen &body, Vector<Shot> &shotVec)
{
	for (size_t i = 0; i < shotVec.getSize(); i++)
	{
		mvwprintw(body.getWindow(), shotVec[i]->getY(), shotVec[i]->getX(), " ");
		if (shotVec[i]->getX() + 1 >= body.getCols())
			continue;
		body.drawPlayerShot(shotVec[i]);
	}
	for (size_t i = 0; i < shotVec.getSize(); i++)
	{
		if (shotVec[i]->getX() + 1 >= body.getCols())
			shotVec.pop(i);
	}
}

int main(void)
{
	initscr();
	noecho();

	BodyScreen		body((LINES / 10) * 9, COLS, LINES / 10, 0, "body");
	InfosScreen		infos(LINES / 10, COLS, 0, 0, "infos");
	WeaponScreen	weapon(LINES / 10, COLS / 5, (LINES / 10) * 9, 0, "weapon");
	WaveScreen		wave(LINES / 10, COLS / 5, (LINES / 10) * 9, COLS - (COLS / 5), "wave");

	body.update();
	infos.update();
	weapon.update();
	wave.update();
	curs_set(0);
	mvwprintw(body.getWindow(), LINES / 2, COLS / 2, "Press enter to start");
	while (getch() != 10)
		;
	cbreak();
	timeout(0);
	body.clear();
	Player	player(nullptr);
	player.setPos(body.getLines() / 2, 10);
	body.drawPlayer(player);

	Vector<Shot>	shotVec;
	Enemies	enemie;
	body.drawEnemies(enemie);
	clock_t t = clock();

	while (!player.isGameOver)
	{
		int c = getch();
		switch (c)
		{
			case UP:
				if (player.getY() - 1 <= 0)
					break ;
				body.erasePlayer(player);
				player.setPos(player.getY() - 1, player.getX());
				break ;
			case DOWN:
				if (player.getY() + 1 >= body.getLines() - LINES / 10)
					break ;
				body.erasePlayer(player);
				player.setPos(player.getY() + 1, player.getX());
				break ;
			case LEFT:
				if (player.getX() - 2 <= 0)
					break ;
				body.erasePlayer(player);
				player.setPos(player.getY(), player.getX() - 2);
				break ;
			case RIGHT:
				if (player.getX() + 2 >= body.getCols() - COLS / 5)
					break ;
				body.erasePlayer(player);
				player.setPos(player.getY(), player.getX() + 2);
				break ;
			case SHOT:
				shotVec.push(player.attack());
				break ;
		}
		if (clock() - t > 100000)
		{
			drawShots(body, shotVec);
			body.eraseEnemies(enemie);
			body.drawEnemies(enemie);
			t = clock();
		}
		body.drawPlayer(player);
		body.update();
	}
	getch();
	endwin();

	return 0;
}
