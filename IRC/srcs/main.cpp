#include "Server/Server.hpp"

/* Define our global var run*/
bool run;

int main(int argc, const char **argv)
{
    if (argc != 3)
    {
       std::cerr << "need this format: /ircserv <port> <password>" << std::endl;
       return (-1);
    }
    Server server;

    run = true;

    server.init_server(argv[1], argv[2]);
    signal(SIGINT, signal_callback_handler);
    while (run)
    {
        server.connect(); //poll + accept
        server.intercept(); //protocole msg
        server.checker(); //first co or next
    }
    server.error("on ferme tout proprement");
}
