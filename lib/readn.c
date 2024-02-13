#include "unp.h"

/* sec 3.9, fig 3-15, page 73 */
ssize_t readn(int fd, void *vptr, size_t n){
    size_t nleft;
    ssize_t nread;
    char *ptr;

    ptr = vptr;
    nleft = n;
    while(nleft > 0){
        if(0 > (nread = read(fd, ptr, nleft))){
            if(errno == EINTR){
                nread = 0;  /* and call read() again */
            }else{
                return -1;  /* error */
            }
        }else if(nread == 0){
            break;  /* EOF */
        }

        nleft -= nread;
        ptr   += nread;
    }
    return n - nleft;   /* return >= 0 */
}