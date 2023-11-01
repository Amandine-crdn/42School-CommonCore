#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/select.h>
#include <sys/types.h>


int ft_error_fatal() {

    write(2, "Error fatale\n", 13);
    return 1;
}

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
	return (newbuf);
}

int main(int argc, char **argv) {
    if (argc != 2) 
        return ft_error_fatal();

	int sockfd, connfd;
	struct sockaddr_in servaddr, cli; 

	// socket create and verification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1)
        return ft_error_fatal();

	printf("Socket successfully created..\n"); 
	bzero(&servaddr, sizeof(servaddr)); 

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(argv[1])); 
  
	// Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
        return ft_error_fatal();
    if (listen(sockfd, 10) != 0)
        return ft_error_fatal();


    fd_set reads;
    fd_set temp_reads;

    FD_ZERO(&reads);
    // FD_ZERO(&writes);
    FD_SET(sockfd, &reads);
    int max_client = 0;
    int id_client[1000];

    for (int i = 0; i < 1000; i++)
        id_client[i] = 0;

    
    int max = sockfd;
    char buffer[5000];
    ssize_t len = 0;

    while(1) {
        
        temp_reads = reads;
        if (select(max + 1, &temp_reads, NULL, NULL, NULL) == -1)
            return ft_error_fatal();

            if (FD_ISSET(sockfd, &temp_reads))
            {
                printf("Socket successfully binded..\n");

                connfd = accept(sockfd, NULL, NULL);
                if (connfd < 0)
                    return ft_error_fatal();

                int i = 0;
                for (; i < max_client && id_client[i] > 0; i++);
                id_client[i] = connfd;
                max_client++;
                FD_SET(id_client[i], &reads);
                if (id_client[i] > max)
                    max = id_client[i];
                printf("max_client = %d\n", max_client);
                printf("max = %d\n", max);


                char bufferSend[100];
                len = sprintf(bufferSend, "server acccept the client %d with fd %d...\n", i, id_client[i]);

                for (int y = 0; y < max_client; y++) {
                    if (id_client[y] > 0 && id_client[y] != connfd ) 
                        send(id_client[y], bufferSend, len, MSG_DONTWAIT);
                    }
            }
            else {
                    
                for (int y = 0; y < max_client; y++) {
                    char bufferReceveid[5000];
                    //  bytesreads = -10;
                    // if (id_client[y] > 0) // && id_client[y] != connfd 
                    ssize_t bytesreads = recv(id_client[y], bufferReceveid, 1, MSG_DONTWAIT); // il envoie un par un
                        // printf( "bytesreads = %ld\n", bytesreads);

                    if (bytesreads == 0)
                    {
                        char buffer2[100];
                        len = sprintf(buffer2, "server kick the client %d with fd %d...\n", y, id_client[y]);

                        for (int i = 0; i < max_client; i++) {
                        if (id_client[i] > 0 && id_client[i] != id_client[y]) 
                            send(id_client[i], buffer2, len, MSG_DONTWAIT);
                        }
                        close(id_client[y]);
                        FD_CLR(id_client[y], &reads);
                        id_client[y] = -1;
                    }
                    else if (bytesreads > 0) {
                        char bufferJoin[5000];
                        char str_cast[2] = {bufferReceveid[0], '\0'};
                        // printf( "%d with fd %d try to send a message...\n", y, id_client[y]);
                        // bufferJoin = str_join(bufferJoin, str_cast);                                                      
                        if (bufferReceveid[0] == '\n') {
                            for (int i = 0; i < max_client; i++) {
                               if (id_client[i] > 0 && id_client[i] != id_client[y]) 
                                   send(id_client[i], bufferJoin, len, MSG_DONTWAIT);
                            }
                        }

                    }
                    // else

                        // puts("here");

                }
            }
    // close(sockfd);
    // FD_CLR(clientfd, &reads);
    }
} 
