#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

#ifndef	INET_ADDRSTRLEN
#define	INET_ADDRSTRLEN		16
#endif

typedef unsigned char u_char;

/* sec 3.7, fig 3-13, page 70 */
const char *inet_ntop(int family, const void *addrptr, char *strptr, size_t len){
    const u_char *p = (const u_char*) addrptr;

    if(AF_INET == family){
        char temp[INET_ADDRSTRLEN];
        snprintf(temp, sizeof(temp), "%d.%d.%d.%d", p[0], p[1], p[2], p[3]);
        if(len <= strlen(temp)){
            errno = ENOSPC;
            return NULL;
        }
        strcpy(strptr, temp);
        return strptr;
    }
    errno = EAFNOSUPPORT;
    return NULL;
}