#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/select.h>

#define BUFFER_SIZE 100
#define MAX_CLIENTS SOMAXCONN


char *str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
    free(buf);
	strcat(newbuf, add);
    free(add);
	return (newbuf);
}



int find_id(int *clientsockets, int fd, int next_id)
{
    for(int i = 0; i < next_id; i++)
    {
        if (clientsockets[i] == fd)
        {
              return (i);                  
        }
    }
    return (-1);
}

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        write(2, "Wrong number of arguments\n", strlen("Wrong number of arguments\n"));
        exit(1);
    }

    int next_id = 0;
    fd_set reads, writes;
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    
	int clientsockets[MAX_CLIENTS];

    char *clients[MAX_CLIENTS];
    for(int i = 0; i < MAX_CLIENTS; i++)
        clients[i] = NULL;

    struct sockaddr_in serverAddress = {0};
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    serverAddress.sin_port = htons(atoi(argv[1]));

    if (bind(socket_fd, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0)
    {
        write(2, "Fatal error\n", strlen("Fatal error\n"));
        exit(1);
    }

    if (listen(socket_fd, MAX_CLIENTS) < 0)
    {
        write(2, "Fatal error\n", strlen("Fatal error\n"));
        exit(1);
    }

    FD_ZERO(&reads);
    FD_SET(socket_fd, &reads);

    int max = socket_fd;

    while(1)
    {
        writes = reads;
        if (select(max + 1, &writes, NULL, NULL, NULL) < 0)
        {
            write(2, "Error select\n", strlen("Error select\n"));
            exit(1);
        }

        for(int fd = 0;fd <= max; fd++)
        {
            if (FD_ISSET(fd, &writes))
            {
                if (fd == socket_fd)
                {
                    int new_client = accept(fd, NULL, NULL);
                    if (new_client < 0)
                     {
                        write(2, "Error accept\n", strlen("Error accept\n"));
                        exit(1);
                    }
                    FD_SET(new_client, &reads);
					if (new_client > max)
						max = new_client;
                    char *buffer = malloc(sizeof(char) * BUFFER_SIZE);
                    sprintf(buffer, "server: client %d just arrived\n", next_id);
                    for(int i = 0; i < next_id; i++)
                    {
                        if (clientsockets[i] > 0)
                            send(clientsockets[i], buffer, strlen(buffer), 0);
                    }
                    clientsockets[next_id++] = new_client;
                    free(buffer);
                }
                else
                {
                    char *buffer = malloc(sizeof(char) * BUFFER_SIZE);
                    int bytesread = recv(fd, buffer, 1, MSG_DONTWAIT);
                    if (bytesread <= 0)
                    {
                        char *buffer3 = malloc(sizeof(char) * BUFFER_SIZE);

                        int id = find_id(clientsockets, fd, next_id);
                        if (id >= 0)
                        {
                            sprintf(buffer, "server: client %d has left\n", id);
                            clientsockets[id] = -1;
                            free(clients[id]);
                        }
                        for(int i = 0; i < next_id; i++)
                        {
                            if (clientsockets[i] != fd && clientsockets[i] > 0)
                                send(clientsockets[i], buffer, strlen(buffer), 0);
                        }
                        free(buffer);
                        free(buffer3);
                        close(fd);
                        FD_CLR(fd, &reads);
                    }
                    else
                    {
                        int pos = -1;
                        buffer[1] = '\0';
                        for(int i = 0; i < (int)strlen(buffer); i++)
                        {
                            if (buffer[i] == '\n')
                            {
                                pos = i;
                                break;
                            }
                        }
                        
                        if (pos >= 0)
                        {
                            char *buffer2;
                            
                            int id = find_id(clientsockets, fd, next_id);
                            if (id >= 0)
                            {
                                clients[id] = str_join(clients[id], buffer);
                                buffer2 = malloc(sizeof(char) * (strlen(clients[id]) + 20));
                                sprintf(buffer2, "client %d: %s", id, clients[id]);
                                free(clients[id]);
                                clients[id] = NULL;
                            }
                            for(int i = 0; i < next_id; i++)
                            {
                                if (clientsockets[i] != fd && clientsockets[i] > 0 && buffer2)
                                    send(clientsockets[i], buffer2, strlen(buffer2), 0);
                            }
                            if (buffer2)
                                free(buffer2);
                        }
                        else
                        {
                            int id = find_id(clientsockets, fd, next_id);
                            if (id >= 0)
                            {
                                clients[id] = str_join(clients[id], buffer);
                            }
                        }
                    }
                }
            }
        }
    }
}