#include "unp.h"
#include <time.h>

/* sec 1.5, fig 1-9, page 13 */
int main(int argc, char **argv){
    int	listenfd = -1, connfd = -1;
    struct sockaddr_in servaddr;
    char buff[MAXLINE];
    time_t ticks;

    listenfd = Socket(AF_INET, SOCK_STREAM, 0);

    /* standard */
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(13);    /* daytime server */
    /* exercise 1.5, page 26 */
    // memset(&servaddr, 0, sizeof(servaddr));
    // servaddr.sin_family = AF_INET;
    // servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    // servaddr.sin_port = htons(9999);

    Bind(listenfd, (SA *)&servaddr, sizeof(servaddr));

    Listen(listenfd, LISTENQ);
    
    while(1){
        connfd = Accept(listenfd, (SA *) NULL, NULL);

        /* standard */
        ticks = time(NULL);
        snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
        Write(connfd, buff, strlen(buff));
        /* exercise 1.5, page 26 */
        // for(int i = 0; i < 10; i++){
        //     ticks = time(NULL);
        //     snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
        //     Write(connfd, buff, strlen(buff));
        // }

        Close(connfd);
    }
}
