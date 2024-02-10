#include	"unp.h"

/* sec 3.9, fig 3-16, page 73 */
ssize_t writen(int fd, const void *vptr, size_t n){
    size_t nleft;
    ssize_t nwritten;
    const char *ptr;

    ptr = vptr;
    nleft = n;
    while(nleft > 0){
        if(0 >= (nwritten = write(fd, ptr, nleft))){
            if (nwritten < 0 && errno == EINTR){
                nwritten = 0;   /* and call write() again */
            }else{
                return -1;  /* error */
            }
        }

        nleft -= nwritten;
        ptr   += nwritten;
    }
    return n;
}
