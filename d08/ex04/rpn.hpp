/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:23:48 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/03 18:26:44 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <list>
# include <iostream>
# include <exception>
# include <map>

class	rpn
{
	public:
		rpn(std::string const& exp);
		rpn(rpn const& copy);
		~rpn();
		rpn		&operator=(rpn const& copy);
		void	print_token();
		void	print_postfix();

		class	NoValidCharacter : public std::exception
		{
			public:
				NoValidCharacter() throw();
				NoValidCharacter(NoValidCharacter const& copy) throw();
				virtual ~NoValidCharacter() throw();
				NoValidCharacter	&operator=(NoValidCharacter const& copy) throw();
				const char	*what() const throw();
		};

		class	WrongImplementation : public std::exception
		{
			public:
				WrongImplementation() throw();
				WrongImplementation(WrongImplementation const& copy) throw();
				virtual ~WrongImplementation() throw();
				WrongImplementation		&operator=(WrongImplementation const& copy) throw();
				const char	*what() const throw();
		};

	private:
		rpn();
		std::list<std::string>	_token;
		std::list<std::string>	_fixed;
		void	fix();
		void	replace_operator(std::list<std::string>::iterator it);
};

#endif
