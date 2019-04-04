/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 06:26:30 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/03 17:04:59 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

int		main()
{
	std::cout << "My stack compared to the original:" << std::endl;
	MutantStack<int> mstack;
	std::stack<int> stack;

	mstack.push(5);
	mstack.push(17);
	stack.push(5);
	stack.push(17);

	std::cout << "top of stack :\n";
	std::cout << mstack.top() << " | ";
	std::cout << stack.top() << std::endl;

	mstack.pop();
	stack.pop();

	std::cout << "size of stack :\n";
	std::cout << mstack.size() << " | ";
	std::cout << stack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	stack.push(3);
	stack.push(5);
	stack.push(737);
	stack.push(0);

	std::cout << "\nPoping all elements of stakcs :\n";
	while (!mstack.empty() && !stack.empty())
	{
		std::cout <<  mstack.top() << " | " << stack.top() << std::endl;
		mstack.pop();
		stack.pop();
	}

	std::deque<int> deque;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	deque.push_back(3);
	deque.push_back(5);
	deque.push_back(737);
	deque.push_back(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	std::deque<int>::iterator dit = deque.begin();
	std::deque<int>::iterator dite = deque.end();

	std::cout << "all content of stacks using itertors:\n";
	while (it != ite && dit != dite)
	{
		std::cout << *it << " | " << *dit << std::endl;
		++dit;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}
