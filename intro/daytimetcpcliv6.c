#include "unp.h"

/* sec 1.3, fig 1-6, page 10*/
int main(int argc, char **argv){
    int sockfd = -1, n = 0;
    struct sockaddr_in6	servaddr = {0};
    char recvline[MAXLINE + 1] = {0};

    if(argc != 2){
        fprintf(stderr, "usage: daytimetcpcliv6 <IPaddress>.\n");
        exit(EXIT_FAILURE);
    }

    if(0 > (sockfd = socket(AF_INET6, SOCK_STREAM, 0))){
        perror("socker error");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin6_family = AF_INET6;
    servaddr.sin6_port   = htons(13);	/* daytime server */
    if(0 >= inet_pton(AF_INET6, argv[1], &servaddr.sin6_addr)){
        fprintf(stderr, "inet_pton error for %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if(0 > connect(sockfd, (SA *)&servaddr, sizeof(servaddr))){
        perror("connect error");
        exit(EXIT_FAILURE);
    }

    while(0 > (n = read(sockfd, recvline, MAXLINE))){
        recvline[n] = '\0';	/* null terminate */
        if(fputs(recvline, stdout) == EOF){
            perror("fputs error");
            exit(EXIT_FAILURE);
        }
    }
    if(0 > n){
        perror("read error");
    }
    exit(0);
}