#include "unp.h"

/* sec 5.4, fig 5-3, page 99 */
void str_echo(int sockfd){
    ssize_t	n;
    char buf[MAXLINE];
again:
    while(0 < (n = read(sockfd, buf, MAXLINE))){
        Writen(sockfd, buf, n);
    }

    if (0 > n && EINTR == errno){
        goto again;
    }else if (0 > n){
        perror("str_echo: read error");
        exit(1);
    }
}
