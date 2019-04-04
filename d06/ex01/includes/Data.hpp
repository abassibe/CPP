/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 03:59:46 by abassibe          #+#    #+#             */
/*   Updated: 2018/04/13 04:35:05 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <string>

struct	Data
{
	std::string		s1;
	int				n;
	std::string		s2;
};

void	*serialize();
Data	*deserialize(void *raw);

# endif
