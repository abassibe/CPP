/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 02:53:40 by abassibe          #+#    #+#             */
/*   Updated: 2018/03/31 03:28:48 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Logger.hpp"

int		main()
{
	{
		Logger	log("log");

		log.log("logToConsole", "1st log into Console");
		log.log("logToFile", "1st log into file");
		log.log("logToFile", "2nd log into file");
		log.log("logToConsole", "2nd log into Console");
	}
	{
		Logger	log("log_v2");
		log.log("logToConsole", "3th log into Console");
		log.log("logToFile", "1st log into another file");
		log.log("logToFile", "2nd log into another file");
		log.log("logToConsole", "4th log into Console");
	}
}
