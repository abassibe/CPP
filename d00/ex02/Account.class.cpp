/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 02:03:36 by abassibe          #+#    #+#             */
/*   Updated: 2018/03/28 04:32:37 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.class.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _amount(initial_deposit)
{
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	std::cout << "[20150406_153629] index:" << _accountIndex;
	std::cout << ";amount:" << _amount << ";created\n";
}

Account::~Account()
{
	std::cout << "[20150406_153629] index:" << _accountIndex;
	std::cout << ";amount:" << _amount << ";closed\n";
}

int		Account::getNbAccounts()
{
	static int	nb_account;

	nb_account = _nbAccounts;
	return (nb_account);
}

int		Account::getTotalAmount()
{
	static int	tot_amount;

	tot_amount = _totalAmount;
	return (tot_amount);
}

int		Account::getNbDeposits()
{
	static int	nb_deposits;

	nb_deposits = _totalNbDeposits;
	return (nb_deposits);
}

int		Account::getNbWithdrawals()
{
	static int	nb_withdrawals;

	nb_withdrawals = _totalNbWithdrawals;
	return (nb_withdrawals);
}

int		Account::checkAmount() const
{
	int		amount;

	amount = _amount;
	return (amount);
}

void	Account::makeDeposit(int deposit)
{
	std::cout << "[20150406_153629] index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	std::cout << ";deposit:" << deposit;
	_amount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	std::cout << ";amount:" << _amount;
	std::cout << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	std::cout << "[20150406_153629] index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	if (_amount - withdrawal < 0)
	{
		std::cout << ";withdrawal:refused\n";
		return (false);
	}
	std::cout << ";withdrawal:" << withdrawal;
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;
	std::cout << ";amount:" << _amount;
	std::cout << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

void	Account::displayAccountsInfos()
{
	std::cout << "[20150406_153629] accounts:" << _nbAccounts;
	std::cout << ";total:" << _totalAmount;
	std::cout << ";deposits:" << _totalNbDeposits;
	std::cout << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::displayStatus() const
{
	std::cout << "[20150406_153629] index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;
}
