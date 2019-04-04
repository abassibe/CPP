/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shellphone.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 01:45:05 by abassibe          #+#    #+#             */
/*   Updated: 2018/03/29 01:08:43 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shellphone.hpp"

contact::contact()
{
	_number = 0;
}

contact::~contact()
{
}

void			contact::set_first_name(std::string first_name)
{
	_first_name = first_name;
}

void			contact::set_last_name(std::string last_name)
{
	_last_name = last_name;
}

void			contact::set_nickname(std::string nickname)
{
	_nickname = nickname;
}

void			contact::set_login(std::string login)
{
	_login = login;
}

void			contact::set_postal_address(std::string postal_address)
{
	_postal_address = postal_address;
}

void			contact::set_mail_address(std::string mail_address)
{
	_mail_address = mail_address;
}

void			contact::set_phone_number(std::string phone_number)
{
	_phone_number = phone_number;
}

void			contact::set_birthday_date(std::string birthday_date)
{
	_birthday_date = birthday_date;
}

void			contact::set_favorite_meal(std::string favorite_meal)
{
	_favorite_meal = favorite_meal;
}

void			contact::set_underwear_color(std::string underwear_color)
{
	_underwear_color = underwear_color;
}

void			contact::set_darkest_secret(std::string darkest_secret)
{
	_darkest_secret = darkest_secret;
}

void			contact::set_index(int index)
{
	_number = index;
}

std::string		contact::get_first_name() const
{
	std::string		ret;

	ret = _first_name;
	return (ret);
}

std::string		contact::get_last_name() const
{
	std::string		ret;

	ret = _last_name;
	return (ret);
}

std::string		contact::get_nickname() const
{
	std::string		ret;

	ret = _nickname;
	return (ret);
}

std::string		contact::get_login() const
{
	std::string		ret;

	ret = _login;
	return (ret);
}

std::string		contact::get_postal_address() const
{
	std::string		ret;

	ret = _postal_address;
	return (ret);
}

std::string		contact::get_mail_address() const
{
	std::string		ret;

	ret = _mail_address;
	return (ret);
}

std::string		contact::get_phone_number() const
{
	std::string		ret;

	ret = _phone_number;
	return (ret);
}

std::string		contact::get_birthday_date() const
{
	std::string		ret;

	ret = _birthday_date;
	return (ret);
}

std::string		contact::get_favorite_meal() const
{
	std::string		ret;

	ret = _favorite_meal;
	return (ret);
}

std::string		contact::get_underwear_color() const
{
	std::string		ret;

	ret = _underwear_color;
	return (ret);
}

std::string		contact::get_darkest_secret() const
{
	std::string		ret;

	ret = _darkest_secret;
	return (ret);
}

int				contact::get_index() const
{
	int		ret;

	ret = _number;
	return (ret);
}

void	contact::print() const
{
	std::cout << "\n\t----- Contact n°" << get_index() << " -----\n\n";
	std::cout << "First name : " << get_first_name() << std::endl;
	std::cout << "Last name : " << get_last_name() << std::endl;
	std::cout << "Nickname : " << get_nickname() << std::endl;
	std::cout << "Login : " << get_login() << std::endl;
	std::cout << "Postal address : " << get_postal_address() << std::endl;
	std::cout << "Mail address : " << get_mail_address() << std::endl;
	std::cout << "Phone number : " << get_phone_number() << std::endl;
	std::cout << "Birthday date : " << get_birthday_date() << std::endl;
	std::cout << "Favorite meal : " << get_favorite_meal() << std::endl;
	std::cout << "Underwear color : " << get_underwear_color() << std::endl;
	std::cout << "Darkest secret : " << get_darkest_secret() << std::endl << std::endl;
}
