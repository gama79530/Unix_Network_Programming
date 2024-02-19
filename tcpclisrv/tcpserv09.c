#include "unp.h"

int main(int argc, char **argv){
    int	listenfd, connfd;
    pid_t childpid;
    socklen_t clilen;
    struct sockaddr_in cliaddr, servaddr;
    void sig_chld(int);

    listenfd = Socket(AF_INET, SOCK_STREAM, 0);

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);

    Bind(listenfd, (SA*)&servaddr, sizeof(servaddr));

    Listen(listenfd, LISTENQ);

    Signal(SIGCHLD, sig_chld);  /* must call waitpid() */

    while(1){
        clilen = sizeof(cliaddr);
        if(0 > (connfd = accept(listenfd, (SA*)&cliaddr, &clilen))){
            if(EINTR == errno){
                continue;
            }
            perror("accept error");
            exit(EXIT_FAILURE);
        }

        if(0 == (childpid = Fork())){  /* child process */
            Close(listenfd);    /* close listening socket */
            str_echo(connfd);   /* process the request */
            Close(connfd);
            exit(0);
        }
        Close(connfd);  /* parent closes connected socket */
    }

    Close(listenfd);
}
