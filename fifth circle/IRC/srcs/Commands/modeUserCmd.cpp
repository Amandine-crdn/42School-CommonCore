#include "../Server/Server.hpp"

void Server::modeUserCmd(User &user, std::vector<std::string> data)
{

/* 🍿🍿🍿 ------- Numerics Replies -------- 🍿🍿🍿*/

    if (data.size() < 2)
	{
		this->clientMessage(user, ERR_NEEDMOREPARAMS, data[0]);
		return ;
	}

    std::string nickname = data[1];

    if (this->userExists(nickname) == false)
    {
        this->clientMessage(user, ERR_USERSDONTMATCH);
        return ;
    }
   
    else if (data.size() == 2)
	{
        std::string mode;
        if (user.getVisibility() == false)
            mode = "+i";
        else if (user.getVisibility() == true)
            mode = "-i";
        if (nickname == user.getNickName())
            this->clientMessage(user, RPL_UMODEIS, mode);
	}






/* 🍿🍿🍿 ------- Messages -------- 🍿🍿🍿*/

    else if (data.size() == 3)
    {        
        std::string flag = data[2];
        std::vector<User>::iterator it = this->findUserIt(user.getNickName());

        if (flag == "+i")
        {
            user.setVisibility(false);
                
            for (std::vector<Channel>::iterator itc = this->channels_list.begin(); itc != this->channels_list.end(); itc++)
            {
                for (std::vector<User>::iterator itu = itc->users_list.begin(); itu != itc->users_list.end(); itu++)
                itu->setVisibility(false);
            }
            
            it->setVisibility(false);
            this->littleMessage(user, ": Your MODE is invisible");
        }

        else if (flag == "-i")
        {
            user.setVisibility(true);
                
            for (std::vector<Channel>::iterator itc = this->channels_list.begin(); itc != this->channels_list.end(); itc++)
            {
                for (std::vector<User>::iterator itu = itc->users_list.begin(); itu != itc->users_list.end(); itu++)
                itu->setVisibility(true);
            }
            
            it->setVisibility(true);
            this->littleMessage(user, ": Your MODE is visible");
        }

        else if (flag == "+O")
            this->littleMessage(user, ": The command should be ignored, please use /OPER");

        else if (flag == "-O")
        {
            if (user.getIRCOper() == false)
                this->littleMessage(user, ": You're not an irc operator");
            else
            {
                user.setIRCOper(false);
                this->littleMessage(user, ": You're 'deopping' (removing irc operator status)");
            }
        }

        else
            this->clientMessage(user, ERR_UMODEUNKNOWNFLAG);
    }
}