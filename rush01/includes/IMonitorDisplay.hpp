/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 12:43:37 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/06 13:30:30 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP

# include "IMonitorModule.hpp"

class IMonitorDisplay
{
	public:
		virtual ~IMonitorDisplay() {}
		virtual void	updateModule() = 0;
		virtual void	render() = 0;
		virtual void	addModule(IMonitorModule *toAdd) = 0;
		virtual void	removeModule(IMonitorModule const *target) = 0;
};

#endif
