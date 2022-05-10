#include "Account.hpp"
#include <iostream>
#include <iomanip>

Account::Account()
{

}

Account::Account(int initial_deposit) : _amount(initial_deposit)
{

}

Account::~Account()
{

}

int	Account::getNbAccounts( void )
{
    std::cout << "je retourne 1" << std::endl;
    return (1);
}

void	Account::displayAccountsInfos( void )
{
    std::cout << "Display Account Infos" << std::endl;
}



int	Account::getTotalAmount( void )
{
    std::cout << "je retourne 2" << std::endl;
    return (2);
}

int	Account::getNbDeposits( void )
{
    std::cout << "je retourne 3" << std::endl;
    return (3);
}

int	Account::getNbWithdrawals( void )
{
    std::cout << "je retourne 4" << std::endl;
    return (4);
}

////////////////////

void	Account::makeDeposit( int deposit )
{
    std::cout << "makeDeposit" << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    std::cout << "checkAmount" << std::endl;
    return (true);
}

int		Account::checkAmount( void ) const
{
    std::cout << "checkAmount" << std::endl;
    return (4);
}

void	Account::displayStatus( void ) const
{
    std::cout << "displayStatus" << std::endl;
}

/////////////

void	Account::_displayTimestamp( void )
{
    std::cout << "_displayTimestamp" << std::endl;
}
