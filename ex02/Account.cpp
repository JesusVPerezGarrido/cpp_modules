/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:48:20 by jeperez-          #+#    #+#             */
/*   Updated: 2025/03/25 15:20:52 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	t::_accountIndex = t::_nbAccounts;
	t::_nbAccounts += 1;
	t::_amount = initial_deposit;
	t::_totalAmount += initial_deposit;
	t::_nbDeposits = 0;
	t::_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout << "index:" << t::_accountIndex << ";";
	std::cout << "amount:" << t::checkAmount() << ";";
	std::cout << "created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << t::_accountIndex << ";";
	std::cout << "amount:" << t::checkAmount() << ";";
	std::cout << "closed" << std::endl;
	t::_totalAmount -= t::checkAmount();
	t::_totalNbDeposits -= t::_nbDeposits;
	t::_totalNbWithdrawals -= t::_nbWithdrawals;
}

int	Account::getNbAccounts( void )
{
	return (t::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (t::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (t::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (t::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	t::_displayTimestamp();
	std::cout << "accounts:" << t::getNbAccounts() << ";";
	std::cout << "total:" << t::getTotalAmount() << ";";
	std::cout << "deposits:" << t::getNbDeposits() << ";";
	std::cout << "withdrawals:" << t::getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	t::_displayTimestamp();
	std::cout << "index:" << t::_accountIndex << ";";
	std::cout << "p_amount:" << checkAmount() << ";";
	std::cout << "deposit:" << deposit << ";";
	t::_amount += deposit;
	t::_totalAmount += deposit;
	std::cout << "amount:" << t::checkAmount() << ";";
	t::_nbDeposits += 1;
	t::_totalNbDeposits += 1;
	std::cout << "nb_deposits:" << t::_nbDeposits << std::endl;
}	

bool	Account::makeWithdrawal(int withdrawal)
{
	t::_displayTimestamp();
	std::cout << "index:" << t::_accountIndex << ";";
	std::cout << "p_amount:" << checkAmount() << ";";
	if (withdrawal < t::checkAmount() && withdrawal > 0)
	{
		std::cout << "withdrawal:" << withdrawal << ";";
		t::_amount -= withdrawal;
		t::_totalAmount -= withdrawal;
		std::cout << "amount:" << checkAmount() << ";";
		t::_nbWithdrawals += 1;
		t::_totalNbWithdrawals += 1;
		std::cout << "nb_withdrawals:" << t::_nbDeposits << std::endl;
		return (true);
	}
	else
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
}

int	Account::checkAmount(void) const
{
	return t::_amount;
}

void	Account::displayStatus(void) const
{
	t::_displayTimestamp();
	std::cout << "index:" << t::_accountIndex << ";";
	std::cout << "amount:" << t::checkAmount() << ";";
	std::cout << "deposits:" << t::_nbDeposits << ";";
	std::cout << "withdrawals:" << t::_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void)
{
	time_t	raw;
	struct tm	*timeinfo;
	char		str[16];
	
	time(&raw);
	timeinfo = localtime (&raw);
	std::cout << "[";
	strftime(str, 16, "%Y%m%d_%H%M%S", timeinfo);
	std::cout << str;
	std::cout << "] ";
}

Account::Account(void)
{
	t::_accountIndex = t::_nbAccounts;
	t::_nbAccounts += 1;
	t::_amount = 0;
	t::_nbDeposits = 0;
	t::_nbWithdrawals = 0;
}
