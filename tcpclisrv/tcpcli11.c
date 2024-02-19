#include "unp.h"

int main(int argc, char **argv){
    int sockfd;
    struct sockaddr_in servaddr;

    if(2 != argc){
        fprintf(stderr, "usage: tcpcli <IPaddress>.\n");
        exit(EXIT_FAILURE);
    }

    sockfd = Socket(AF_INET, SOCK_STREAM, 0);

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    Connect(sockfd, (SA*)&servaddr, sizeof(servaddr));

    str_cli(stdin, sockfd);
    
    Close(sockfd);
    exit(0);
}
