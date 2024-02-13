#include "unp.h"

/* sec 5.10, fig 5-9, page 109 */
int main(int argc, char **argv){
    int	i, sockfd[5];
    struct sockaddr_in servaddr;

    if(2 != argc){
        fprintf(stderr, "usage: tcpcli <IPaddress>.\n");
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < 5; i++){
        sockfd[i] = Socket(AF_INET, SOCK_STREAM, 0);

        memset(&servaddr, 0, sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sin_port = htons(SERV_PORT);
        Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

        Connect(sockfd[i], (SA*)&servaddr, sizeof(servaddr));
    }

    str_cli(stdin, sockfd[0]);  /* do it all */

    for(i = 0; i < 5; i++){
        Close(sockfd[i]);
    }
    exit(0);
}