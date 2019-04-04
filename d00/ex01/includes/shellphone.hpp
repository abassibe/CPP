/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shellphone.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 01:45:30 by abassibe          #+#    #+#             */
/*   Updated: 2018/03/29 01:08:17 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELLPHONE_H
# define SHELLPHONE_H

# include <iostream>
# include <istream>
# include <ios>
# include <iomanip>
# include <string>

class	contact
{
	public:
		contact();
		~contact();
		static int		nb_contact;
		void			print() const;
		void			set_first_name(std::string first_name);
		void			set_last_name(std::string last_name);
		void			set_nickname(std::string nickname);
		void			set_login(std::string login);
		void			set_postal_address(std::string postal_address);
		void			set_mail_address(std::string mail_address);
		void			set_phone_number(std::string phone_number);
		void			set_birthday_date(std::string birthday_date);
		void			set_favorite_meal(std::string favorite_meal);
		void			set_underwear_color(std::string underwear_color);
		void			set_darkest_secret(std::string darkest_secret);
		void			set_index(int index);
		std::string		get_first_name() const;
		std::string		get_last_name() const;
		std::string		get_nickname() const;
		std::string		get_login() const;
		std::string		get_postal_address() const;
		std::string		get_mail_address() const;
		std::string		get_phone_number() const;
		std::string		get_birthday_date() const;
		std::string		get_favorite_meal() const;
		std::string		get_underwear_color() const;
		std::string		get_darkest_secret() const;
		int				get_index() const;

	private:
		std::string		_first_name;
		std::string		_last_name;
		std::string		_nickname;
		std::string		_login;
		std::string		_postal_address;
		std::string		_mail_address;
		std::string		_phone_number;
		std::string		_birthday_date;
		std::string		_favorite_meal;
		std::string		_underwear_color;
		std::string		_darkest_secret;
		int				_number;
};

#endif
