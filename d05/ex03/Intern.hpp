/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 16:13:53 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/01 17:56:58 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(Intern const& copy);
		~Intern();
		Intern		&operator=(Intern const& copy);
		Form		*makeForm(std::string form, std::string target);
		typedef Form* (Intern::*InternFPointer)(std::string);

	private:
		Form*				searchForm(std::string n, std::string t);
		Form				*newRobotomy(std::string target);
		Form				*newPresidential(std::string target);
		Form				*newShrubbery(std::string target);
		InternFPointer		_functions[3];
		static std::string	_names[3];
};

#endif
