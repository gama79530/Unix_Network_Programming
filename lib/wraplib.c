#include	"unp.h"

const char *Inet_ntop(int family, const void *addrptr, char *strptr, size_t len){
    const char	*ptr;

    if(strptr == NULL){
        perror("NULL 3rd argument to inet_ntop");
        exit(0);
    }

    if(NULL == (ptr = inet_ntop(family, addrptr, strptr, len))){
        perror("inet_ntop error");
        exit(0);
    }
    return ptr;
}
