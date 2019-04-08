/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 12:54:27 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/06 17:40:13 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <SFML/Graphics.hpp>
#include "../includes/HostModule.hpp"
#include "../includes/OSModule.hpp"
#include "../includes/DateModule.hpp"
#include "../includes/CPUModule.hpp"
#include "../includes/RAMModule.hpp"
#include "../includes/NetworkModule.hpp"
#include "../includes/ConsoleView.hpp"
#include "../includes/CPUActivityModule.hpp"
#include "../includes/RAMActivityModule.hpp"
#include "../includes/GraphicalView.hpp"

void	consoleView()
{
	initscr();
	noecho();
	curs_set(0);
	cbreak();
	timeout(0);

	ConsoleView		view;
	view.addModule(new HostModule(0, 0));
	view.addModule(new OSModule(80, 0));
	view.addModule(new DateModule(160, 0));
	view.addModule(new CPUModule(0, 15));
	view.addModule(new RAMModule(80, 15));
	view.addModule(new NetworkModule(160, 15));
	view.addModule(new CPUActivityModule(0, 30, 80, 20));
	view.addModule(new RAMActivityModule(80, 30, 80, 20));
	while (1)
	{
		view.updateModule();
		view.render();
	}
}

void	graphicalView()
{
	std::cout << "GRAPHICAL" << std::endl;

	GraphicalView view;

    view.addModule(new HostModule(0, 0,800, 150));
    view.addModule(new OSModule(800, 0, 800, 150));
    view.addModule(new DateModule(1600, 0, 800, 150));
    view.addModule(new CPUModule(0, 150, 800, 150));
    view.addModule(new RAMModule(800, 150, 800, 150));
    view.addModule(new NetworkModule(1600, 150, 800, 150));
    view.addModule(new CPUActivityModule(0, 300, 800, 150));
    view.addModule(new RAMActivityModule(800, 300, 800, 150));

	sf::RenderWindow window(sf::VideoMode(2410,750), "Monitor Rush01", sf::Style::Close | sf::Style::Titlebar);

	view._window = &window;

	view.render();
}

int		main(int ac, char **av)
{
	if (ac == 1)
		consoleView();
	else if (strcmp(av[1], "-g") == 0)
		graphicalView();
	else
		std::cout << "Start without argument for console use. Or with -g flag for graphical view." << std::endl;
}
