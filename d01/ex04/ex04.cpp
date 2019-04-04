/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 17:03:52 by abassibe          #+#    #+#             */
/*   Updated: 2019/03/26 17:06:59 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int		main()
{
	std::string		brain = "HI THIS IS BRAIN";
	std::string		*ptr_brain = &brain;
	std::string		&ref_brain = brain;

	std::cout << "PTR = " << *ptr_brain << std::endl;
	std::cout << "REF = " << ref_brain << std::endl;
}
