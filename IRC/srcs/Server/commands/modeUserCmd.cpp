#include "../Server.hpp"

void Server::modeUserCmd(User &user, std::vector<std::string> data)
{
    
    /*------- numerics replies for channel mode--------*/

    if (data.size() < 3)
	{
		this->clientMessage(user, ERR_NEEDMOREPARAMS, data[0]);
		return ;
	}

    if (data[2] != "+i")
    {
		this->clientMessage(user, ERR_UMODEUNKNOWNFLAG);
		return ;
	}
    std::string nickname = data[2];

    if (this->userExists(nickname) == false)
    {
        this->clientMessage(user, ERR_USERSDONTMATCH);
        return ;
    }

                    
                    /*-------- MODE +i ---------*/


    //this->clientMessage(user, RPL_UMODEIS); // mets en invisible
    user.setVisibility(false); // du coup utilite ?
}