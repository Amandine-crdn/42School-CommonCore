#include "Account.hpp"

Account::Account( int initial_deposit )
{
}

Account::~Account( void )
{

}

//qui n'existent pas
int	Account::getNbWithdrawals( void )
{
    return (0); 
}
int	Account::getTotalAmount( void )
{
    return (0); 
}
int	Account::getNbDeposits( void )
{
    return (0); 
}
int		Account::checkAmount( void ) const
{
    return (0);
}
void	Account::_displayTimestamp( void ) //retrait du debut static
{

}
int	Account::getNbAccounts( void )
{
   return (0); 
}




//a creer
void	Account::displayAccountsInfos( void )
{

}
void	Account::makeDeposit( int deposit )
{

}
bool	Account::makeWithdrawal( int withdrawal )
{
    return (true);
}
void	Account::displayStatus( void ) const
{
    std::cout << "created" << std::endl;
    std::cout << "closed" << std::endl;
}
	





