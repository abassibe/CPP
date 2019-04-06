/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConsoleView.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 13:03:31 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/06 14:15:58 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSOLEVIEW_HPP
# define CONSOLEVIEW_HPP

# include <vector>
# include <ncurses.h>
# include "IMonitorDisplay.hpp"

class ConsoleView : public IMonitorDisplay
{
	public:
		ConsoleView();
		virtual ~ConsoleView();
		virtual void	updateModule();
		virtual void	render();
		virtual void	addModule(IMonitorModule *toAdd);
		virtual void	removeModule(IMonitorModule const *target);

	private:
		ConsoleView(ConsoleView const& copy);
		ConsoleView						&operator=(ConsoleView const& copy);
		std::vector<IMonitorModule*>	_module;
		std::vector<WINDOW*>			_winModule;
};

#endif
