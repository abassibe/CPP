/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 02:53:23 by abassibe          #+#    #+#             */
/*   Updated: 2018/03/29 01:09:16 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shellphone.hpp"

int		contact::nb_contact = 0;

void		print_usage()
{
	std::cout << "Hi customers, and thank you for purchasing our amazing and revolutionary product !\n";
	std::cout << "This product is not very difficult to handle.\n";
	std::cout << "You just have 3 commands to know :\n\n";
	std::cout << "\t- ADD -\n";
	std::cout << "\t\tUse this commands to add a new contact\n";
	std::cout << "\t- SEARCH -\n";
	std::cout << "\t\tUse this commands to research an existing contact\n";
	std::cout << "\t- EXIT -\n";
	std::cout << "\t\tUse this commands to exit the program\n\n";
}

bool		cin_fail()
{
	if (std::cin.eof())
		exit (0);
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(10, '\n');
		std::cout << "\033[0;31mInvalid argument.\33[0;0m\n";
		std::cout << "Press Enter to continue.\n";
		std::cin.get();
		return false;
	}
	return true;
}

contact		add_contact()
{
	contact		contact;
	std::string	tmp;

	std::cin.get();
label1:
	std::cout << "\nPlease enter a First Name :\n";
	std::getline(std::cin, tmp);
	contact.set_first_name(tmp);
	if (!cin_fail())
		goto label1;
	std::cout << "Please enter a Last Name :\n";
	std::getline(std::cin, tmp);
	contact.set_last_name(tmp);
	if (!cin_fail())
		goto label1;
	std::cout << "Please enter a Nickname :\n";
	std::getline(std::cin, tmp);
	contact.set_nickname(tmp);
	if (!cin_fail())
		goto label1;
	std::cout << "Please enter a login :\n";
	std::getline(std::cin, tmp);
	contact.set_login(tmp);
	if (!cin_fail())
		goto label1;
	std::cout << "Please enter a postal address :\n";
	std::getline(std::cin, tmp);
	contact.set_postal_address(tmp);
	if (!cin_fail())
		goto label1;
	std::cout << "Please enter a mail address :\n";
	std::getline(std::cin, tmp);
	contact.set_mail_address(tmp);
	if (!cin_fail())
		goto label1;
	std::cout << "Please enter a phone number :\n";
	std::getline(std::cin, tmp);
	contact.set_phone_number(tmp);
	if (!cin_fail())
		goto label1;
	std::cout << "Please enter a birthday date :\n";
	std::getline(std::cin, tmp);
	contact.set_birthday_date(tmp);
	if (!cin_fail())
		goto label1;
	std::cout << "Please enter a favorite meal :\n";
	std::getline(std::cin, tmp);
	contact.set_favorite_meal(tmp);
	if (!cin_fail())
		goto label1;
	std::cout << "Please enter a underwear color :\n";
	std::getline(std::cin, tmp);
	contact.set_underwear_color(tmp);
	if (!cin_fail())
		goto label1;
	std::cout << "Please enter a darkest secret :\n";
	std::getline(std::cin, tmp);
	contact.set_darkest_secret(tmp);
	if (!cin_fail())
		goto label1;
	contact.set_index(contact::nb_contact + 1);
	return (contact);
}

void		print_arg(std::string str)
{
	int		i = -1;

	while (str[++i])
	{
		std::cout << str[i];
		if (i == 8 && str[9])
		{
			std::cout << '.';
			i += 2;
			break ;
		}
	}
	while (i++ < 10)
		std::cout << ' ';
}

void		print_contact(contact *contact)
{
	int		i = -1;

	std::cout << "\nYou will find below the list of your contacts\n\n";
	std::cout << "\033[0;4m  Index   \033[0;0m\033[0;32m|";
	std::cout << "\033[0;4mFirst Name\033[0;0m\033[0;32m|";
	std::cout << "\033[0;4mLast Name \033[0;0m\033[0;32m|";
	std::cout << "\033[0;4m Nickname \033[0;0m\n";
	while (++i < contact::nb_contact)
	{
		std::cout << "    " << contact[i].get_index() << "     ";
		std::cout << "\033[0;32m|\033[0;0m";
		print_arg(contact[i].get_first_name());
		std::cout << "\033[0;32m|\033[0;0m";
		print_arg(contact[i].get_last_name());
		std::cout << "\033[0;32m|\033[0;0m";
		print_arg(contact[i].get_nickname());
		std::cout << std::endl << std::endl;
	}
}

void		apply_commands(std::string input, contact *contact)
{
	int		index = 0;

	if (input.compare("ADD") == 0 || input.compare("add") == 0)
	{
		if (contact::nb_contact >= 8)
			std::cout << "\033[0;031mYou have too many contact (8 is the maximum), don't be so sociable\033[0;0m\n";
		else
		{
			contact[contact::nb_contact] = add_contact();
			contact::nb_contact++;
		}
	}
	else if (input.compare("SEARCH") == 0 || input.compare("search") == 0)
	{
		if (contact::nb_contact == 0)
			std::cout << "\n\033[0;31mIt appears that you have no contact, go make some friends then come back\033[0;0m\n";
		else
		{
			print_contact(contact);
			do
			{
				std::cout << "\nPlease, select an index :\n";
				std::cin >> index;
				if (std::cin.eof())
					exit (0);
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(10, '\n');
					std::cout << "Please enter a numeric value\n";
				}
				if (index < 1 || index > contact::nb_contact)
				{
					std::cout << "\n\033[0;031mInvalid index, please refer to the list\033[0;0m\n";
					print_contact(contact);
				}
			}
			while (index < 1 || index > contact::nb_contact);
			contact[index - 1].print();
		}
	}
}

int			main()
{
	std::string		input;
	contact			contact[8];

	print_usage();
	do
	{
		std::cout << "\nPlease enter a command :\n";
		std::cin >> input;
		if (std::cin.eof())
			exit (0);
		apply_commands(input, contact);
	}
	while (input.compare("EXIT") != 0 && input.compare("exit") != 0);
	return (0);
}
