#include <iostream>
#include <ctime>
#include <iomanip>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	++_nbAccounts;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";amount:" << _amount << ";closed" << std::endl;
}

Account::Account(void)
{
}

int	Account::getNbAccounts(void) { return (_nbAccounts); }
int	Account::getTotalAmount(void) { return (_totalAmount); }
int	Account::getNbDeposits(void) { return (_totalNbDeposits); }
int	Account::getNbWithdrawals(void) { return (_totalNbWithdrawals); }
int	Account::checkAmount(void) const { return (_amount); }

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
		<< ";total:" << _totalAmount
		<< ";deposits:" << _totalNbDeposits
		<< ";withdrawals:" << _totalNbWithdrawals
		<< std::endl;
}

void	Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";p_amount:" << _amount
		<< ";deposit:" << deposit
		<< ";amount:" << _amount + deposit
		<< ";nb_deposits:" << _nbDeposits + 1
		<< std::endl;
	_amount += deposit;
	_totalAmount += deposit;
	++_nbDeposits;
	++_totalNbDeposits;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	if (withdrawal > _amount)
	{
		std::cout << "index:" << _accountIndex
			<< ";p_amount:" << _amount
			<< ";withdrawal:refused"
			<< std::endl;
		return (false);
	}
	std::cout << "index:" << _accountIndex
		<< ";p_amount:" << _amount
		<< ";withdrawal:" << withdrawal
		<< ";amount:" << _amount - withdrawal
		<< ";nb_withdrawals:" << _nbWithdrawals + 1
		<< std::endl;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	++_nbWithdrawals;
	++_totalNbWithdrawals;
	return (true);
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void)
{
    std::time_t	t = std::time(nullptr);
    std::tm		*now = std::localtime(&t);

    std::cout << "["
              << (now->tm_year + 1900)
              << std::setw(2) << std::setfill('0') << (now->tm_mon + 1)
              << std::setw(2) << std::setfill('0') << now->tm_mday << "_"
              << std::setw(2) << std::setfill('0') << now->tm_hour
              << std::setw(2) << std::setfill('0') << now->tm_min
              << std::setw(2) << std::setfill('0') << now->tm_sec
              << "] ";
}
