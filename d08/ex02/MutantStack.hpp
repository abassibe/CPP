/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:57:30 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/03 17:04:24 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <list>

template <class T, class Container = std::deque<T> >
class MutantStack :  public std::stack<T>
{
	public:
		MutantStack<T, Container>() : std::stack<T, Container>() {}
		MutantStack<T, Container>(MutantStack<T, Container> const& copy) : std::stack<T, Container>(copy) {}
		MutantStack<T, Container>		&operator=(MutantStack<T, Container> const& copy)
		{
			*this = std::stack<T, Container>(copy);
			return (*this);
		}
		typedef typename	std::deque<T>::iterator					iterator;
		typedef typename	std::deque<T>::reverse_iterator			reverse_iterator;
		typedef typename	std::deque<T>::const_iterator			const_iterator;
		typedef typename	std::deque<T>::const_reverse_iterator	const_reverse_iterator;
		iterator				begin() { return (this->c.begin()); }
		iterator				end() { return (this->c.end()); }
		reverse_iterator		rbegin() { return (this->c.rbegin()); }
		reverse_iterator		rend() { return (this->c.rend()); }
		const_iterator			cbegin() { return (this->c.cbegin()); }
		const_iterator			cend() { return (this->c.cend()); }
		const_reverse_iterator	crbegin() { return (this->c.crbegin()); }
		const_reverse_iterator	crend() { return (this->c.crend()); }
};

#endif
