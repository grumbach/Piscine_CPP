// ************************************************************************** //
//                                                                            //
//                Account.class.cpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 2018                      //
//                Last update : Wed Jan 04 14:54:06 2018                      //
//                Made by : Dream Employee agrumbac                           //
//                                                                            //
// ************************************************************************** //

#include <ctime>
#include <iostream>
#include "Account.class.hpp"

int				Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int				Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int				Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int				Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void			Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

//[20150406_153629] index:0;amount:42;created
Account::Account( int initial_deposit )
{
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";created" << std::endl;
}

//[20150406_153629] index:7;amount:8942;closed
Account::~Account( void )
{
	Account::_nbAccounts--;
	Account::_totalAmount -= this->_amount;
	Account::_totalNbDeposits -= this->_nbDeposits;
	Account::_totalNbWithdrawals -= this->_nbWithdrawals;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";closed" << std::endl;
}

//[20150406_153629] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
void			Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";

	//check for overflows
	if (Account::_totalAmount + deposit > Account::_totalAmount)
	{
		Account::_totalAmount += deposit;
		Account::_totalNbDeposits++;
		this->_amount += deposit;
		this->_nbDeposits++;
		std::cout << "deposit:" << deposit << ";";
		std::cout << "amount:" << this->_amount << ";";
		std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
	}
	else
	{
		std::cout << "deposit:refused" << std::endl;
	}
}

//[20150406_153629] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
bool			Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";

	if (this->_amount - withdrawal < this->_amount && \
		this->_amount - withdrawal > 0)
	{
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		std::cout << "withdrawal:" << withdrawal << ";";
		std::cout << "amount:" << this->_amount << ";";
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (true);
	}
	else
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
}

int				Account::checkAmount( void ) const
{
	return (this->_amount);
}

//[20150406_153629] index:0;amount:42;deposits:0;withdrawals:0
void			Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void			Account::_displayTimestamp( void )
{
	char		str[100];
	std::time_t	t = std::time(nullptr);

	if (std::strftime(str, sizeof(str), "[%Y%m%d_%H%M%S] ", std::localtime(&t)))
		std::cout << str;
}

Account::Account( void )
{ }

int		Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int		Account::_totalNbDeposits = 0;
int		Account::_totalNbWithdrawals = 0;
