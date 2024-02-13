#include "unp.h"

/* sec 1.2, fig 1-5, page 5 */ 
int main(int argc, char **argv){
    int sockfd = -1, n = 0;
    char recvline[MAXLINE + 1] = {0};
    struct sockaddr_in servaddr = {0};

    if(argc != 2){
        fprintf(stderr, "usage: daytimetcpcli <IPaddress>.\n");
        exit(EXIT_FAILURE);
    }

    /* standard */
    if(0 > (sockfd = socket(AF_INET, SOCK_STREAM, 0))){
        perror("socker error");
        exit(EXIT_FAILURE);
    }
    /* exercise 1.3, page 26 */
    // if(0 > (sockfd = socket(9999, SOCK_STREAM, 0))){
    //     perror("socker error");
    //     exit(EXIT_FAILURE);
    // }
        
    /* standard */
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(13);  /* daytime server */
    if(0 >= inet_pton(AF_INET, argv[1], &servaddr.sin_addr)){
        fprintf(stderr, "inet_pton error for %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    /* exercise 1.5, page 26 */
    // memset(&servaddr, 0, sizeof(servaddr));
    // servaddr.sin_family = AF_INET;
    // servaddr.sin_port = htons(9999);  /* daytime server */
    // if(0 >= inet_pton(AF_INET, argv[1], &servaddr.sin_addr)){
    //     fprintf(stderr, "inet_pton error for %s\n", argv[1]);
    //     exit(EXIT_FAILURE);
    // }

    if(0 > connect(sockfd, (SA*)&servaddr, sizeof(servaddr))){
        perror("connect error");
        exit(EXIT_FAILURE);
    }

    /* exercise 4.3, page 96 */
    // struct sockaddr_storage ss;
    // socklen_t len = sizeof(ss);
    // getsockname(sockfd, (SA*)&ss, &len);
    // char *addr_str = sock_ntop((SA*)&ss, len);
    // fputs(addr_str, stdout);
    // fputc('\n', stdout);

    /* standard */
    while(0 < (n = read(sockfd, recvline, MAXLINE))){
        recvline[n] = '\0';    /* null terminate */
        if(EOF == fputs(recvline, stdout)){   
            perror("fputs error");
            exit(EXIT_FAILURE);
        }
    }    
    if(0 > n){
        perror("read error");
    }
    /* exercise 1.4, exercise 1.5, page 26 */
    // int counter = 0;
    // while(0 < (n = read(sockfd, recvline, MAXLINE))){
    //     counter++; 
    //     recvline[n] = '\0';    /* null terminate */
    //     if(EOF == fputs(recvline, stdout)){   
    //         perror("fputs error");
    //         exit(EXIT_FAILURE);
    //     }
    // }
    // if(0 > n){
    //     perror("read error");
    // }
    // fprintf(stdout, "counter = %d\n", counter);

    exit(0);
}
