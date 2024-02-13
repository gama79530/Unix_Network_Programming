#include "unp.h"

void Close(int fd){
    if(-1 == close(fd)){
        perror("close error");
        exit(1);
    }
}

void Write(int fd, void *ptr, size_t nbytes){
    if(-1 == write(fd, ptr, nbytes)){
        perror("write error");
        exit(1);
    }
}

pid_t Fork(void){
    pid_t pid;
    if(-1 == (pid = fork())){
        perror("fork error");
        exit(1);
    }
    return pid;
}