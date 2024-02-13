#include "unp.h"

/* sec 5.2, fig 5-2, page 98 */
int main(int argc, char **argv){
    int listenfd, connfd;
    pid_t childpid;
    socklen_t clilen;
    struct sockaddr_in cliaddr, servaddr;

    listenfd = Socket(AF_INET, SOCK_STREAM, 0);

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);

    Bind(listenfd, (SA*)&servaddr, sizeof(servaddr));

    Listen(listenfd, LISTENQ);

    while(1){
        clilen = sizeof(cliaddr);
        connfd = Accept(listenfd, (SA*)&cliaddr, &clilen);

        if(0 == (childpid = Fork())){   /* child process */
            Close(listenfd);    /* close listening socket */
            str_echo(connfd);   /* process the request */
            Close(connfd);
            exit(0); /* Become a zombie process since child process does not signal parent process. */
        }
        Close(connfd);  /* parent closes connected socket */
    }

    Close(listenfd);    /* close listening socket */
    exit(0);
}
