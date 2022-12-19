#include "../Server.hpp"

void Server::modeUserCmd(User &user, std::vector<std::string> data)
{
    
    /*------- numerics replies for channel mode--------*/

    if (data.size() < 3)
	{
		this->clientMessage(user, ERR_NEEDMOREPARAMS, data[0]);
		return ;
	}

    std::string nickname = data[1];
    std::string flag = data[2];
    std::string mode;

    if (this->userExists(nickname) == false)
    {
        this->clientMessage(user, ERR_USERSDONTMATCH);
        return ;
    }

    if (flag != "+i" && flag != "-o" && flag != "+o" && flag != "+O")
    {
		this->clientMessage(user, ERR_UMODEUNKNOWNFLAG);
		return ;
	}

    /*-------- MODE return ; ---------*/

    if (flag == "-o")
    {
        user.setIRCOper(false);
        return ;
    }

    else if (flag == "-O")            
    {
        user.setOpServer(false);
        return ;
    }


    /*-------- MODE response ---------*/
    else if (flag == "+o")            
    {
        user.setIRCOper(true);
        mode = "Network-Operator";
    }

    else if (flag == "+O")
    {
        user.setOpServer(true); 
        mode = "Server-Operator";
    }
    
    else if (flag == "+i")
    {
        user.setVisibility(false); // du coup utilite ?
        mode = "Invisible";
    }

    this->clientMessage(user, RPL_UMODEIS, mode);

}