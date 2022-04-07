#include <iostream>
#include <iomanip>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account() {}

Account::Account( int initial_deposit )
    : _amount(initial_deposit)
{
    this->_accountIndex = _nbAccounts;
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex
    << ";amount:" << this->_amount
    <<";created" << std::endl;
    _nbAccounts += 1;
    _totalAmount += this->_amount;
}

Account::~Account( void )
{
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex
    << ";amount:" << this->_amount
    <<";closed" << std::endl;
}

int	Account::getNbAccounts( void ) { return (Account::_nbAccounts); }

int	Account::getTotalAmount( void ) { return (Account::_totalAmount); }

int	Account::getNbDeposits( void ) { return (Account::_totalNbDeposits); }

int	Account::getNbWithdrawals( void ) { return (Account::_totalNbWithdrawals); }

void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << " accounts:" << _nbAccounts
    << ";total:" << _totalAmount
    << ";deposits:" << _totalNbDeposits
    << ";withdrawals:" << _totalNbWithdrawals
    << std::endl;
}

void	Account::makeDeposit( int deposit )
{
    int prev_amount;

    prev_amount = _amount;
    if (deposit >= 0)
    {
        this->_amount += deposit;
        this->_nbDeposits += 1;
        _totalNbDeposits += 1;
        _totalAmount += deposit;

        _displayTimestamp();
        std::cout << " index:" << this->_accountIndex
        << ";p_amount:" << prev_amount
        << ";deposit:" << deposit
        << ";amount:" << this->_amount
        << ";nb_deposits:" << this->_nbDeposits
        << std::endl;
    }
    else
        std::cout << "Error: Deposits can't be negative" << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    int     prev_amount;
    bool    ret_val;

    prev_amount = _amount;
    ret_val = true;
    if (withdrawal >= 0)
    {
        if (_amount - withdrawal >= 0)
        {
            this->_amount -= withdrawal;
            this->_nbWithdrawals += 1;
            _totalNbWithdrawals += 1;
            _totalAmount -= withdrawal;
        
            _displayTimestamp();
            std::cout << " index:" << this->_accountIndex
            << ";p_amount:" << prev_amount
            << ";withdrawal:" << withdrawal
            << ";amount:" << this->_amount
            << ";nb_withdrawals:" << this->_nbWithdrawals
            << std::endl;
        }
        else
        {
            ret_val = false;
            _displayTimestamp();
            std::cout << " index:" << this->_accountIndex
            << ";p_amount:" << prev_amount
            << ";withdrawal:refused" << std::endl;
        }
    }
    else
    {
        ret_val = false;
        std::cout << "Error: Withdrawals can't be negative" << std::endl;
    }
    return (ret_val);
}

int		Account::checkAmount( void ) const { return (this->_amount); }

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex
    << ";amount:" << this->_amount
    << ";deposits:" << this->_nbDeposits
    << ";withdrawals:" << this->_nbWithdrawals
    << std::endl;
}

void	Account::_displayTimestamp( void )
{
    time_t      now;
    struct tm   nowLocal;

    now = time(NULL);
    nowLocal = *localtime(&now);

    std::cout << "["
    << nowLocal.tm_year + 1900
    << std::setfill('0') << std::setw(2) << nowLocal.tm_mon + 1
    << std::setfill('0') << std::setw(2) << nowLocal.tm_mday
    << "_"
    << std::setfill('0') << std::setw(2) << nowLocal.tm_hour
    << std::setfill('0') << std::setw(2) << nowLocal.tm_min
    << std::setfill('0') << std::setw(2) << nowLocal.tm_sec
    << "]";
}
