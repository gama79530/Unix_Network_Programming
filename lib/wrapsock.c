#include	"unp.h"

/* sec 1.4, fig 1-7, page 11vscode-remote://wsl%2Bubuntu-22.04/home/rein/workspace/Unix-Network-Programming/lib/wrappthread.c */
int Socket(int family, int type, int protocol){
    int n = -1;

    if(0 > (n = socket(family, type, protocol))){
        perror("socker error");
        exit(1);
    }

    return n;
}

void Bind(int fd, const SA *sa, socklen_t salen){
    if(0 > bind(fd, sa, salen)){
        perror("bind error");
        exit(1);
    }
}

/* sec 4.5, fig 4-9, page 86 */
void Listen(int fd, int backlog){
    char *ptr;
    
    if(NULL != (ptr = getenv("LISTENQ"))){
        backlog = atoi(ptr);
    }

    if(0 > listen(fd, backlog)){
        perror("listen error");
        exit(1);
    }
}

int Accept(int fd, struct sockaddr *sa, socklen_t *salenptr){
    int n = 0;
again:
    if(0 > (n = accept(fd, sa, salenptr))){
    #ifdef	EPROTO
        if (errno == EPROTO || errno == ECONNABORTED){
    #else
        if (errno == ECONNABORTED){
    #endif
            goto again;
        }else{
            perror("accept error");
            exit(1);
        }
    }

    return n;
}