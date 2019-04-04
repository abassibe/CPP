/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 19:29:28 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/26 19:39:36 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_HPP
# define LOGGER_HPP

# include <iostream>

struct Log;

class Logger
{
	public:
		Logger(std::string name);
		~Logger();
		void	log(std::string const& dest, std::string const& message);
	private:
		void			logToFile(std::string log);
		void			logToConsole(std::string log);
		std::string		makeLogEntry(std::string message);
		std::string		_name;
		static Log		logs[];
};

#endif
