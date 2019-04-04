/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 12:36:46 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/03 14:02:31 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iterator>
#include <list>
#include <exception>

template<typename T>int		easyfind(T const& container, int const& target)
{
	if (find(container.begin(), container.end(), target) == container.end())
		throw std::logic_error("No occurence found");
	return (*(find(container.begin(), container.end(), target)));
}
