#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>

/* sec 3.7, fig 3-12, page 69 */
int inet_pton(int family, const char *strptr, void *addrptr){
    if(family == AF_INET){
        struct in_addr in_val;
        if(inet_aton(strptr, &in_val)){
            memcpy(addrptr, &in_val, sizeof(struct in_addr));
            return 1;
        }
        return 0;
    }
    errno = EAFNOSUPPORT;
    return -1;
}