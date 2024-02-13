#include "unp.h"

const char *Inet_ntop(int family, const void *addrptr, char *strptr, size_t len){
    const char *ptr = NULL;
    if(strptr == NULL){
        perror("NULL 3rd argument to inet_ntop");
        return ptr;
    }
    if(NULL == (ptr = inet_ntop(family, addrptr, strptr, len))){
        perror("inet_ntop error");
        return ptr;
    }
    return ptr;
}

void Inet_pton(int family, const char *strptr, void *addrptr){
    int n;
    char buffer[MAXLINE];

    if(0 > (n = inet_pton(family, strptr, addrptr))){
        snprintf(buffer, MAXLINE, "inet_pton error for %s", strptr);
        perror(buffer);
        exit(EXIT_FAILURE);
    }else if(0 == n){
        fprintf(stderr, "inet_pton error for %s\n", strptr);
        exit(EXIT_FAILURE);
    }
}
