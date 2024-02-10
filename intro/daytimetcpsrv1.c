#include "unp.h"
#include <time.h>

/* sec 4.6, fig 4-11, page 89 */
int main(int argc, char **argv){
    int listenfd, connfd;
    socklen_t len;
    struct sockaddr_in servaddr, cliaddr;
    char buff[MAXLINE];
    time_t ticks;

    listenfd = Socket(AF_INET, SOCK_STREAM, 0);

    /* standard */
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(13);  /* daytime server */
    /* exercise 4.4, exercise 4.5, page 96 */
    // memset(&servaddr, 0, sizeof(servaddr));
    // servaddr.sin_family = AF_INET;
    // servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    // servaddr.sin_port = htons(9999);    /* daytime server */

    // exercise 4.5, page 96: comment Bind(listenfd, (SA*)&servaddr, sizeof(servaddr));
    Bind(listenfd, (SA*)&servaddr, sizeof(servaddr));

    // exercise 4.4, page 96: comment Listen(listenfd, LISTENQ);
    Listen(listenfd, LISTENQ);

    while(1){
        len = sizeof(cliaddr);
        connfd = Accept(listenfd, (SA*)&cliaddr, &len);
        printf("connection from %s, port %d\n", Inet_ntop(AF_INET, &cliaddr.sin_addr, buff, sizeof(buff)), ntohs(cliaddr.sin_port));

        ticks = time(NULL);
        snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
        Write(connfd, buff, strlen(buff));

        Close(connfd);
    }
}
